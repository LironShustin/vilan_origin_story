#ifndef fileSaving_H
#define fileSaving_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Structs&Enums.h"

void create_answers_file(char* file_name);
AllStructs* allocate_all_structs();
void free_all_structs(AllStructs* s);

#endif 
#pragma once