#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char storyName[256];
    FILE* file;
    bool isRealistic;

    while (1) {
        printf("What's your story's name? ");
        if (fgets(storyName, sizeof(storyName), stdin) == NULL) {
            printf("Error reading input. Please try again.\n");
            continue;
        }
        // Remove the newline character from the input
        storyName[strcspn(storyName, "\n")] = 0;

        // Append .txt to the story name
        char fileName[260];
        if (sprintf_s(fileName, sizeof(fileName), "%s.txt", storyName) == -1) {
            printf("File name is too long. Please try again.\n");
            continue;
        }

        // Check if the file already exists
        if (fopen_s(&file, fileName, "r") == 0) {
            // File exists, so prompt for a different name
            fclose(file);
            printf("A story with the name '%s' already exists. Please choose a different name.\n", storyName);
        }
        else {
            // File doesn't exist, create the new file
            if (fopen_s(&file, fileName, "w") != 0) {
                printf("Error creating the file. Please try again.\n");
                return 1;
            }

            // Ask if the story is realistic or fictional
            char choice[10];
            while (1) {
                printf("Is your story realistic or fictional? (Enter R for realistic, F for fictional): ");
                if (fgets(choice, sizeof(choice), stdin) == NULL) {
                    printf("Error reading input. Please try again.\n");
                    continue;
                }
                choice[strcspn(choice, "\n")] = 0;
                if (strcmp(choice, "R") == 0 || strcmp(choice, "r") == 0) {
                    isRealistic = true;
                    break;
                }
                else if (strcmp(choice, "F") == 0 || strcmp(choice, "f") == 0) {
                    isRealistic = false;
                    break;
                }
                else {
                    printf("Invalid choice. Please enter R for realistic or F for fictional.\n");
                }
            }

            // Print confirmation message
            printf("Successfully created the story file: %s\n", fileName);
            printf("Your story is %s.\n", isRealistic ? "realistic" : "fictional");
            fclose(file);
            break;
        }
    }
    return 0;
}