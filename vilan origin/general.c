#include <stdio.h>
#include <stdlib.h>
#include "Structs&Enums.h"

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

