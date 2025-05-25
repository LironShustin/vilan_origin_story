#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Structs&Enums.h"
#include "design.h"

<<<<<<< HEAD
void printOutputVillain(const Output_Vilain_Struct* villain) {
    printf("Story Title: %s\n", villain->story_title);
    printf("Realistic: %s\n", villain->realistic);
    printf("Genre: %s\n", villain->genre);
    printf("Line 1: %s\n", villain->line1);
    printf("Line 2: %s\n", villain->line2);
    printf("Line 3: %s\n", villain->line3);
    printf("Line 4: %s\n", villain->line4);
    printf("Line 5: %s\n", villain->line5);
}

void printDramaVillain(const Output_Vilain_Struct* villain, const Drama_villain* drama_villain, const char* story_name) {
    strcpy_s(drama_villain->Story_name, sizeof(drama_villain->Story_name), story_name);
    strcpy_s(drama_villain->is_realistic, sizeof(drama_villain->is_realistic), "Realistic");
    strcpy_s(drama_villain->genre, sizeof(drama_villain->genre), "Drama");
    strcpy_s(drama_villain->how_long_known, sizeof(drama_villain->how_long_known), (const char*)villain->line1);
    strcpy_s(drama_villain->where_met, sizeof(drama_villain->where_met), (const char*)villain->line2);
    strcpy_s(drama_villain->villain_target, sizeof(drama_villain->villain_target), (const char*)villain->line3);
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
        printf("The hero and villain are coleagues\n");
    }
    // role
    printf("Your villain is %s\n", drama_villain->villain_target);
    // plot line
    printf("My suggested plot line:\n%s\n", villain->line4);
=======
#define MAX_NAMES 50
#define MAX_NAME_LENGTH 100

char* get_random_name() {
    static char name[MAX_NAME_LENGTH];
    FILE* file = fopen("names.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    int random_index = rand() % MAX_NAMES;

    for (int i = 0; i <= random_index; i++) {
        if (fgets(name, MAX_NAME_LENGTH, file) == NULL) {
            fprintf(stderr, "Error reading line %d\n", i);
            fclose(file);
            return NULL;
        }
    }

    fclose(file);
    return name;
>>>>>>> liron5
}

void generate_random_traits(villainTrait traits[3]) {
    int used[TRAIT_COUNT] = { 0 };
    int count = 0;
    while (count < 3) {
        int r = rand() % TRAIT_COUNT;
        if (!used[r]) {
            traits[count++] = (villainTrait)r;
            used[r] = 1;
        }
    }
}

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
