#ifndef HW11
#define HW11

#define MAX_TITLES 100
#define MAX_TITLE_LENGTH 256

// External declaration of global variables
extern char titles[MAX_TITLES][MAX_TITLE_LENGTH];
extern int title_count;

// Function declarations
char* read_xml_file(const char* filename);
void find_titles_recursive(const char *xml);
void sort_titles_alphabetically();
void print_titles();

#endif