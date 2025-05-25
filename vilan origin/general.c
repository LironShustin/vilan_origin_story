#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Structs&Enums.h"
#include "design.h"

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


