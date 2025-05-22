#ifndef Structs_And_Enums_H
#define Structs_And_Enums_H

#define True 1
#define False 0
typedef int BOOL;

typedef struct {
	char name[50];
	char is_realistic[50]; //1) yes 2) no
	char genre[50]; //1) Drama 2) Comedy
	char how_long_known[50]; //1) justMet 2) lessThanAYear 3) moreThanAyear
	char where_met[50]; //1) Family 2) studiedTogether 3) Work
	char traits[100];
	char villain_target[300];
	char plot_line[1000];
}drama_villain;

typedef struct {
	char name[50];
	char is_realistic[50]; //1) yes 2) no
	char genre[50]; //1) Drama 2) Comedy
	char how_long_known[50]; //1) justMet 2) lessThanAYear 3) moreThanAyear
	char where_met[50]; //1) Family 2) studiedTogether 3) Work
	char traits[100];
	char villain_target[300];
	char plot_line[1000];
}comedy_villain;

typedef struct {
	char name[50];
	char is_realistic[50]; //1) yes 2) no
	char genre[50]; //1) Drama 2) Comedy
	char meeting_place[50]; //1) enemy_captivity 2) Battlefield
	char same_side[50]; //1) yes 2) no
	char how_long_sience_than[50]; //1) justMet 2) lessThanAweek 3) moreThanAWeek 4) moreThanAYear
	char traits[100];
	char villain_target[300];
	char plot_line[1000];
}fantasy_villain1;

typedef struct {
	char name[50];
	char is_realistic[50]; //1) yes 2) no
	char genre[50]; //1) Drama 2) Comedy
	char meeting_place[50]; //3) canteen
	char crew_member[50]; //1) yes 2) no
	char traits[100];
	char villain_target[300];
	char plot_line[1000];
}fantasy_villain2;

typedef struct {
	char name[50];
	char is_realistic[50]; //1) yes 2) no
	char genre[50]; //1) Drama 2) Comedy
	char meeting_place[50]; //1) enemy_captivity 2) Battlefield
	char same_side[50]; //1) yes 2) no
	char how_long_sience_than[50]; //1) justMet 2) lessThanAweek 3) moreThanAWeek 4) moreThanAYear
	char traits[100];
	char villain_target[300];
	char plot_line[1000];
}scifi_villain1;

typedef struct {
	char name[50];
	char is_realistic[50]; //1) yes 2) no
	char genre[50]; //1) Drama 2) Comedy
	char meeting_place[50]; //3) canteen
	char crew_member[50]; //1) yes 2) no
	char traits[100];
	char villain_target[300];
	char plot_line[1000];
}scifi_villain2;

typedef struct {
	char name[50];
	char is_realistic[50]; //1) yes 2) no
	char genre[50]; //1) Drama 2) Comedy
	char did_they_meet[50]; //1) yes
	char where[50]; //1) canteen
	char crew_member[50]; //1) yes 2) no
	char traits[100];
	char villain_target[300];
	char plot_line[1000];
}thriller_villain1;

typedef struct {
	char name[50];
	char is_realistic[50]; //1) yes 2) no
	char genre[50]; //1) Drama 2) Comedy
	char did_they_meet[50]; //1) yes
	char where[50]; //2) investigationOffice
	char hero_duty[50]; //1) investigator 2) murderer 3) victim 4) uninvolved
	char traits[100];
	char villain_target[300];
	char plot_line[1000];
}thriller_villain2;

typedef struct {
	char name[50];
	char is_realistic[50]; //1) yes 2) no
	char genre[50]; //1) Drama 2) Comedy
	char did_they_meet[50]; //2) no
	char hero_duty[50]; //1) investigator 2) murderer 3) victim 4) uninvolved
	char traits[100];
	char villain_target[300];
	char plot_line[1000];
}thriller_villain3;

#endif 
#pragma once