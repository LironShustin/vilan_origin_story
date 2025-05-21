//#ifndef questions_H
//#define questions_H
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//
//void is_realistic(bool* realistic, char* story_file_name);
//void genre(bool realistic, char* story_file_name);
//void how_long_you_met(char* story_file_name);
//void first_meeting_place(char* story_file_name);
//
//
//#endif
//#pragma once

#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void is_realistic(bool* realistic, char* story_file_name);

void genre(bool realistic, char* story_file_name);

void how_long_you_met(char* story_file_name);
void first_meeting_place(char* story_file_name);

void sci_fi_or_fantasy_meeting_place(char* story_file_name);
void thriller_meeting_status(char* story_file_name);
void hero_villain_same_side(char* story_file_name);
void how_long_since_meeting(char* story_file_name);
void thriller_meeting_place(char* story_file_name);
void thriller_hero_duty(char* story_file_name);
void was_one_crew_member(char* story_file_name);

#endif

