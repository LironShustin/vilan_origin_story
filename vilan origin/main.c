#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fileSaving.h"
#include "questions.h"
#include "editingFiles.h"
#include "Structs&Enums.h"
#include "fileReading.h"
#include "fileComparison.h"

int main() {
    srand((unsigned int)time(NULL)); // Seed the RNG
    Output_Vilain_Struct test = { 0 };
    char answers_file[260];
    BOOL realistic = True;
    int match_lines[10] = { 0 };
    int match_count = 0;
    int n;
    int r;
    create_answers_file(answers_file);
    is_realistic(&realistic, answers_file);
    genre(realistic, answers_file);

	if (realistic) {// drama and comedy have the same questions
        how_long_you_met(answers_file);
        first_meeting_place(answers_file);
        n = 2; //in drama n=2
        compare_structs("drama_database.txt", n, answers_file, match_lines, &match_count);
        r = (rand() % match_count);
        write_lines_to_struct("drama_database.txt", match_lines[r], n, &test);
    }
	else {// unrealistic
        char genre[30] = { 0 };
        int pull_line = 3;
		int genre_size = sizeof(genre);
		pull_line_from_file(answers_file,pull_line, genre, genre_size);
        if (strcmp(genre, "Thriller") == 0) {
            thriller_meeting_status(answers_file);
        }
        else if (strcmp(genre, "Science fiction") == 0 || strcmp(genre, "Fantasy") == 0) {
            sci_fi_or_fantasy_meeting_place(answers_file);
        }
    }
    return 0;
}