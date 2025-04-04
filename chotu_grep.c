#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 512

/**
 * @brief Searches for the pattern in the given file.
 *
 * @param filename Name of the file.
 * @param pattern Pattern to search for.
 * @return 0 on success, non-zero on error.
 */
int search(char *filename, char *pattern);

/**
 * @brief Checks if the given string is empty or only contains whitespace.
 *
 * @param str The string to check.
 * @return 2 if the string is empty/whitespace, 0 otherwise.
 */
int is_empty(char *str);

int main(int argc, char *argv[]){
    if (argc != 3){
        printf("Usage : ./chotu_grep <pattern> <filename>\n");
        return 1;
    }
    char *pattern = argv[1];
    char *filename = argv[2];

    if (is_empty(pattern) || is_empty(filename)){
        printf("Empty filename or pattern\n");
        return 2;
    }
    search(filename, pattern);

    return 0;
}

/// @brief Searches for the pattern in the given file
/// @param filename - Name of the file
/// @param pattern - Pattern you want to search
/// @return 0 on success, non-zero on error 
int search(char *filename, char *pattern){
    char line[MAX_LEN];
    int i = 0;
    int found = 0;

    FILE *fp = fopen(filename, "r");

    if (!fp){
        perror("Error opening file");
        return 2;
    }

    while (fgets(line, sizeof(line), fp) != NULL){
        ++i;
        if (strstr(line, pattern))
        {
            printf("%d. %s", i, line);
            found++;
        }
    }
    if (!found){
        printf("%s not found in %s\n", pattern, filename);
    }

    fclose(fp);
    return 0;
}

/// @brief Check if string is empty or only has whitespaces
/// @param str - String you want to check
/// @return 0 on success, non-zero on error
int is_empty(char *str){
    if(str == NULL) return 2;

    while(*str){
        if(!isspace((unsigned char)*str)) return 0;
        str++;
    }
    return 2;
}