#include "questions.h"
#include "editingFiles.h"
#include "design.h"


void genre(bool realistic, char* story_file_name[260]) {
	int choice = 0;
	char genre[30];

	if (realistic) {
		while (choice == 0) {
			print_colored("What genre is your story?\n", YELLOW);
			print_colored("1) Drama \n2) Comedy\n\n", CYAN);
			scanf_s(" %d", &choice);
			if (choice == 1) {
				strcpy_s(genre, sizeof(genre), "Drama");

			}
			else if (choice == 2) {
				strcpy_s(genre, sizeof(genre), "Comedy");

			}
			else {
				print_colored("invalid input try again...", RED);
			}
		}
	}
	else {
		while (choice == 0) {
			print_colored("What genre is your story?\n", YELLOW);
			print_colored("1) Thriller \n2) Fantasy \n3) Science fiction \n", CYAN);
			scanf_s(" %d", &choice);
			if (choice == 1) {
				strcpy_s(genre, sizeof(genre), "Thriller");

			}
			else if (choice == 2) {
				strcpy_s(genre, sizeof(genre), "Fantasy");

			}
			else if (choice == 3) {
				strcpy_s(genre, sizeof(genre), "Science fiction");

			}
			else {
				print_colored("invalid input try again...", RED);
			}
		}
	}
<<<<<<< HEAD
	append_to_next_empty_line(story_file_name, genre);
}
=======
	append_to_next_empty_line(&story_file_name, genre);
}

void how_long_you_met(char story_file_name[260]) {
    char when_met[100] = { 0 };
    char genre[30] = { 0 };
    int choice = 0;
    while (choice < 1 || choice > 3) {
        print_colored("How long have you known each other?\n", YELLOW);
        print_colored("1) Just met\n2) Less than a year\n3) More than a year\n", CYAN);
        scanf_s("%d", &choice);
        if (choice < 1 || choice > 3) {
            print_colored("Invalid input, try again...\n", RED);
        }
    }
    switch (choice) {
    case 1:
        strcpy_s(when_met, sizeof(when_met), "Just met");
        break;
    case 2:
        strcpy_s(when_met, sizeof(when_met), "Less than a year");
        break;
    case 3:
        strcpy_s(when_met, sizeof(when_met), "More than a year");
        break;
    }
        append_to_next_empty_line(&story_file_name, when_met);
}
>>>>>>> QhowLongYouMet
