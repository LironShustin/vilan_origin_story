#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Structs&Enums.h"
#include "design.h"

#define MAX_NAMES 50
#define MAX_NAME_LENGTH 100


void print_Output_Villain(const Output_Vilain_Struct* villain) {
    printf("Story Title: %s\n", villain->story_title);
    printf("Realistic: %s\n", villain->realistic);
    printf("Genre: %s\n", villain->genre);
    printf("Line 1: %s\n", villain->line1);
    printf("Line 2: %s\n", villain->line2);
    printf("Line 3: %s\n", villain->line3);
    printf("Line 4: %s\n", villain->line4);
    printf("Line 5: %s\n", villain->line5);
}

void print_Drama_Villain(const Output_Vilain_Struct* villain, const Drama_villain* drama_villain, const char* story_name) {
    strcpy_s(drama_villain->Story_name, sizeof(drama_villain->Story_name), story_name);
    strcpy_s(drama_villain->is_realistic, sizeof(drama_villain->is_realistic), "Realistic");
    strcpy_s(drama_villain->genre, sizeof(drama_villain->genre), "Drama");
    strcpy_s(drama_villain->how_long_known, sizeof(drama_villain->how_long_known), (const char*)villain->line1);
    strcpy_s(drama_villain->where_met, sizeof(drama_villain->where_met), (const char*)villain->line2);
    strcpy_s(drama_villain->villain_target, sizeof(drama_villain->villain_target), (const char*)villain->line3);
    strcpy_s(drama_villain->plot_line, sizeof(drama_villain->plot_line), (const char*)villain->line4);
    printf("Story Title: %s\n", drama_villain->Story_name);
    printf("Type: %s\n", drama_villain->is_realistic);
    printf("Genre: %s\n", drama_villain->genre);
    // Q 1
    if (strcmp(drama_villain->how_long_known, "Just met") == 0) {
        printf("The hero and villain dont know each other at the start of the story.\n");
    }
    else {
        printf("The hero and villain have known each other for %s\n", drama_villain->how_long_known);
    }
    // Q 2
    if (strcmp(drama_villain->where_met, "Family") == 0) {
        printf("The hero and villain are family members\n");
    }
    else if (strcmp(drama_villain->where_met, "School") == 0) {
        printf("The hero and villain are school mates\n");
    }
    else if (strcmp(drama_villain->where_met, "Work place") == 0) {
        printf("The hero and villain are colleagues\n");
    }
    // role
    printf("Your villain is %s\n", drama_villain->villain_target);
    // plot line
    printf("My suggested plot line:\n%s\n", drama_villain->plot_line);
}

void print_Comedy_Villain(const Output_Vilain_Struct* villain, Comedy_villain* comedy_villain, const char* story_name) {
    strcpy_s(comedy_villain->Story_name, sizeof(comedy_villain->Story_name), story_name);
    strcpy_s(comedy_villain->is_realistic, sizeof(comedy_villain->is_realistic), "Realistic");
    strcpy_s(comedy_villain->genre, sizeof(comedy_villain->genre), "Comedy");
    strcpy_s(comedy_villain->how_long_known, sizeof(comedy_villain->how_long_known), (const char*)villain->line1);
    strcpy_s(comedy_villain->where_met, sizeof(comedy_villain->where_met), (const char*)villain->line2);
    strcpy_s(comedy_villain->villain_target, sizeof(comedy_villain->villain_target), (const char*)villain->line3);
    strcpy_s(comedy_villain->plot_line, sizeof(comedy_villain->plot_line), (const char*)villain->line4);
    printf("Story Title: %s\n", comedy_villain->Story_name);
    printf("Type: %s\n", comedy_villain->is_realistic);
    printf("Genre: %s\n", comedy_villain->genre);
    // Q1
    if (strcmp(comedy_villain->how_long_known, "Just met") == 0) {
        printf("The hero and villain just met\n");
    }
    else {
        printf("The hero and villain have known each other for %s\n", comedy_villain->how_long_known);
    }
    // Q2
    if (strcmp(comedy_villain->where_met, "Family") == 0) {
        printf("The hero and villain are family members\n");
    }
    else if (strcmp(comedy_villain->where_met, "School") == 0) {
        printf("The hero and villain are school mates\n");
    }
    else if (strcmp(comedy_villain->where_met, "Work place") == 0) {
        printf("The hero and villain are colleagues\n");
    }
    // Role
    printf("Your villain is %s\n", comedy_villain->villain_target);
    // Plot line
    printf("My suggested plot line:\n%s\n", comedy_villain->plot_line);
}

