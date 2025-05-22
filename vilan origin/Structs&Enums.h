#ifndef Structs_And_Enums_H
#define Structs_And_Enums_H

#define True 1
#define False 0
typedef int BOOL;

typedef struct {
	int how_long_known; //1) justMet 2) lessThanAYear 3) moreThanAyear
	int where_met; //1) Family 2) studiedTogether 3) Work
}drama_villain;

typedef struct {
	int how_long_known; //1) justMet 2) lessThanAYear 3) moreThanAyear
	int where_met; //1) Family 2) studiedTogether 3) Work
}comedy_villain;

typedef struct {
	int meeting_place; //1) enemy_captivity 2) Battlefield
	int same_side; //1) yes 2) no
	int how_long_sience_than; //1) justMet 2) lessThanAweek 3) moreThanAWeek 4) moreThanAYear
}fantasy_villain1;

typedef struct {
	int meeting_place; //3) canteen
	int crew_member; //1) yes 2) no
}fantasy_villain2;

typedef struct {
	int meeting_place; //1) enemy_captivity 2) Battlefield
	int same_side; //1) yes 2) no
	int how_long_sience_than; //1) justMet 2) lessThanAweek 3) moreThanAWeek 4) moreThanAYear
}scifi_villain1;

typedef struct {
	int meeting_place; //3) canteen
	int crew_member; //1) yes 2) no
}scifi_villain2;

typedef struct {
	int did_they_meet; //1) yes
	int where; //1) canteen
	int crew_member; //1) yes 2) no
}thriller_villain1;

typedef struct {
	int did_they_meet; //1) yes
	int where; //2) investigationOffice
	int hero_duty; //1) investigator 2) murderer 3) victim 4) uninvolved
}thriller_villain2;

typedef struct {
	int did_they_meet; //2) no
	int hero_duty; //1) investigator 2) murderer 3) victim 4) uninvolved
}thriller_villain3;

#endif 
#pragma once