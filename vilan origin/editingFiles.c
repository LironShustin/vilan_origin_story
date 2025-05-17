#include "editingFiles.h"

void append_to_next_empty_line(const char* filename, const char* text) {
    //strcat_s(filename, sizeof(filename) + 10, ".txt");
    FILE* file = fopen(filename, "a+");
    if (!file) {
        perror("Error opening file");
        return;
    }
    fseek(file, 0, SEEK_END);
    fprintf(file, "%s\n", text);
    fclose(file);
}