void print_Fantasy1_Villain(const Output_Vilain_Struct* villain, Fantasy_villain1* fantasy_villain, const char* story_name) {
    strcpy_s(fantasy_villain->Story_name, sizeof(fantasy_villain->Story_name), story_name);
    strcpy_s(fantasy_villain->is_realistic, sizeof(fantasy_villain->is_realistic), "Fictional");
    strcpy_s(fantasy_villain->genre, sizeof(fantasy_villain->genre), "Fantasy");
    strcpy_s(fantasy_villain->meeting_place, sizeof(fantasy_villain->meeting_place), (const char*)villain->line1);
    strcpy_s(fantasy_villain->same_side, sizeof(fantasy_villain->same_side), (const char*)villain->line2);
    strcpy_s(fantasy_villain->how_long_sience_than, sizeof(fantasy_villain->how_long_sience_than), (const char*)villain->line3);
    strcpy_s(fantasy_villain->villain_target, sizeof(fantasy_villain->villain_target), (const char*)villain->line4);
    strcpy_s(fantasy_villain->plot_line, sizeof(fantasy_villain->plot_line), (const char*)villain->line5);
    printf("Story Title: %s\n", fantasy_villain->Story_name);
    printf("Type: %s\n", fantasy_villain->is_realistic);
    printf("Genre: %s\n", fantasy_villain->genre);
    // Q1
    if (strcmp(fantasy_villain->meeting_place, "Enemy captivity") == 0) {
        printf("The hero and villain first met while being held in enemy captivity\n");
    }
    else if (strcmp(fantasy_villain->meeting_place, "Battlefield") == 0) {
        printf("The hero and villain first met on the battlefield\n");
    }
    // Q2
    if (strcmp(fantasy_villain->same_side, "Yes") == 0) {
        printf("They were on the same side when they met\n");
    }
    else if (strcmp(fantasy_villain->same_side, "No") == 0) {
        printf("They were on opposite sides when they met\n");
    }
    // Q3
    printf("It has been %s since they first met\n", fantasy_villain->how_long_sience_than);
    // Role
    printf("Your villain is %s\n", fantasy_villain->villain_target);
    // Plot line
    printf("My suggested plot line:\n%s\n", fantasy_villain->plot_line);
}

void print_Fantasy2_villain(const Output_Vilain_Struct* villain, const Fantasy_villain2* fantasy2_villain, const char* story_name) {
    strcpy_s(fantasy2_villain->Story_name, sizeof(fantasy2_villain->Story_name), story_name);
    strcpy_s(fantasy2_villain->is_realistic, sizeof(fantasy2_villain->is_realistic), "Fictional");
    strcpy_s(fantasy2_villain->genre, sizeof(fantasy2_villain->genre), "Science fiction");
    strcpy_s(fantasy2_villain->meeting_place, sizeof(fantasy2_villain->meeting_place), (const char*)villain->line1);
    strcpy_s(fantasy2_villain->crew_member, sizeof(fantasy2_villain->crew_member), (const char*)villain->line2);
    strcpy_s(fantasy2_villain->villain_target, sizeof(fantasy2_villain->villain_target), (const char*)villain->line3);
    strcpy_s(fantasy2_villain->plot_line, sizeof(fantasy2_villain->plot_line), (const char*)villain->line4);
    // Q 1
    printf("The hero and villain first met at the %s", fantasy2_villain->meeting_place);
    // Q 2
    if (strcmp(fantasy2_villain->crew_member, "Yes") == 0) {
        printf("The villain was a staff member at the Canteen\n");
    }
    else if (strcmp(fantasy2_villain->crew_member, "No") == 0) {
        printf("The hero and villain are school mates\n");
    }
    // role
    printf("Your villain is %s\n", fantasy2_villain->villain_target);
    // plot line
    printf("My suggested plot line:\n%s\n", fantasy2_villain->plot_line);
}

