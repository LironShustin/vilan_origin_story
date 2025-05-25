#ifndef Structs_And_Enums_H
#define Structs_And_Enums_H
#define MAX_LINE_LEN 1024
#define True 1
#define False 0

typedef int BOOL;

typedef struct {
    char story_title[MAX_LINE_LEN];
    char realistic[MAX_LINE_LEN];
    char genre[MAX_LINE_LEN];
    char line1[MAX_LINE_LEN];
    char line2[MAX_LINE_LEN];
    char line3[MAX_LINE_LEN];
	char line4[MAX_LINE_LEN];
    char line5[MAX_LINE_LEN];
} Output_Vilain_Struct; // need to zeero out all feilds before using

typedef enum {
	TRAIT_CUNNING,
	TRAIT_RUTHLESS,
	TRAIT_MANIPULATIVE,
	TRAIT_ARROGANT,
	TRAIT_VENGEFUL,
	TRAIT_GREEDY,
	TRAIT_MERCILESS,
	TRAIT_DECEPTIVE,
	TRAIT_AMBITIOUS,
	TRAIT_CALLOUS,
	TRAIT_CRUEL,
	TRAIT_ENVIOUS,
	TRAIT_FANATICAL,
	TRAIT_IMPULSIVE,
	TRAIT_JEALOUS,
	TRAIT_MACHIAVELLIAN,
	TRAIT_NARCISSISTIC,
	TRAIT_PARANOID,
	TRAIT_PERSISTENT,
	TRAIT_POWER_HUNGRY,
	TRAIT_REMORSELESS,
	TRAIT_SADISTIC,
	TRAIT_SELFISH,
	TRAIT_UNFORGIVING,
	TRAIT_UNTRUSTWORTHY,
	TRAIT_VICIOUS,
	TRAIT_WITTY,
	TRAIT_CHAOTIC,
	TRAIT_CALCULATING,
	TRAIT_OPPORTUNISTIC,
	TRAIT_COUNT // for bounds checking
} villainTrait;

typedef struct {
	char Story_name[50];
	char is_realistic[50]; // yes
	char genre[50]; //Drama 
	char how_long_known[50]; //1) justMet 2) lessThanAYear 3) moreThanAyear
	char where_met[50]; //1) Family 2) studiedTogether 3) Work
	char villain_target[300];
	char plot_line[1000];
	villainTrait traits[3]; // villain will always have 3 traits
}Drama_villain;

//typedef struct {
//	char name[50];
//	char is_realistic[50]; // yes 
//	char genre[50]; // Comedy
//	char how_long_known[50]; //1) justMet 2) lessThanAYear 3) moreThanAyear
//	char where_met[50]; //1) Family 2) studiedTogether 3) Work
//	char villain_target[300];
//	char plot_line[1000];
//	villainTrait traits[3]; // villain will always have 3 traits
//}Comedy_villain;
//
//typedef struct {
//	char name[50];
//	char is_realistic[50]; // no
//	char genre[50]; //fantasy
//	char meeting_place[50]; //1) enemy_captivity 2) Battlefield
//	char same_side[50]; //1) yes 2) no
//	char how_long_sience_than[50]; //1) justMet 2) lessThanAweek 3) moreThanAWeek 4) moreThanAYear
//	char villain_target[300];
//	char plot_line[1000];
//	villainTrait traits[3]; // villain will always have 3 traits
//}Fantasy_villain1;
//
//typedef struct {
//	char name[50];
//	char is_realistic[50];  // no
//	char genre[50]; //fantasy
//	char meeting_place[50]; //3) canteen
//	char crew_member[50]; //1) yes 2) no
//	char villain_target[300];
//	char plot_line[1000];
//	villainTrait traits[3]; // villain will always have 3 traits
//}Fantasy_villain2;
//
//typedef struct {
//	char name[50];
//	char is_realistic[50];  // no
//	char genre[50]; //1) Drama 2) Comedy
//	char meeting_place[50]; //1) enemy_captivity 2) Battlefield
//	char same_side[50]; //1) yes 2) no
//	char how_long_sience_than[50]; //1) justMet 2) lessThanAweek 3) moreThanAWeek 4) moreThanAYear
//	char villain_target[300];
//	char plot_line[1000];
//	villainTrait traits[3]; // villain will always have 3 traits
//}Scifi_villain1;
//
//typedef struct {
//	char name[50];
//	char is_realistic[50]; // no
//	char genre[50]; //1) Drama 2) Comedy
//	char meeting_place[50]; //3) canteen
//	char crew_member[50]; //1) yes 2) no
//	char villain_target[300];
//	char plot_line[1000];
//	villainTrait traits[3]; // villain will always have 3 traits
//}Scifi_villain2;
//
//typedef struct {
//	char name[50];
//	char is_realistic[50];  // no
//	char genre[50]; //1) Drama 2) Comedy
//	char did_they_meet[50]; //1) yes
//	char where[50]; //1) canteen
//	char crew_member[50]; //1) yes 2) no
//	char villain_target[300];
//	char plot_line[1000];
//	villainTrait traits[3]; // villain will always have 3 traits
//}Thriller_villain1;
//
//typedef struct {
//	char name[50];
//	char is_realistic[50];  // no
//	char genre[50]; //1) Drama 2) Comedy
//	char did_they_meet[50]; //1) yes
//	char where[50]; //2) investigationOffice
//	char hero_duty[50]; //1) investigator 2) murderer 3) victim 4) uninvolved
//	char villain_target[300];
//	char plot_line[1000];
//	villainTrait traits[3]; // villain will always have 3 traits
//}Thriller_villain2;
//
//typedef struct {
//	char name[50];
//	char is_realistic[50];  // no
//	char genre[50]; //1) Drama 2) Comedy
//	char did_they_meet[50]; //2) no
//	char hero_duty[50]; //1) investigator 2) murderer 3) victim 4) uninvolved
//	char villain_target[300];
//	char plot_line[1000];
//	villainTrait traits[3]; // villain will always have 3 traits
//}Thriller_villain3;

typedef enum {
	DRAMA,
	COMEDY,
	FANTASY1,
	FANTASY2,
	SCIFI1,
	SCIFI2,
	THRILLER1,
	THRILLER2,
	THRILLER3
} VillainType;

#endif 
#pragma once