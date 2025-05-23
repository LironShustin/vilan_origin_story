#include <stdio.h>
#include <string.h>
#include "Structs&Enums.h"

#define MAX_LINE_LEN 1024

void pull_line_from_file(const char* filename, int line_number, char* text_from_line, int text_from_line_size) {
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("Error opening file %s\n", filename);
		return;
	}
	int current_line = 1;
	while (fgets(text_from_line, text_from_line_size, file) != NULL) {
		if (current_line == line_number) {
			text_from_line[strcspn(text_from_line, "\n")] = '\0'; // Remove newline character
			break;
		}
		current_line++;
	}
}

int write_lines_to_struct(const char* filename, int start_line, int N, Output_Vilain_Struct* data) { // N is the amount of lines we want to write to the struct from the db
    N = N + 2; // we want to print question answers and the 2 assitional antagonist and plot line fields
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return -1;
    }
    char buffer[MAX_LINE_LEN];
    int current_line = 1;
    int lines_read = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        if (current_line >= start_line) {
            // Trim newline
            buffer[strcspn(buffer, "\n")] = '\0';
            // Fill only line1 to lineN
            switch (lines_read) {
            case 0: strncpy_s(data->line1, MAX_LINE_LEN, buffer, MAX_LINE_LEN - 1); break;
            case 1: strncpy_s(data->line2, MAX_LINE_LEN, buffer, MAX_LINE_LEN - 1); break;
            case 2: strncpy_s(data->line3, MAX_LINE_LEN, buffer, MAX_LINE_LEN - 1); break;
            case 3: strncpy_s(data->line4, MAX_LINE_LEN, buffer, MAX_LINE_LEN - 1); break;
            case 4: strncpy_s(data->line5, MAX_LINE_LEN, buffer, MAX_LINE_LEN - 1); break;
            default:
                printf("Warning: Tried to read more than N lines into struct.\n");
                break;
            }
            lines_read++;
            if (lines_read >= N)
                break;
        }
        current_line++;
    }
    fclose(file);
    return lines_read == N ? 0 : -2; // -2 = not enough lines read
}

