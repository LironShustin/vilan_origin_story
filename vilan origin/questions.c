#include "questions.h"
#include "editingFiles.h"

void genre(bool realistic, char story_file_name[260]) {
	int choice = 0;
	char genre[30];

	if (realistic) {
		while (choice == 0) {
			printf("What genre is your story?\n");
			printf("1) Drama \n2) Comedy\n\n");
			scanf_s(" %d", &choice);
			if (choice == 1) {
				strcpy(genre, "Drama");
			}
			else if (choice == 2) {
				strcpy(genre, "Comedy");
			}
			else {
				printf("invalid input try again...");
			}
		}
	}
	else {
		while (choice == 0) {
			printf("What genre is your story?\n");
			printf("1) Thriller \n2) Fantasy \n3) Science fiction \n");
			scanf_s(" %d", &choice);
			if (choice == 1) {
				strcpy(genre, "Thriller");
			}
			else if (choice == 2) {
				strcpy(genre, "Fantasy");
			}
			else if (choice == 3) {
				strcpy(genre, "Science fiction");
			}
			else {
				printf("invalid input try again...");
			}
		}
	}
	append_to_next_empty_line(&story_file_name, genre);
}