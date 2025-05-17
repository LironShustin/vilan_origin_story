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
    fclose(file);
}
