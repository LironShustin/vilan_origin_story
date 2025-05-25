#include "fileSaving.h"
#include "design.h"

void create_answers_file(char* file_name) {
    char storyName[256];
    char fileName[260];
    FILE* file;
    //bool isRealistic;

    while (1) {
        // Prompt for the story name
        print_colored("What's your story's name? ", YELLOW);
        if (scanf_s("%255[^\n]%*c", storyName, (unsigned int)sizeof(storyName)) != 1) {
            print_colored("Error reading input. Please try again.\n", RED);
            while (getchar() != '\n');  // Clear the input buffer
            continue;
        }
        storyName[sizeof(storyName) - 1] = '\0'; // Ensure null-termination
        // Append .txt to the story name
        if (strcpy_s(fileName, sizeof(fileName), storyName) != 0 || strcat_s(fileName, sizeof(fileName), ".txt") != 0) {
            print_colored("File name is too long or invalid. Please try again.\n", RED);
            continue;
        }
        // Check if the file already exists
        if (fopen_s(&file, fileName, "r") == 0) {
            fclose(file);
            print_colored("A story with the name", RED);
            printf(" '%s' ", storyName);
            print_colored("already exists.Please choose a different name.\n", RED);
            continue;
        }
        // Create the new file
        if (fopen_s(&file, fileName, "w") != 0) {
            print_colored("Error creating the file. Please try again.\n", RED);
            continue;
        }
        // Save the story name
        fprintf(file, "Story Name: %s\n", storyName);
        // Copy the file name to the provided buffer
        if (strcpy_s(file_name, 260, fileName) != 0) {
            print_colored("Error copying the file name.\n", RED);
            fclose(file);
            continue;
        }
        break;
    }
    print_colored("Successfully created the answers file:", GREEN);
    printf(" %s\n", fileName);
    printf(" %s\n", file_name);
    fclose(file);
}

AllStructs* allocate_all_structs() {
    AllStructs* allstructs = (AllStructs*)malloc(sizeof(AllStructs));
    if (!allstructs) return NULL;
    allstructs->drama_villain = (Drama_villain*)calloc(1, sizeof(Drama_villain));
    allstructs->comedy_villain = (Comedy_villain*)calloc(1, sizeof(Comedy_villain));
    allstructs->fantasy_villain1 = (Fantasy_villain1*)calloc(1, sizeof(Fantasy_villain1));
    allstructs->fantasy_villain2 = (Fantasy_villain2*)calloc(1, sizeof(Fantasy_villain2));
    allstructs->scifi_villain1 = (Scifi_villain1*)calloc(1, sizeof(Scifi_villain1));
    allstructs->scifi_villain2 = (Scifi_villain2*)calloc(1, sizeof(Scifi_villain2));
    allstructs->thriller_villain1 = (Thriller_villain1*)calloc(1, sizeof(Thriller_villain1));
    allstructs->thriller_villain2 = (Thriller_villain2*)calloc(1, sizeof(Thriller_villain2));
    allstructs->thriller_villain3 = (Thriller_villain3*)calloc(1, sizeof(Thriller_villain3));
    allstructs->output = (Output_Vilain_Struct*)calloc(1, sizeof(Output_Vilain_Struct));
    // Optionally check for allocation failures for each pointer
    return allstructs;
}

void free_all_structs(AllStructs* s) {
    if (!s) return;
    free(s->drama_villain);
    free(s->comedy_villain);
    free(s->fantasy_villain1);
    free(s->fantasy_villain2);
    free(s->scifi_villain1);
    free(s->scifi_villain2);
    free(s->thriller_villain1);
    free(s->thriller_villain2);
    free(s->thriller_villain3);
    free(s->output);
    free(s);
}