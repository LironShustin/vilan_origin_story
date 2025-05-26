#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structs&Enums.h"

void is_realistic(BOOL* realistic, char* story_file_name);
void genre(BOOL realistic, char* story_file_name);
void how_long_you_met(char* story_file_name, char* genre);
void first_meeting_place(char* story_file_name, char* genre);
void sci_fi_or_fantasy_meeting_place(char* story_file_name, char* genre);
void thriller_meeting_status(char* story_file_name);
void hero_villain_same_side(char* story_file_name, char* genre);
void how_long_since_meeting(char* story_file_name, char* genre);
void thriller_meeting_place(char* story_file_name);
void thriller_hero_duty(char* story_file_name);
void was_one_crew_member(char* story_file_name, char* genre);
void are_you_happy_with_your_result(int r, int match_count, char database[100], int* match_lines, int n, Output_Vilain_Struct* output, int* run, int* print);
void generate_another(int r, int match_count, char database[100], int* match_lines, int n, Output_Vilain_Struct* output, int* run, int* print);

#endif
#pragma once

