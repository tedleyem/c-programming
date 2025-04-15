#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

#define MAX_URL_LENGTH 512
#define MAX_HTML_LENGTH 10240

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

// A function to parse the HTML content for the head-to-head results
void parse_html(const char *html_content) {
    xmlDocPtr doc;
    xmlNodePtr root, cur_node;

    // Parse the HTML content as XML
    doc = xmlReadMemory(html_content, strlen(html_content), "noname.xml", NULL, 0);
    if (doc == NULL) {
        fprintf(stderr, "Failed to parse HTML content.\n");
        return;
    }

    // Get the root element
    root = xmlDocGetRootElement(doc);

    // Loop through nodes to find the head-to-head results table (you'll need to adjust this based on the actual structure of the page)
    cur_node = root;
    while (cur_node != NULL) {
        if (cur_node->type == XML_ELEMENT_NODE && strcmp((const char *)cur_node->name, "table") == 0) {
            // Look for specific classes or attributes to identify the table
            xmlAttr *attr = cur_node->properties;
            while (attr) {
                if (strcmp((const char *)attr->name, "class") == 0 && strcmp((const char *)attr->children->content, "head-to-head-results") == 0) {
                    // Print out the rows from the table (this is just an example, you need to adjust it based on the real structure)
                    xmlNodePtr row_node = cur_node->children;
                    while (row_node) {
                        if (row_node->type == XML_ELEMENT_NODE && strcmp((const char *)row_node->name, "tr") == 0) {
                            xmlNodePtr col_node = row_node->children;
                            int col_count = 0;
                            char date[256], score[256], result[256];

                            while (col_node) {
                                if (col_node->type == XML_ELEMENT_NODE && strcmp((const char *)col_node->name, "td") == 0) {
                                    if (col_count == 0) {
                                        strncpy(date, (const char *)col_node->children->content, sizeof(date) - 1);
                                    } else if (col_count == 1) {
                                        strncpy(score, (const char *)col_node->children->content, sizeof(score) - 1);
                                    } else if (col_count == 2) {
                                        strncpy(result, (const char *)col_node->children->content, sizeof(result) - 1);
                                    }
                                    col_count++;
                                }
                                col_node = col_node->next;
                            }

                            printf("%-20s %-15s %-10s\n", date, score, result);
                        }
                        row_node = row_node->next;
                    }
                }
                attr = attr->next;
            }
        }
        cur_node = cur_node->next;
    }

    // Free the XML document
    xmlFreeDoc(doc);
}

// Argument parsing to allow choosing NBA teams
void parse_arguments(int argc, char *argv[], char *team1, char *team2) {
    const char *available_teams[] = {
        "Lakers", "Warriors", "Bucks", "Celtics", "Heat", "Nets", "Suns", "Raptors", "Knicks", "Mavericks",
        "76ers", "Bulls", "Nuggets", "Kings", "Pelicans", "Clippers", "Spurs", "Hornets", "Pacers", "Magic"
    };

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <team1> <team2>\n", argv[0]);
        exit(1);
    }

    // Check if the teams are valid
    int valid_team1 = 0, valid_team2 = 0;
    for (int i = 0; i < sizeof(available_teams) / sizeof(available_teams[0]); i++) {
        if (strcmp(argv[1], available_teams[i]) == 0) {
            valid_team1 = 1;
        }
        if (strcmp(argv[2], available_teams[i]) == 0) {
            valid_team2 = 1;
        }
    }

    if (!valid_team1 || !valid_team2) {
        fprintf(stderr, "Invalid team name. Available teams are:\n");
        for (int i = 0; i < sizeof(available_teams) / sizeof(available_teams[0]); i++) {
            printf("%s\n", available_teams[i]);
        }
        exit(1);
    }

    strncpy(team1, argv[1], 50);
    strncpy(team2, argv[2], 50);
}

int main(int argc, char *argv[]) {
    char team1[50], team2[50];
    char url[MAX_URL_LENGTH];
    char html_content[MAX_HTML_LENGTH] = "";

    // Parse the arguments
    parse_arguments(argc, argv, team1, team2);

    // Construct the URL for the head-to-head page
    snprintf(url, sizeof(url), "https://landonbasketball.com/head-to-head/%s-vs-%s", team1, team2);

    // Fetch the HTML content
    if (fetch_html(url, html_content) != 0) {
        fprintf(stderr, "Error fetching HTML content.\n");
        return 1;
    }

    // Parse the HTML and display the head-to-head results
    printf("Head-to-Head Results: %s vs %s\n", team1, team2);
    printf("%-20s %-15s %-10s\n", "Date", "Score", "Result");
    parse_html(html_content);

    return 0;
}
