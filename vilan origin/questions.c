#include "questions.h"
#include "editingFiles.h"
#include "design.h"
#include "Structs&Enums.h"


void is_realistic(BOOL* realistic, char* story_file_name) {
    char answer[10]; // buffer for input
    answer[0] = '0';
    while (answer[0] == '0') {
        print_colored("Is your story realistic? (y/n)\n", YELLOW);
        scanf_s("%9s", answer, (unsigned)_countof(answer));
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {} // clear input buffer

        if ((answer[0] == 'y' || answer[0] == 'Y') && answer[1] == '\0') {
            *realistic = True;
            append_to_next_empty_line(story_file_name, "Realistic");
        }
        else if ((answer[0] == 'n' || answer[0] == 'N') && answer[1] == '\0') {
            *realistic = False;
            append_to_next_empty_line(story_file_name, "Fictional");
        }
        else {
            print_colored("Invalid answer\n", RED);
            answer[0] = '0';
        }
    }
}
void genre(BOOL realistic, char* story_file_name) {
    int choice = 0;
    char genre[30];
    if (realistic) {
    	while (choice == 0) {
    		print_colored("\nWhat genre is your story?\n", YELLOW);
    		print_colored("1) Drama \n2) Comedy\n", CYAN);
    		scanf_s(" %d", &choice);
   			if (choice == 1) {
   				strcpy_s(genre, sizeof(genre), "Drama");
   			}
   			else if (choice == 2) {
    			strcpy_s(genre, sizeof(genre), "Comedy");
    		}
    		else {
    			print_colored("invalid input try again...", RED);
    			choice = 0; // Reset choice to allow for re-entry
   			}
   		}
   	}
   	else {
    	while (choice == 0) {
    		print_colored("\nWhat genre is your story?\n", YELLOW);
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

void how_long_you_met(char* story_file_name) {
    char when_met[100] = { 0 };
    int choice = 0;
    while (choice < 1 || choice > 3) {
        print_colored("\nWhen the story starts how long have your hero and vilain known each other?\n", YELLOW);
        print_colored("1) Just met\n2) Less than a year\n3) More than a year\n", CYAN);
        scanf_s("%d", &choice);
        if (choice < 1 || choice > 3) {
            print_colored("Invalid input, try again...\n", RED);
        }
    }
    switch (choice) {
    case 1:
        strcpy_s(when_met, sizeof(when_met), "just met");
        break;
    case 2:
        strcpy_s(when_met, sizeof(when_met), "less than a year");
        break;
    case 3:
        strcpy_s(when_met, sizeof(when_met), "more than a year");
        break;
    }
    append_to_next_empty_line(story_file_name, when_met);
}

void first_meeting_place(char* story_file_name) {
    char meeting_place[100] = { 0 };
    int choice = 0;
    while (choice < 1 || choice > 3) {
        print_colored("\nWhere did the hero and villain first meet?\n", YELLOW);
        print_colored("1) They are family related\n2) They studied together\n3) They worked together\n", CYAN);
        scanf_s("%d", &choice);
        if (choice < 1 || choice > 3) {
            print_colored("Invalid input, try again...\n", RED);
        }
    }
    switch (choice) {
    case 1:
        strcpy_s(meeting_place, sizeof(meeting_place), "family");
        break;
    case 2:
        strcpy_s(meeting_place, sizeof(meeting_place), "school");
        break;
    case 3:
        strcpy_s(meeting_place, sizeof(meeting_place), "work place");
        break;
    }
    append_to_next_empty_line(story_file_name, meeting_place);
}

void sci_fi_or_fantasy_meeting_place(char* story_file_name) {
    char place[100] = { 0 };
    int choice = 0;
    while (choice < 1 || choice > 3) {
        print_colored("\nWhere did the hero and villain meet first?\n", YELLOW);
        print_colored("1) Enemy captivity\n2) Battlefield\n3) Canteen\n", CYAN);
        scanf_s("%d", &choice);
        clear_console();
        if (choice < 1 || choice > 3) {
            print_colored("Invalid input, try again...\n", RED);
        }
    }
    switch (choice) {
    case 1:
        strcpy_s(place, sizeof(place), "Enemy captivity");
        break;
    case 2:
        strcpy_s(place, sizeof(place), "Battlefield");
        break;
    case 3:
        strcpy_s(place, sizeof(place), "Canteen");
        break;
    }
    append_to_next_empty_line(story_file_name, place);
}
void hero_villain_same_side(char* story_file_name) {
    char answer[100] = { 0 };
    int choice = 0;
    while (choice < 1 || choice > 2) {
        print_colored("\nWere the hero and the villain on the same side?\n", YELLOW);
        print_colored("1) Yes\n2) No\n", CYAN);
        scanf_s("%d", &choice);
        clear_console();
        if (choice < 1 || choice > 2) {
            print_colored("Invalid input, try again...\n", RED);
        }
    }
    if (choice == 1) {
        strcpy_s(answer, sizeof(answer), "Same side: Yes");
    }
    else {
        strcpy_s(answer, sizeof(answer), "Same side: No");
    }
    append_to_next_empty_line(story_file_name, answer);
    //how_long_since_meeting(story_file_name);
}

void how_long_since_meeting(char* story_file_name) {
    char answer[100] = { 0 };
    int choice = 0;
    while (choice < 1 || choice > 4) {
        print_colored("\nHow long has it been since then?\n", YELLOW);
        print_colored("1) Just met\n2) Less than a week\n3) More than a week\n4) More than a year\n", CYAN);
        scanf_s("%d", &choice);
        clear_console();
        if (choice < 1 || choice > 4) {
            print_colored("Invalid input, try again...\n", RED);
        }
    }
    switch (choice) {
    case 1:
        strcpy_s(answer, sizeof(answer), "Just met");
        break;
    case 2:
        strcpy_s(answer, sizeof(answer), "Less than a week");
        break;
    case 3:
        strcpy_s(answer, sizeof(answer), "More than a week");
        break;
    case 4:
        strcpy_s(answer, sizeof(answer), "More than a year");
        break;
    }
    append_to_next_empty_line(story_file_name, answer);
}


void thriller_meeting_status(char* story_file_name) {
    char answer[20] = { 0 };
    int choice = 0;
    while (choice < 1 || choice > 2) {
        print_colored("\nDid the hero and villain already meet each other?\n", YELLOW);
        print_colored("1) Yes\n2) No\n", CYAN);
        scanf_s("%d", &choice);
        clear_console();
        if (choice < 1 || choice > 2) {
            print_colored("Invalid input, try again...\n", RED);
        }
    }
    if (choice == 1) {
        strcpy_s(answer, sizeof(answer), "Yes");
    }
    else {
        strcpy_s(answer, sizeof(answer), "No");
    }
    append_to_next_empty_line(story_file_name, answer);
}

void thriller_meeting_place(char* story_file_name) {
    int choice = 0;
    while (choice < 1 || choice > 2) {
        print_colored("\nWhere?\n", YELLOW);
        print_colored("1) Canteen\n2) Investigation Office\n", CYAN);
        scanf_s("%d", &choice);
        clear_console();
        if (choice < 1 || choice > 2) {
            print_colored("Invalid input, try again...\n", RED);
        }
    }
    if (choice == 1) {
        append_to_next_empty_line(story_file_name,"Canteen");
    }
    else if (choice == 2){
        append_to_next_empty_line(story_file_name,"Investigation Office");
    }
}

void thriller_hero_duty(char* story_file_name) {
    int choice = 0;
    while (choice < 1 || choice > 4) {
        print_colored("\nWhat is the duty of the hero\n", YELLOW);
        print_colored("1) Investigator\n2) Murderer\n3) Victim\n4) Uninvolved\n", CYAN);
        scanf_s("%d", &choice);
        clear_console();
        if (choice < 1 || choice > 4) {
            print_colored("Invalid input, try again...\n", RED);
        }
    }
    switch (choice) {
    case 1: append_to_next_empty_line(story_file_name, "Investigator"); break;
    case 2: append_to_next_empty_line(story_file_name, "Murderer"); break;
    case 3: append_to_next_empty_line(story_file_name, "Victim"); break;
    }
}

void was_one_crew_member(char* story_file_name) {
    int choice = 0;
    while (choice < 1 || choice > 2) {
        print_colored("\nWas one of them a crew member?\n", YELLOW);
        print_colored("1) Yes\n2) No\n", CYAN);
        scanf_s("%d", &choice);
        if (choice < 1 || choice > 2) {
            print_colored("Invalid input, try again...\n", RED);
        }
    }
    if (choice == 1) {
        append_to_next_empty_line(story_file_name, "Crew member: Yes");
    }
    else {
        append_to_next_empty_line(story_file_name, "Crew member: No");
    }
}
