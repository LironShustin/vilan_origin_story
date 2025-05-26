#ifndef GENERAL_H
#define GENERAL_H
#include "Structs&Enums.h"
#include <Windows.h>

//char* get_random_name();
void generate_random_traits(villainTrait traits[3]);
void clear_console();
void analyzing_encounter_parameter(void);
void print_Output_Villain(const Output_Vilain_Struct* villain);
void print_Drama_Villain(const Output_Vilain_Struct* villain, const Drama_villain* drama_villain, const char* story_name);
void print_Comedy_Villain(const Output_Vilain_Struct* villain, Comedy_villain* comedy_villain, const char* story_name);
void print_Fantasy1_Villain(const Output_Vilain_Struct* villain, Fantasy_villain1* fantasy_villain, const char* story_name);
void print_Fantasy2_villain(const Output_Vilain_Struct* villain, const Fantasy_villain2* fantasy2_villain, const char* story_name);
void print_Scifi_Villain1(const Output_Vilain_Struct* villain, Scifi_villain1* scifi_villain, const char* story_name);
void print_Scifi_Villain2(const Output_Vilain_Struct* villain, Scifi_villain2* scifi_villain, const char* story_name);
void print_Thriller_Villain1(const Output_Vilain_Struct* villain, Thriller_villain1* thriller_villain, const char* story_name);
void print_Thriller_Villain2(const Output_Vilain_Struct* villain, Thriller_villain2* thriller_villain, const char* story_name);
void print_Thriller_Villain3(const Output_Vilain_Struct* villain, Thriller_villain3* thriller_villain, const char* story_name);

#endif
#pragma once