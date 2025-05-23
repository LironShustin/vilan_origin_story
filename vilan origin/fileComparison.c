#include "fileComparison.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void compare_structs(const char* file1, int n, const char* file2, int match_lines[10], int* match_count) {
    FILE* fp1 = NULL;
    FILE* fp2 = NULL;
    char line[MAX_LINE_LENGTH];
    *match_count = 0; // Initialize match count
    // Open the first file for reading
    if (fopen_s(&fp1, file1, "r") != 0 || fp1 == NULL) {
        printf("Error opening file: %s\n", file1);
        return;
    }
    // Open the second file for reading
    if (fopen_s(&fp2, file2, "r") != 0 || fp2 == NULL) {
        printf("Error opening file: %s\n", file2);
        fclose(fp1);
        return;
    }
    // Skip first 3 lines in file2 (they are not used for comparison)
    for (int i = 0; i < 3; ++i) {
        fgets(line, MAX_LINE_LENGTH, fp2);
    }
    // Read n lines from file2 for comparison
    char** target_values = (char**)malloc(n * sizeof(char*)); // char** = pointer to an array of strings, (char**) typecast for the malloc result (used for clarfication)
    for (int i = 0; i < n; ++i) {
        if (fgets(line, MAX_LINE_LENGTH, fp2) == NULL) {
            printf("Error reading struct from %s\n", file2);
            fclose(fp1);
            fclose(fp2);
            free(target_values);
            return;
        }
        line[strcspn(line, "\r\n")] = 0; // Remove newline characters
        target_values[i] = _strdup(line); // Duplicate and store each line
    }
    fclose(fp2);
    int line_number = 1; // Keeps track of current line number in file1
    while (1) {
        char** current_struct = (char**)malloc(n * sizeof(char*));
        if (current_struct == NULL) { // Check if memory allocation failed
            printf("Error: Memory allocation for current_struct failed.\n");
            fclose(fp1);
            for (int j = 0; j < n; ++j) {
                free(target_values[j]);
            }
            free(target_values);
            return;
        }
        int i;
        int struct_start_line = line_number; // Save the starting line of this struct
        // Read n + 2 lines per struct from file1
        for (i = 0; i < n + 2; ++i) {
            if (fgets(line, MAX_LINE_LENGTH, fp1) == NULL) {
                break; // Reached end of file or incomplete struct
            }
            line[strcspn(line, "\r\n")] = 0; // Remove newline characters
            if (i < n) {
                current_struct[i] = _strdup(line); // Only first n lines used
                if (current_struct[i] == NULL) { // Check if _strdup failed
                    printf("Error: Memory allocation for current_struct[%d] failed.\n", i);
                    for (int j = 0; j < i; ++j) {
                        free(current_struct[j]);
                    }
                    free(current_struct);
                    fclose(fp1);
                    for (int j = 0; j < n; ++j) {
                        free(target_values[j]);
                    }
                    free(target_values);
                    return;
                }
            }
            ++line_number;
        }
        // If not enough lines read, exit loop
        if (i < n + 2) {
            for (int j = 0; j < i && j < n; ++j) {
                free(current_struct[j]);
            }
            free(current_struct);
            break;
        }
        int equal = 1;
        for (int j = 0; j < n; ++j) {
            if (strcmp(current_struct[j], target_values[j]) != 0) {
                equal = 0;
                break;
            }
        }
        if (equal && *match_count < 100) {
            match_lines[*match_count] = struct_start_line; // saves the start lines of all found matches
            (*match_count)++;
        }
        for (int j = 0; j < n; ++j) {
            free(current_struct[j]);
        }
        free(current_struct);
    }
    for (int i = 0; i < n; ++i) {
        free(target_values[i]);
    }
    free(target_values);
    fclose(fp1);
}
