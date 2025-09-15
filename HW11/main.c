#include "hw11.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        fprintf(stderr, "Example: %s input/input1.txt\n", argv[0]);
        return 1;
    }
    
    // Read XML from file
    char* xml_data = read_xml_file(argv[1]);
    if (!xml_data) {
        return 1; // File error already printed by read_xml_file
    }
    
    // Reset global variables in case this is not the first run
    title_count = 0;
    
    // Find all titles recursively
    find_titles_recursive(xml_data);
    
    if (title_count == 0) {
        printf("No book titles found in the XML data.\n");
        free(xml_data);
        return 0;
    }
    
    // Sort the titles alphabetically
    sort_titles_alphabetically();
    
    // Print sorted titles to stdout
    print_titles();
    
    // Clean up
    free(xml_data);
    return 0;
}