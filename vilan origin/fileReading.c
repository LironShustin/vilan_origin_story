#include <stdio.h>
#include <string.h>

void pull_line_from_file(const char* filename, int line_number, char* text_from_line, size_t text_from_line_size) {
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


