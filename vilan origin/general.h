#ifndef GENERAL_H
#define GENERAL_H
#include "Structs&Enums.h"
#include <Windows.h>

char* get_random_name();
void generate_random_traits(villainTrait traits[3]);
void clear_console();
void analyzing_encounter_parameter(void);
void printOutputVillain(const Output_Vilain_Struct* villain);
void printDramaVillain(const Output_Vilain_Struct* villain, const Drama_villain* drama_villain, const char* story_name);

#endif
#pragma once