void print_Scifi_Villain1(const Output_Vilain_Struct* villain, Scifi_villain1* scifi_villain, const char* story_name) {
    strcpy_s(scifi_villain->Story_name, sizeof(scifi_villain->Story_name), story_name);
    strcpy_s(scifi_villain->is_realistic, sizeof(scifi_villain->is_realistic), "Fictional");
    strcpy_s(scifi_villain->genre, sizeof(scifi_villain->genre), "Science fiction");
    strcpy_s(scifi_villain->meeting_place, sizeof(scifi_villain->meeting_place), (const char*)villain->line1);
    strcpy_s(scifi_villain->same_side, sizeof(scifi_villain->same_side), (const char*)villain->line2);
    strcpy_s(scifi_villain->how_long_sience_than, sizeof(scifi_villain->how_long_sience_than), (const char*)villain->line3);
    strcpy_s(scifi_villain->villain_target, sizeof(scifi_villain->villain_target), (const char*)villain->line4);
    strcpy_s(scifi_villain->plot_line, sizeof(scifi_villain->plot_line), (const char*)villain->line5);
    printf("Story Title: %s\n", scifi_villain->Story_name);
    printf("Type: %s\n", scifi_villain->is_realistic);
    printf("Genre: %s\n", scifi_villain->genre);
    // Q1
    if (strcmp(scifi_villain->meeting_place, "Enemy captivity") == 0) {
        printf("The hero and villain first met while being held in enemy captivity\n");
    }
    else if (strcmp(scifi_villain->meeting_place, "Battlefield") == 0) {
        printf("The hero and villain first met on the battlefield\n");
    }
    // Q2
    if (strcmp(scifi_villain->same_side, "Yes") == 0) {
        printf("They were on the same side when they met\n");
    }
    else if (strcmp(scifi_villain->same_side, "No") == 0) {
        printf("They were on opposite sides when they met\n");
    }
    // Q3
    printf("It has been %s since they first met\n", scifi_villain->how_long_sience_than);
    // Role
    printf("Your villain is %s\n", scifi_villain->villain_target);
    // Plot line
    printf("My suggested plot line:\n%s\n", scifi_villain->plot_line);
}

void print_Scifi_Villain2(const Output_Vilain_Struct* villain, Scifi_villain2* scifi_villain, const char* story_name) {
    strcpy_s(scifi_villain->Story_name, sizeof(scifi_villain->Story_name), story_name);
    strcpy_s(scifi_villain->is_realistic, sizeof(scifi_villain->is_realistic), "Fictional");
    strcpy_s(scifi_villain->genre, sizeof(scifi_villain->genre), "Science fiction");
    strcpy_s(scifi_villain->meeting_place, sizeof(scifi_villain->meeting_place), (const char*)villain->line1);
    strcpy_s(scifi_villain->crew_member, sizeof(scifi_villain->crew_member), (const char*)villain->line2);
    strcpy_s(scifi_villain->villain_target, sizeof(scifi_villain->villain_target), (const char*)villain->line3);
    strcpy_s(scifi_villain->plot_line, sizeof(scifi_villain->plot_line), (const char*)villain->line4);
    printf("Story Title: %s\n", scifi_villain->Story_name);
    printf("Type: %s\n", scifi_villain->is_realistic);
    printf("Genre: %s\n", scifi_villain->genre);
    // Q1
    printf("The hero and villain first met at the %s\n", scifi_villain->meeting_place);
    // Q2
    if (strcmp(scifi_villain->crew_member, "Yes") == 0) {
        printf("The villain was a staff member at the canteen\n");
    }
    else if (strcmp(scifi_villain->crew_member, "No") == 0) {
        printf("The villain was not a part of the canteen staff\n");
    }
    // Role
    printf("Your villain is %s\n", scifi_villain->villain_target);
    // Plot line
    printf("My suggested plot line:\n%s\n", scifi_villain->plot_line);
}

void print_Thriller_Villain1(const Output_Vilain_Struct* villain, Thriller_villain1* thriller_villain, const char* story_name) {
    strcpy_s(thriller_villain->Story_name, sizeof(thriller_villain->Story_name), story_name);
    strcpy_s(thriller_villain->is_realistic, sizeof(thriller_villain->is_realistic), "Fictional");
    strcpy_s(thriller_villain->genre, sizeof(thriller_villain->genre), "Thriller");
    strcpy_s(thriller_villain->did_they_meet, sizeof(thriller_villain->did_they_meet), (const char*)villain->line1);
    strcpy_s(thriller_villain->where, sizeof(thriller_villain->where), (const char*)villain->line2);
    strcpy_s(thriller_villain->crew_member, sizeof(thriller_villain->crew_member), (const char*)villain->line3);
    strcpy_s(thriller_villain->villain_target, sizeof(thriller_villain->villain_target), (const char*)villain->line4);
    strcpy_s(thriller_villain->plot_line, sizeof(thriller_villain->plot_line), (const char*)villain->line5);
    printf("Story Title: %s\n", thriller_villain->Story_name);
    printf("Type: %s\n", thriller_villain->is_realistic);
    printf("Genre: %s\n", thriller_villain->genre);
    // Q1
    printf("The hero and villain already met each other\n");
    // Q2
    printf("They first met at the %s\n", thriller_villain->where);
    // Q3a
    if (strcmp(thriller_villain->crew_member, "Yes") == 0) {
        printf("The villain was a staff member at the canteen\n");
    }
    else if (strcmp(thriller_villain->crew_member, "No") == 0) {
        printf("The villain was not a part of the canteen staff\n");
    }
    // Role
    printf("Your villain is %s\n", thriller_villain->villain_target);
    // Plot line
    printf("My suggested plot line:\n%s\n", thriller_villain->plot_line);
}

