#ifndef Structs_And_Enums_H
#define Structs_And_Enums_H
#define MAX_LINE_LEN 1024
#define True 1
#define False 0
typedef int BOOL;

typedef struct {
    char title[MAX_LINE_LEN];
    char author[MAX_LINE_LEN];
    char date[MAX_LINE_LEN];
    char line1[MAX_LINE_LEN];
    char line2[MAX_LINE_LEN];
    char line3[MAX_LINE_LEN];
    char line4[MAX_LINE_LEN];
    char line5[MAX_LINE_LEN];
} Output_Vilain_Struct; // need to zeero out all feilds before using



#endif 
#pragma once