Certainly! Writing a web scraper in C is a bit more involved than in Python, but it's still possible with the right libraries. For HTTP requests, `libcurl` is commonly used, and for parsing HTML, you can use `libxml2` or `htmlcxx`. I'll walk you through the C code that uses `libcurl` for web requests and `htmlcxx` for basic HTML parsing.

### Prerequisites:

1. **libcurl**: This library will help you make HTTP requests.
2. **htmlcxx**: A simple C++ library for parsing HTML, though it can be used in C with some effort.

To install these libraries:

```bash
sudo apt-get install libcurl4-openssl-dev
sudo apt-get install libhtmlcxx-dev
```

### C Code for Web Scraping:

```c
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
```

### Explanation:

1. **Fetching HTML Content**:
   - `fetch_html()` uses `libcurl` to fetch the HTML content of the head-to-head page for two NBA teams. The content is stored in a string (`html_content`).

2. **Parsing HTML Content**:
   - `parse_html()` uses the `htmlcxx` library to parse the HTML content. It searches for the table that contains the head-to-head results. You would need to adjust the parsing logic to match the actual structure of the HTML page from `landonbasketball.com`.
   - The function looks for a table with the class `head-to-head-results` (you can change this based on actual HTML structure).

3. **Displaying Results**:
   - It prints the results in a formatted table: Date, Score, and Result.

### Running the C Code:

1. Save the code in a file, for example `scraper.c`.
2. Compile the code with `libcurl` and `htmlcxx`:

```bash
gcc scraper.c -o scraper -lcurl -lhtmlcxx
```

3. Run the program, passing in two team names as arguments:

```bash
./scraper Lakers Warriors
```

### Expected Output:

If the scraping works and the page is structured correctly, you should see something like this:

```
Head-to-Head Results: Lakers vs Warriors
Date                 Score      Result    
2025-01-28           110-98     Lakers Win
2025-01-25           102-105    Warriors Win
...
```

### Important Notes:

1. **HTML Structure**: You’ll need to inspect the HTML structure of the `landonbasketball.com` website to tailor the `parse_html` function. It assumes the table has a class `head-to-head-results`, but this may vary.

2. **Error Handling**: This code handles basic errors such as failed HTTP requests or missing table elements. You can expand the error handling depending on your needs.

3. **Libraries**: Make sure to install `libcurl` and `htmlcxx`. If you prefer other libraries for HTML parsing, you can use `libxml2`, but that requires a different approach.

Let me know if you need further adjustments or help with something else!