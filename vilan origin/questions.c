#include "questions.h"
#include "editingFiles.h"
#include "design.h"
#include "Structs&Enums.h"
#include "general.h"
#include <windows.h>
#include <stdio.h>
#include <string.h>

void is_realistic(BOOL* realistic, char* story_file_name) {
    char answer[10]; // buffer for input
    answer[0] = '0';
    while (answer[0] == '0') {
<<<<<<< HEAD
        print_colored("Is your story realistic? (y/n)\n", YELLOW);
=======
        print_colored("Is your story realistic or fictional?\n", YELLOW);
        print_colored("[1] Realistic\n", BLUE);
        print_colored("[2] Fictional\n", GREEN);
>>>>>>> liron3
        scanf_s(" %9s", answer, (unsigned)_countof(answer));
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {} // clear input buffer

        if ((answer[0] == '1') && answer[1] == '\0') {
            *realistic = True;
            append_to_next_empty_line(story_file_name, "Realistic");
        }
        else if ((answer[0] == '2') && answer[1] == '\0') {
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
    char choice = 0;
    char genre[30];
    if (realistic) {
        while (choice != '1' && choice != '2') {
            print_colored("\nWhat genre is your story?\n", ORANGE);
            print_colored("[1] Drama\n", PINK);
            print_colored("[2] Comedy\n", CYAN);
            scanf_s(" %c", &choice, 1);
            if (choice == '1') {
                strcpy_s(genre, sizeof(genre), "Drama");
            }
            else if (choice == '2') {
                strcpy_s(genre, sizeof(genre), "Comedy");
            }
            else {
                print_colored("invalid input try again...", RED);
                choice = 0; // Reset choice to allow for re-entry
            }
        }
    }
    else {
        while (choice != '1' && choice != '2' && choice != '3') {
            print_colored("\nWhat genre is your story?\n", ORANGE);
            print_colored("[1] Thriller\n", RED); 
            print_colored("[2] Fantasy\n", PURPLE); 
            print_colored("[3] Science Fiction\n", GREEN);
            scanf_s(" %c", &choice, 1);
            if (choice == '1') {
                strcpy_s(genre, sizeof(genre), "Thriller");
            }
            else if (choice == '2') {
                strcpy_s(genre, sizeof(genre), "Fantasy");
            }
            else if (choice == '3') {
                strcpy_s(genre, sizeof(genre), "Science fiction");
            }
            else {
                print_colored("invalid input try again...", RED);
                choice = 0; // Reset choice to allow for re-entry
            }
        }
    }
    append_to_next_empty_line(story_file_name, genre);
}


void how_long_you_met(char* story_file_name, char* genre) {
    char when_met[100] = { 0 };
    char choice = 0;
    while (choice != '1' && choice != '2' && choice != '3') {
        print_colored("\nAt the start of the story how long have your hero and vilain known each other?\n", ORANGE);
        if (strcmp(genre, "Drama") == 0) {
            print_colored("[1] Just met\n", PINK);
            print_colored("[2] Less than a year\n", PINK);
            print_colored("[3] More than a year\n", PINK);
        }
        else if (strcmp(genre, "Comedy") == 0) {
            print_colored("[1] Just met\n", CYAN);
            print_colored("[2] Less than a year\n", CYAN);
            print_colored("[3] More than a year\n", CYAN);
        }
        scanf_s(" %c", &choice, 1);
        if (choice != '1' && choice != '2' && choice != '3') {
            print_colored("Invalid input, try again...\n", RED);
            choice = 0;
        }
    }
    switch (choice) {
    case '1':
        strcpy_s(when_met, sizeof(when_met), "just met");
        break;
    case '2':
        strcpy_s(when_met, sizeof(when_met), "less than a year");
        break;
    case '3':
        strcpy_s(when_met, sizeof(when_met), "more than a year");
        break;
    }
    append_to_next_empty_line(story_file_name, when_met);
}


void first_meeting_place(char* story_file_name, char* genre) {
    char meeting_place[100] = { 0 };
    char choice = 0;
    while (choice != '1' && choice != '2' && choice != '3') {
        print_colored("\nWhere did the hero and villain first meet?\n", ORANGE);
        if (strcmp(genre, "Drama") == 0) {
            print_colored("[1] Family\n", PINK);
            print_colored("[2] School\n", PINK);
            print_colored("[3] Work place\n", PINK);
        }
        else if (strcmp(genre, "Comedy") == 0) {
            print_colored("[1] Family\n", CYAN);
            print_colored("[2] School\n", CYAN);
            print_colored("[3] Work place\n", CYAN);
        }
        scanf_s(" %c", &choice, 1);
        if (choice != '1' && choice != '2' && choice != '3') {
            print_colored("Invalid input, try again...\n", RED);
            choice = 0;
        }
    }
    switch (choice) {
    case '1':
        strcpy_s(meeting_place, sizeof(meeting_place), "family");
        break;
    case '2':
        strcpy_s(meeting_place, sizeof(meeting_place), "school");
        break;
    case '3':
        strcpy_s(meeting_place, sizeof(meeting_place), "work place");
        break;
    }
    append_to_next_empty_line(story_file_name, meeting_place);
    print_colored("Analyzing encounter parameter...\nplease wait...\n", YELLOW);
    Sleep(3000);
}


void sci_fi_or_fantasy_meeting_place(char* story_file_name, char* genre) {
	if (strcmp(genre, "Fantasy") == 0) {

	}
	else if (strcmp(genre, "Science fiction") == 0) {

	}
    else if (strcmp(genre, "Science fiction") == 0) {

    }
    char place[100] = { 0 };
    char choice = 0;
    while (choice != '1' && choice != '2' && choice != '3') {
        print_colored("\nWhere did the hero and villain meet first?\n", ORANGE);
        if (strcmp(genre, "Fantasy") == 0) {
            print_colored("[1] Enemy captivity\n", PURPLE);
            print_colored("[2] Battlefield\n", PURPLE);
            print_colored("[3] Canteen\n", PURPLE);
        }
        else if (strcmp(genre, "Science fiction") == 0) {
            print_colored("[1] Enemy captivity\n", BLUE);
            print_colored("[2] Battlefield\n", BLUE);
            print_colored("[3] Canteen\n", BLUE);
        }
        scanf_s(" %c", &choice, 1);
        clear_console();
        if (choice != '1' && choice != '2' && choice != '3') {
            print_colored("Invalid input, try again...\n", RED);
            choice = 0;
        }
    }
    switch (choice) {
    case '1':
        strcpy_s(place, sizeof(place), "Enemy captivity");
        break;
    case '2':
        strcpy_s(place, sizeof(place), "Battlefield");
        break;
    case '3':
        strcpy_s(place, sizeof(place), "Canteen");
        break;
    }
    append_to_next_empty_line(story_file_name, place);
}

<<<<<<< HEAD
void hero_villain_same_side(char* story_file_name) {
=======
void hero_villain_same_side(char* story_file_name, char* genre) {
>>>>>>> liron3
    char answer[100] = { 0 };
    char choice = 0;
    while (choice != '1' && choice != '2') {
        print_colored("\nWere the hero and the villain on the same side?\n", ORANGE);
        if (strcmp(genre, "Fantasy") == 0) {
            print_colored("[1] Yes\n", PURPLE);
            print_colored("[2] No\n", PURPLE);
        }
        else if (strcmp(genre, "Science fiction") == 0) {
            print_colored("[1] Yes\n", BLUE);
            print_colored("[2] No\n", BLUE);
        }
        scanf_s(" %c", &choice, 1);
        clear_console();
        if (choice != '1' && choice != '2') {
            print_colored("Invalid input, try again...\n", RED);
            choice = 0;
        }
    }
<<<<<<< HEAD
    if (choice == 1) {
        strcpy_s(answer, sizeof(answer), "Yes");
=======
    if (choice == '1') {
        strcpy_s(answer, sizeof(answer), "Same side: Yes");
>>>>>>> liron3
    }
    else {
        strcpy_s(answer, sizeof(answer), "No");
    }
    append_to_next_empty_line(story_file_name, answer);
}


void how_long_since_meeting(char* story_file_name, char* genre) {
    char answer[100] = { 0 };
    char choice = 0;
    while (choice != '1' && choice != '2' && choice != '3' && choice != '4') {
        print_colored("\nHow long has it been since the hero and villain first met?\n", ORANGE);
        if (strcmp(genre, "Fantasy") == 0) {
            print_colored("[1] Just met\n", PURPLE);
            print_colored("[2] Less than a week\n", PURPLE);
            print_colored("[3] More than a week\n", PURPLE);
            print_colored("[4] More than a year\n", PURPLE);
        }
        else if (strcmp(genre, "Science fiction") == 0) {
            print_colored("[1] Just met\n", BLUE);
            print_colored("[2] Less than a week\n", BLUE);
            print_colored("[3] More than a week\n", BLUE);
            print_colored("[4] More than a year\n", BLUE);
        }
        scanf_s(" %c", &choice, 1);
        clear_console();
        if (choice != '1' && choice != '2' && choice != '3' && choice != '4') {
            print_colored("Invalid input, try again...\n", RED);
            choice = 0;
        }
    }
    switch (choice) {
    case '1':
        strcpy_s(answer, sizeof(answer), "Just met");
        break;
    case '2':
        strcpy_s(answer, sizeof(answer), "Less than a week");
        break;
    case '3':
        strcpy_s(answer, sizeof(answer), "More than a week");
        break;
    case '4':
        strcpy_s(answer, sizeof(answer), "More than a year");
        break;
    }
    append_to_next_empty_line(story_file_name, answer);
    print_colored("Analyzing encounter parameter...\nplease wait...\n", YELLOW);
    Sleep(3000);
}

void thriller_meeting_status(char* story_file_name) {
    char answer[20] = { 0 };
    char choice = 0;
    while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
        print_colored("\nDid the hero and villain already know each other at the begining of the story?\n", YELLOW);
        print_colored("[1] Yes\n", ORANGE);
        print_colored("[2] No\n", ORANGE);
        scanf_s(" %c", &choice, 1);
        clear_console();
        if (choice != '1' && choice != '2') {
            print_colored("Invalid input, try again...\n", RED);
            choice = 0;
        }
    }
    if (choice == '1') {
        strcpy_s(answer, sizeof(answer), "Yes");
    }
    else {
        strcpy_s(answer, sizeof(answer), "No");
    }
    append_to_next_empty_line(story_file_name, answer);
}

void thriller_meeting_place(char* story_file_name) {
    char choice = 0;
    while (choice != '1' && choice != '2') {
        print_colored("\nWhere did the hero and villain first meet each other?\n", YELLOW);
        print_colored("[1] Canteen\n", ORANGE);
        print_colored("[2] Investigation Office\n", ORANGE);
        scanf_s(" %c", &choice, 1);
        clear_console();
        if (choice != '1' && choice != '2') {
            print_colored("Invalid input, try again...\n", RED);
            choice = 0;
        }
    }
    if (choice == '1') {
        append_to_next_empty_line(story_file_name, "Canteen");
    }
    else if (choice == '2') {
        append_to_next_empty_line(story_file_name, "Investigation Office");
    }
}


void thriller_hero_duty(char* story_file_name) {
    char choice = 0;
    while (choice != '1' && choice != '2' && choice != '3') {
        print_colored("\nWhat is the role of the hero in the story?\n", YELLOW);
        print_colored("[1] Investigator\n", ORANGE);
        print_colored("[2] Murderer\n", ORANGE);
        print_colored("[3] Victim\n", ORANGE);
        scanf_s(" %c", &choice, 1);
        clear_console();
        if (choice != '1' && choice != '2' && choice != '3') {
            print_colored("Invalid input, try again...\n", RED);
            choice = 0;
        }
    }
    switch (choice) {
    case '1': append_to_next_empty_line(story_file_name, "Investigator"); break;
    case '2': append_to_next_empty_line(story_file_name, "Murderer"); break;
    case '3': append_to_next_empty_line(story_file_name, "Victim"); break;
    }
    print_colored("Analyzing encounter parameter...\nplease wait...\n", YELLOW);
    Sleep(3000);
}


void was_one_crew_member(char* story_file_name, char* genre) {

	if (strcmp(genre, "Fantasy") == 0) {

	}
	else if (strcmp(genre, "Science fiction") == 0) {

	}
	else if (strcmp(genre, "Thriller") == 0) {

	}
    char choice = 0;
    while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
        print_colored("\nWas the villain a staff member in the canteen?\n", ORANGE);
        print_colored("[1] Yes\n", YELLOW);
        print_colored("[2] No\n", YELLOW);
        scanf_s(" %c", &choice, 1);
        if (choice != '1' && choice != '2') {
            print_colored("Invalid input, try again...\n", RED);
            choice = 0;
        }
    }
<<<<<<< HEAD
    if (choice == 1) {
        append_to_next_empty_line(story_file_name, "Yes");
=======
    if (choice == '1') {
        append_to_next_empty_line(story_file_name, "Crew member: Yes");
>>>>>>> liron3
    }
    else {
        append_to_next_empty_line(story_file_name, "No");
    }
    print_colored("Analyzing encounter parameter...\nplease wait...\n", YELLOW);
    Sleep(3000);
}

<<<<<<< HEAD
void are_you_happy_with_your_result() {
    char answer = '0';
    while (answer == '0') {
        print_colored("Are you happy with the vilain/antagonist generated?\n", YELLOW);
        print_colored("[1] Yes\n [2] No", CYAN);
        scanf_s(" %c", &answer, 1);
        if (answer == 'y' || answer == 'Y' || answer == '1') {
            print_colored("Great! I'm happy to hear, goodbye!", GREEN);
        }
        else if (answer == 'n' || answer == 'N' || answer == '2') {
            print_colored("I'm sorry to hear that", ORANGE);
            print_colored("Do you want to generate a new one insted", YELLOW);
            //NEED TO CONTINUE
        }
        else {
            answer = '0';
            print_colored("Invalid Input!, try again", RED);
        }
    }
}
=======
>>>>>>> liron3
