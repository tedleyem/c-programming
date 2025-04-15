#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Simple hash function to generate a unique hash for the long URL
unsigned long hash_url(const char *url) {
    unsigned long hash = 5381;
    int c;

    while ((c = *url++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash;
}

// Simple struct to store long URL and short URL pair
typedef struct {
    char long_url[2048];
    char short_url[10];
} URLMapping;

// In-memory "database" of shortened URLs
#define MAX_URLS 100
URLMapping url_database[MAX_URLS];
int url_count = 0;

// Generate a short URL and store the mapping
void shorten_url(const char *long_url) {
    if (url_count >= MAX_URLS) {
        printf("Error: URL database is full!\n");
        return;
    }

    unsigned long hash_value = hash_url(long_url);
    unsigned int short_url_hash = hash_value % 1000000;  // Keep it as a 6-digit number

    // Create the short URL (simplified)
    snprintf(url_database[url_count].short_url, sizeof(url_database[url_count].short_url), "short.ly/%06u", short_url_hash);
    strncpy(url_database[url_count].long_url, long_url, sizeof(url_database[url_count].long_url) - 1);
    
    printf("Shortened URL: %s\n", url_database[url_count].short_url);
    url_count++;
}

// Expand a short URL back to the long URL
void expand_url(const char *short_url) {
    for (int i = 0; i < url_count; i++) {
        if (strcmp(url_database[i].short_url, short_url) == 0) {
            printf("Original URL: %s\n", url_database[i].long_url);
            return;
        }
    }
    printf("Error: Short URL not found!\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <command> <url>\n", argv[0]);
        printf("Commands:\n");
        printf("  shorten <long_url>  : Shorten a URL\n");
        printf("  expand <short_url>  : Expand a short URL\n");
        return 1;
    }

    const char *command = argv[1];
    const char *url = argv[2];

    if (strcmp(command, "shorten") == 0) {
        shorten_url(url);
    } else if (strcmp(command, "expand") == 0) {
        expand_url(url);
    } else {
        printf("Unknown command: %s\n", command);
        return 1;
    }

    return 0;
}
