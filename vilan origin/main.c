//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include "fileSaving.h"
//#include "questions.h"
//#include "editingFiles.h"
//
//int main() { 
//	char answers_file[260];
//	bool realistic = true;
//	create_answers_file(&answers_file);
//	is_realistic(&realistic, &answers_file);
//	genre(realistic, &answers_file);
//	how_long_you_met(&answers_file);
//	first_meeting_place(&answers_file);
//}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "fileSaving.h"
#include "questions.h"
#include "editingFiles.h"

int main() {
    char answers_file[260];
    bool realistic = true;
    char genre_selected[30] = "";

    create_answers_file(answers_file);
    is_realistic(&realistic, answers_file);
    genre(realistic, answers_file, genre_selected);

    if (realistic) {
        how_long_you_met(answers_file);
        first_meeting_place(answers_file);
    }
    else {
        if (strcmp(genre_selected, "Thriller") == 0) {
            thriller_meeting_status(answers_file);
        }
        else if (strcmp(genre_selected, "Fantasy") == 0 || strcmp(genre_selected, "Science fiction") == 0) {
            sci_fi_or_fantasy_meeting_place(answers_file);
        }
    }

    return 0;
}


