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
	append_to_next_empty_line(story_file_name, genre);
}