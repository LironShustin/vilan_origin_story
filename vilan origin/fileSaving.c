#include "fileSaving.h"

void create_answers_file(char* file_name) {
    char storyName[256];
    char fileName[260];
    FILE* file;
    bool isRealistic;

    while (1) {
        // Prompt for the story name
        printf("What's your story's name? ");
        if (scanf_s("%255[^\n]%*c", storyName, (unsigned int)sizeof(storyName)) != 1) {
            printf("Error reading input. Please try again.\n");
            while (getchar() != '\n');  // Clear the input buffer
            continue;
        }
        storyName[sizeof(storyName) - 1] = '\0'; // Ensure null-termination
        // Append .txt to the story name
        if (strcpy_s(fileName, sizeof(fileName), storyName) != 0 || strcat_s(fileName, sizeof(fileName), ".txt") != 0) {
            printf("File name is too long or invalid. Please try again.\n");
            continue;
        }
        // Check if the file already exists
        if (fopen_s(&file, fileName, "r") == 0) {
            fclose(file);
            printf("A story with the name '%s' already exists. Please choose a different name.\n", storyName);
            continue;
        }
        // Create the new file
        if (fopen_s(&file, fileName, "w") != 0) {
            printf("Error creating the file. Please try again.\n");
            continue;
        }
        // Save the story name
        fprintf(file, "Story Name: %s\n", storyName);
        // Copy the file name to the provided buffer
        if (strcpy_s(file_name, 260, fileName) != 0) {
            printf("Error copying the file name.\n");
            fclose(file);
            continue;
        }
        break;
    }
    printf("Successfully created the answers file: %s\n", fileName);
    fclose(file);
}
