#pragma once
#ifndef DYNAMIC_MEMORY_ALLOCATION_H
#define DYNAMIC_MEMORY_ALLOCATION_H

#include "Structs&Enums.h"

villainTrait* allocate_default_traits(int* trait_count); //Allocate default 3 traits

villainTrait* allocate_more_traits(int n, int* trait_count); // Allocate n traits (zero-initialized)

void change_trait(villainTrait* traits, int index, villainTrait new_trait); //Change a trait at index 

villainTrait* remove_trait(villainTrait* traits, int* trait_count, int index);//Remove a trait at index

void free_traits(villainTrait* traits);//Free all traits


#endif