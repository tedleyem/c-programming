#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <htmlcxx/html/ParserDom.h>
#include <htmlcxx/html/Node.h>

#define MAX_URL_LENGTH 256

// A function to handle the data fetched by libcurl
size_t write_callback(void *ptr, size_t size, size_t nmemb, void *data) {
    strcat(data, ptr);
    return size * nmemb;
}

// A function to fetch HTML content from the URL
int fetch_html(const char *url, char *html_content) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, html_content);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            return -1;
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}

// A function to parse HTML content for head-to-head results
void parse_html(const char *html_content) {
    htmlcxx::ParserDom parser;
    htmlcxx::DOM::Node root = parser.parseTree(html_content);

    // This is a simplified example and assumes a specific structure for the table
    for (auto node = root.begin(); node != root.end(); ++node) {
        if (node->isTag() && node->tagName() == "table" && node->hasAttribute("class", "head-to-head-results")) {
            // Find and parse the rows in the table
            for (auto tr_node = node->begin(); tr_node != node->end(); ++tr_node) {
                if (tr_node->isTag() && tr_node->tagName() == "tr") {
                    // Find the columns in each row
                    std::string date, score, result;
                    for (auto td_node = tr_node->begin(); td_node != tr_node->end(); ++td_node) {
                        if (td_node->isTag() && td_node->tagName() == "td") {
                            std::string content = td_node->text();
                            if (date.empty()) {
                                date = content;
                            } else if (score.empty()) {
                                score = content;
                            } else {
                                result = content;
                                printf("%-20s %-10s %-10s\n", date.c_str(), score.c_str(), result.c_str());
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <team1> <team2>\n", argv[0]);
        return 1;
    }

    char team1[50], team2[50];
    strncpy(team1, argv[1], sizeof(team1) - 1);
    strncpy(team2, argv[2], sizeof(team2) - 1);

    // Construct the URL for the head-to-head page
    char url[MAX_URL_LENGTH];
    snprintf(url, sizeof(url), "https://landonbasketball.com/head-to-head/%s-vs-%s", team1, team2);

    char html_content[10000] = "";  // Assuming the page won't exceed 10KB

    // Fetch the HTML content
    if (fetch_html(url, html_content) != 0) {
        fprintf(stderr, "Error fetching the HTML content.\n");
        return 1;
    }

    // Parse and print the head-to-head results
    printf("Head-to-Head Results: %s vs %s\n", team1, team2);
    printf("%-20s %-10s %-10s\n", "Date", "Score", "Result");
    parse_html(html_content);

    return 0;
}