void print_Thriller_Villain2(const Output_Vilain_Struct* villain, Thriller_villain2* thriller_villain, const char* story_name) {
    strcpy_s(thriller_villain->Story_name, sizeof(thriller_villain->Story_name), story_name);
    strcpy_s(thriller_villain->is_realistic, sizeof(thriller_villain->is_realistic), "Fictional");
    strcpy_s(thriller_villain->genre, sizeof(thriller_villain->genre), "Thriller");
    strcpy_s(thriller_villain->did_they_meet, sizeof(thriller_villain->did_they_meet), (const char*)villain->line1);
    strcpy_s(thriller_villain->where, sizeof(thriller_villain->where), (const char*)villain->line2);
    strcpy_s(thriller_villain->hero_duty, sizeof(thriller_villain->hero_duty), (const char*)villain->line3);
    strcpy_s(thriller_villain->villain_target, sizeof(thriller_villain->villain_target), (const char*)villain->line4);
    strcpy_s(thriller_villain->plot_line, sizeof(thriller_villain->plot_line), (const char*)villain->line5);
    printf("Story Title: %s\n", thriller_villain->Story_name);
    printf("Type: %s\n", thriller_villain->is_realistic);
    printf("Genre: %s\n", thriller_villain->genre);
    // Q1
    printf("The hero and villain already met each other\n");
    // Q2
    printf("They first met at an %s\n", thriller_villain->where);
    // Q3b
    if (strcmp(thriller_villain->hero_duty, "Investigator") == 0) {
        printf("The hero is an investigator in this story\n");
    }
    else if (strcmp(thriller_villain->hero_duty, "Murderer") == 0) {
        printf("The hero is the murderer in this story\n");
    }
    else if (strcmp(thriller_villain->hero_duty, "Victim") == 0) {
        printf("The hero is the victim in this story\n");
    }
    // Role
    printf("Your villain is %s\n", thriller_villain->villain_target);
    // Plot line
    printf("My suggested plot line:\n%s\n", thriller_villain->plot_line);
}

void print_Thriller_Villain3(const Output_Vilain_Struct* villain, Thriller_villain3* thriller_villain, const char* story_name) {
    strcpy_s(thriller_villain->Story_name, sizeof(thriller_villain->Story_name), story_name);
    strcpy_s(thriller_villain->is_realistic, sizeof(thriller_villain->is_realistic), "Fictional");
    strcpy_s(thriller_villain->genre, sizeof(thriller_villain->genre), "Thriller");
    strcpy_s(thriller_villain->did_they_meet, sizeof(thriller_villain->did_they_meet), (const char*)villain->line1);
    strcpy_s(thriller_villain->hero_duty, sizeof(thriller_villain->hero_duty), (const char*)villain->line2);
    strcpy_s(thriller_villain->villain_target, sizeof(thriller_villain->villain_target), (const char*)villain->line3);
    strcpy_s(thriller_villain->plot_line, sizeof(thriller_villain->plot_line), (const char*)villain->line4);
    printf("Story Title: %s\n", thriller_villain->Story_name);
    printf("Type: %s\n", thriller_villain->is_realistic);
    printf("Genre: %s\n", thriller_villain->genre);
    // Q1
    printf("The hero and villain have not yet met in the story\n");
    // Q2
    if (strcmp(thriller_villain->hero_duty, "Investigator") == 0) {
        printf("The hero is an investigator in this story\n");
    }
    else if (strcmp(thriller_villain->hero_duty, "Murderer") == 0) {
        printf("The hero is the murderer in this story\n");
    }
    else if (strcmp(thriller_villain->hero_duty, "Victim") == 0) {
        printf("The hero is the victim in this story\n");
    }
    // Role
    printf("Your villain is %s\n", thriller_villain->villain_target);
    // Plot line
    printf("My suggested plot line:\n%s\n", thriller_villain->plot_line);
}

//char* get_random_name() {
//    static char name[MAX_NAME_LENGTH];
//    FILE* file = fopen("names.txt", "r");
//    if (file == NULL) {
//        perror("Error opening file");
//        return NULL;
//    }
//    int random_index = rand() % MAX_NAMES;
//    for (int i = 0; i <= random_index; i++) {
//        if (fgets(name, MAX_NAME_LENGTH, file) == NULL) {
//            fprintf(stderr, "Error reading line %d\n", i);
//            fclose(file);
//            return NULL;
//        }
//    }
//    fclose(file);
//    return name;
//}


void clear_console() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void analyzing_encounter_parameter(void) {
    print_colored("Analyzing encounter parameter...\nplease wait...\n", ORANGE);
    Sleep(3000);
}
