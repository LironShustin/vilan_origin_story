#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileSaving.h"
#include "questions.h"
#include "editingFiles.h"
#include "Structs&Enums.h"
#include "fileReading.h"

int main() {
    char answers_file[260];
    BOOL realistic = True;
    create_answers_file(answers_file);
    is_realistic(&realistic, answers_file);
    genre(realistic, answers_file);
	clear_console();

	if (realistic) {// drama and comedy have the same questions
        how_long_you_met(answers_file);
		clear_console();
        first_meeting_place(answers_file);
        clear_console();
    }
	else {
        char genre[30] = { 0 };
        int pull_line = 3;
		size_t genre_size = sizeof(genre);
		pull_line_from_file(answers_file,pull_line, genre, genre_size);
        if (strcmp(genre, "Thriller") == 0) {
            thriller_meeting_status(answers_file);
            char status_answer[10] = { 0 };
            pull_line_from_file(answers_file, 0, status_answer, sizeof(status_answer));
            if (strcmp(status_answer, "yes") == 0) {
                thriller_meeting_place(answers_file);
            }
            else if (strcmp(status_answer, "no") == 0) {
                thriller_hero_duty(answers_file);
            }
        }

        else if (strcmp(genre, "Science fiction") == 0 || strcmp(genre, "Fantasy") == 0) {
            sci_fi_or_fantasy_meeting_place(answers_file);
        }
    }
    return 0;
}