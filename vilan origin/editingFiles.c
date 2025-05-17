#include "editingFiles.h"

void append_to_next_empty_line(const char* filename, const char* text) {
    strcat_s(filename, sizeof(filename) + 10, ".txt");
    FILE* file = fopen(filename, "a+");
    if (!file) {
        perror("Error opening file");
        return;
    }
    // Move to the start of the file to check for an existing empty line
    fseek(file, 0, SEEK_SET);
    char line[1024];
    long empty_line_pos = -1;
    while (fgets(line, sizeof(line), file)) {
        if (strlen(line) == 1 && line[0] == '\n') {
            empty_line_pos = ftell(file) - 1;
            break;
        }
    }
    // Move to the empty line position if found
    if (empty_line_pos != -1) {
        fseek(file, empty_line_pos, SEEK_SET);
    }
    else {
        // If no empty line was found, move to the end to append
        fseek(file, 0, SEEK_END);
        fprintf(file, "\n");
    }
    // Write the new text
    fprintf(file, "%s\n", text);
    fclose(file);
    //printf("Text appended successfully.\n");
}