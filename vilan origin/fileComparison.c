#include "fileComparison.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int compare_structs(const char* file1, int n, const char* file2, int match_lines[10]) {
    FILE* fp1 = NULL;
    FILE* fp2 = NULL;
    char line[MAX_LINE_LENGTH];
    if (fopen_s(&fp1, file1, "r") != 0 || fp1 == NULL) {
        printf("Error opening file: %s\n", file1);
        return -1;
    }
    if (fopen_s(&fp2, file2, "r") != 0 || fp2 == NULL) {
        printf("Error opening file: %s\n", file2);
        fclose(fp1);
        return -1;
    }
    // Skip first 3 lines in file2
    for (int i = 0; i < 3; ++i) {
        fgets(line, MAX_LINE_LENGTH, fp2);
    }
    // Read n lines from file2 for comparison
    char** target_values = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; ++i) {
        if (fgets(line, MAX_LINE_LENGTH, fp2) == NULL) {
            printf("Error reading struct from %s\n", file2);
            fclose(fp1);
            fclose(fp2);
            free(target_values);
            return -1;
        }
        line[strcspn(line, "\r\n")] = 0;
        target_values[i] = _strdup(line);
    }
    fclose(fp2);
    int line_number = 1;
    int match_count = 0;
    while (1) {
        char** current_struct = (char**)malloc(n * sizeof(char*));
        int i;
        int struct_start_line = line_number;
        // Read n + 2 lines per struct
        for (i = 0; i < n + 2; ++i) {
            if (fgets(line, MAX_LINE_LENGTH, fp1) == NULL) {
                break; // End of file or incomplete struct
            }
            line[strcspn(line, "\r\n")] = 0;
            if (i < n) {
                current_struct[i] = _strdup(line); // Only first n lines used for comparison
            }
            ++line_number;
        }
        if (i < n + 2) {
            // Incomplete struct
            for (int j = 0; j < i && j < n; ++j) {
                free(current_struct[j]);
            }
            free(current_struct);
            break;
        }
        // Compare to target struct
        int equal = 1;
        for (int j = 0; j < n; ++j) {
            if (strcmp(current_struct[j], target_values[j]) != 0) {
                equal = 0;
                break;
            }
        }
        if (equal && match_count < 10) {
            match_lines[match_count++] = struct_start_line;
        }
        for (int j = 0; j < n; ++j) {
            free(current_struct[j]);
        }
        free(current_struct);
    }
    // Clean up
    for (int i = 0; i < n; ++i) {
        free(target_values[i]);
    }
    free(target_values);
    fclose(fp1);
    return match_count;
}
