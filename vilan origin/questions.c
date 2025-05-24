#include "questions.h"
#include "editingFiles.h"
#include "design.h"
#include "Structs&Enums.h"
#include <windows.h>
#include <stdio.h>
#include <string.h>

void is_realistic(BOOL* realistic, char* story_file_name) {
    char answer[10]; // buffer for input
    answer[0] = '0';
    while (answer[0] == '0') {
        print_colored("Is your story realistic?\n", YELLOW);
        print_colored_rgb("[y] Yes\n", 120, 255, 120);
        print_colored_rgb("[n] No\n", 255, 80, 80);
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
    char choice = 0;
    char genre[30];
    if (realistic) {
        while (choice != '1' && choice != '2') {
            print_colored("\nWhat genre is your story?\n", YELLOW);
            print_colored_rgb("[1] ", 255, 255, 0); print_colored_rgb("Drama\n", 255, 180, 80);
            print_colored_rgb("[2] ", 120, 255, 120); print_colored_rgb("Comedy\n", 120, 120, 255);
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
            print_colored("\nWhat genre is your story?\n", YELLOW);
            print_colored_rgb("[1] ", 255, 255, 0); print_colored_rgb("Thriller\n", 255, 180, 80);
            print_colored_rgb("[2] ", 120, 255, 120); print_colored_rgb("Fantasy\n", 120, 120, 255);
            print_colored_rgb("[3] ", 120, 255, 255); print_colored_rgb("Science Fiction\n", 120, 255, 120);
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


void how_long_you_met(char* story_file_name) {
    char when_met[100] = { 0 };
    char choice = 0;
    while (choice != '1' && choice != '2' && choice != '3') {
        print_colored("\nWhen the story starts how long have your hero and vilain known each other?\n", YELLOW);
        print_colored_rgb("[1] Just met\n", 255, 255, 0);
        print_colored_rgb("[2] Less than a year\n", 120, 255, 120);
        print_colored_rgb("[3] More than a year\n", 120, 255, 255);
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


void first_meeting_place(char* story_file_name) {
    char meeting_place[100] = { 0 };
    char choice = 0;
    while (choice != '1' && choice != '2' && choice != '3') {
        print_colored("\nWhere did the hero and villain first meet?\n", YELLOW);
        print_colored_rgb("[1] Family\n", 255, 255, 0);
        print_colored_rgb("[2] School\n", 120, 255, 120);
        print_colored_rgb("[3] Work place\n", 120, 255, 255);
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


void sci_fi_or_fantasy_meeting_place(char* story_file_name) {
    char place[100] = { 0 };
    char choice = 0;
    while (choice != '1' && choice != '2' && choice != '3') {
        print_colored("\nWhere did the hero and villain meet first?\n", YELLOW);
        print_colored_rgb("[1] Enemy captivity\n", 255, 255, 0);
        print_colored_rgb("[2] Battlefield\n", 120, 255, 120);
        print_colored_rgb("[3] Canteen\n", 120, 255, 255);
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

void hero_villain_same_side(char* story_file_name) {
    char answer[100] = { 0 };
    char choice = 0;
    while (choice != '1' && choice != '2') {
        print_colored("\nWere the hero and the villain on the same side?\n", YELLOW);
        print_colored_rgb("[y] Yes\n", 120, 255, 120);
        print_colored_rgb("[n] No\n", 255, 80, 80);
        scanf_s(" %c", &choice, 1);
        clear_console();
        if (choice != 'y' || choice != 'Y' && choice != 'n' || choice != 'N') {
            print_colored("Invalid input, try again...\n", RED);
            choice = 0;
        }
    }
    if (choice == 'y' || choice == 'Y') {
        strcpy_s(answer, sizeof(answer), "Same side: Yes");
    }
    else {
        strcpy_s(answer, sizeof(answer), "Same side: No");
    }
    append_to_next_empty_line(story_file_name, answer);
}


void how_long_since_meeting(char* story_file_name) {
    char answer[100] = { 0 };
    char choice = 0;
    while (choice != '1' && choice != '2' && choice != '3' && choice != '4') {
        print_colored("\nHow long has it been since then?\n", YELLOW);
        print_colored_rgb("[1] Just met\n", 255, 255, 0);
        print_colored_rgb("[2] Less than a week\n", 120, 255, 120);
        print_colored_rgb("[3] More than a week\n", 120, 255, 255);
        print_colored_rgb("[4] More than a year\n", 120, 120, 255);
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
        print_colored("\nDid the hero and villain already meet each other?\n", YELLOW);
        print_colored_rgb("[y] Yes\n", 120, 255, 120);
        print_colored_rgb("[n] No\n", 255, 80, 80);
        scanf_s(" %c", &choice, 1);
        clear_console();
        if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
            print_colored("Invalid input, try again...\n", RED);
            choice = 0;
        }
    }
    if (choice == 'y' || choice == 'Y') {
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
        print_colored("\nWhere did they first meet each other?\n", YELLOW);
        print_colored_rgb("[1] Canteen\n", 120, 255, 120);
        print_colored_rgb("[2] Investigation Office\n", 120, 120, 255);
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
        print_colored("\nWhat is the duty of the hero\n", YELLOW);
        print_colored_rgb("[1] Investigator\n", 120, 255, 120);
        print_colored_rgb("[2] Murderer\n", 255, 80, 80);
        print_colored_rgb("[3] Victim\n", 120, 120, 255);
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


void was_one_crew_member(char* story_file_name) {
    char choice = 0;
    while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
        print_colored("\nWas one of them a crew member?\n", YELLOW);
        print_colored_rgb("[y] Yes\n", 120, 255, 120);
        print_colored_rgb("[n] No\n", 255, 80, 80);
        scanf_s(" %c", &choice, 1);
        if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
            print_colored("Invalid input, try again...\n", RED);
            choice = 0;
        }
    }
    if (choice == 'y' || choice == 'Y') {
        append_to_next_empty_line(story_file_name, "Crew member: Yes");
    }
    else {
        append_to_next_empty_line(story_file_name, "Crew member: No");
    }
    print_colored("Analyzing encounter parameter...\nplease wait...\n", YELLOW);
    Sleep(3000);
}

