#include "hw11.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Global variables definition
char titles[MAX_TITLES][MAX_TITLE_LENGTH];
int title_count = 0;

char* read_xml_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        return NULL;
    }
    
    // Get file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    if (file_size <= 0) {
        fprintf(stderr, "Error: File '%s' is empty\n", filename);
        fclose(file);
        return NULL;
    }
    
    // Allocate buffer for file content
    char* buffer = malloc(file_size + 1);
    if (!buffer) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        fclose(file);
        return NULL;
    }
    
    // Read file content
    size_t bytes_read = fread(buffer, 1, file_size, file);
    if (bytes_read != file_size) {
        fprintf(stderr, "Error: Failed to read entire file\n");
        free(buffer);
        fclose(file);
        return NULL;
    }
    
    buffer[bytes_read] = '\0'; // Null-terminate the string
    
    fclose(file);
    return buffer;
}

// Recursive function to find and store book titles
void find_titles_recursive(const char *xml) {
    const char *title_start = strstr(xml, "<title>");
    if (!title_start) return;
    
    const char *title_end = strstr(title_start, "</title>");
    if (!title_end) return;
    
    // Extract title content
    const char *content_start = title_start + 7; // Skip "<title>"
    int title_length = title_end - content_start;
    
    // Store the title if we have space
    if (title_count < MAX_TITLES && title_length < MAX_TITLE_LENGTH - 1) {
        strncpy(titles[title_count], content_start, title_length);
        titles[title_count][title_length] = '\0';
        title_count++;
    }
    
    // Continue searching after this title
    find_titles_recursive(title_end + 8); // Skip "</title>"
}

// Comparison function for qsort
int compare_strings(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

// Sort titles alphabetically
void sort_titles_alphabetically() {
    qsort(titles, title_count, MAX_TITLE_LENGTH, compare_strings);
}

// Print all stored titles
void print_titles() {
    for (int i = 0; i < title_count; i++) {
        printf("%d. %s\n", i + 1, titles[i]);
    }
}