#include <stdlib.h>
#include "dynamicMemoryAllocation.h"

villainTrait* allocate_default_traits(int* trait_count) {
    *trait_count = 3;
    return (villainTrait*)malloc(3 * sizeof(villainTrait));
}

villainTrait* allocate_more_traits(int n, int* trait_count) {
    *trait_count = n;
    return (villainTrait*)calloc(n, sizeof(villainTrait));
}

void change_trait(villainTrait* traits, int index, villainTrait new_trait) {
    traits[index] = new_trait;
}

villainTrait* remove_trait(villainTrait* traits, int* trait_count, int index) {
    if (*trait_count <= 1) {
        return traits;
    }
    villainTrait* new_traits = (villainTrait*)malloc((*trait_count - 1) * sizeof(villainTrait));
    for (int i = 0, j = 0; i < *trait_count; ++i) {
        if (i != index) {
            new_traits[j++] = traits[i];
        }
    }
    free(traits);
    (*trait_count)--;
    return new_traits;
}


void free_traits(villainTrait* traits) {
    free(traits);
}
