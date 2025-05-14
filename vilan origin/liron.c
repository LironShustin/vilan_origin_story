#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "liron.h"

void questions(int* genre_choice, char* file_name[260]) {
    char storyName[256];
    FILE* file;
    bool isRealistic;
    int genreChoice;
    
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
            }

            // Ensure the file pointer is valid before using it
            if (file != NULL) {
				// save the story name
                fprintf(file, "Story Name: %s\n", storyName);
            }
            else {
                printf("Error: File pointer is NULL. Unable to write to the file.\n");
            }

			*file_name = fileName;
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
                    if (file != NULL) {
                        fprintf(file, "Type: Realistic\n");
                    }
                    else {
                        printf("Error: File pointer is NULL. Unable to write to the file.\n");
                    }

                    break;
                }
                else if (strcmp(choice, "F") == 0 || strcmp(choice, "f") == 0) {
                    isRealistic = false;
                    if (file != NULL) {
                        fprintf(file, "Type: Fictional\n");
                    }
                    else {
                        printf("Error: File pointer is NULL. Unable to write to the file.\n");
                    }
                    break;
                }
                else {
                    printf("Invalid choice. Please enter R for realistic or F for fictional.\n");
                }
            }

            // Ask for the story genre based on realism
            while (1) {
                if (isRealistic) {
                    printf("Choose a genre for your realistic story:\n");
                    printf("1) Drama\n");
                    printf("2) Comedy\n");
                    printf("Enter the number of your choice: ");
                    if (scanf_s("%d", &genreChoice) != 1 || genreChoice < 1 || genreChoice > 2) {
                        printf("Invalid choice. Please enter 1 or 2.\n");
                        while (getchar() != '\n'); // Clear the input buffer
                    }
                    else {
                        const char* genres[] = { "", "Drama", "Comedy" };
                        if (file != NULL) {
                            *genre_choice = genreChoice;
                            fprintf(file, "Genre: %s\n", genres[genreChoice]);
                        }
                        else {
                            printf("Error: File pointer is NULL. Unable to write to the file.\n");
                        }

                        // Ask about the relationship duration for realistic genres
                        int relationChoice;
                        while (1) {
                            printf("How long do the hero and the antagonist know each other?\n");
                            printf("1) Just met\n");
                            printf("2) Less than a year\n");
                            printf("3) More than a year\n");
                            printf("Enter the number of your choice: ");
                            if (scanf_s("%d", &relationChoice) != 1 || relationChoice < 1 || relationChoice > 3) {
                                printf("Invalid choice. Please enter a number between 1 and 3.\n");
                                while (getchar() != '\n'); // Clear the input buffer
                            }
                            else {
                                const char* relations[] = { "", "Just met", "Less than a year", "More than a year" };
                                if (file != NULL) {
                                    fprintf(file, "Relationship Duration: %s\n", relations[relationChoice]);
                                }
                                else {
                                    printf("Error: File pointer is NULL. Unable to write to the file.\n");
                                }                                break;
                            }
                        }

                        // Ask where they first met
                        int meetingPlaceChoice;
                        while (1) {
                            printf("Where did they first meet?\n");
                            printf("1) At work\n");
                            printf("2) At university\n");
                            printf("3) In childhood\n");
                            printf("4) They are family members\n");
                            printf("Enter the number of your choice: ");
                            if (scanf_s("%d", &meetingPlaceChoice) != 1 || meetingPlaceChoice < 1 || meetingPlaceChoice > 4) {
                                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                                while (getchar() != '\n'); // Clear the input buffer
                            }
                            else {
                                const char* meetingPlaces[] = { "", "At work", "At university", "In childhood", "You are family members" };
                                if (file != NULL) {
                                    fprintf(file, "First Meeting Place: %s\n", meetingPlaces[meetingPlaceChoice]);
                                }
                                else {
                                    printf("Error: File pointer is NULL. Unable to write to the file.\n");
                                }                                break;
                            }
                        }
                        break;
                    }
                }
                else {
                    printf("Choose a genre for your fictional story:\n");
                    printf("3) Thriller\n");
                    printf("4) Fantasy\n");
                    printf("5) Science Fiction\n");
                    printf("Enter the number of your choice: ");
                    if (scanf_s("%d", &genreChoice) != 1 || genreChoice < 3 || genreChoice > 5) {
                        printf("Invalid choice. Please enter a number between 3 and 5.\n");
                        while (getchar() != '\n'); // Clear the input buffer
                    }
                    else {
                        const char* genres[] = { "", "", "", "Thriller", "Fantasy", "Science Fiction" };
                        if (file != NULL) {
                            fprintf(file, "Genre: %s\n", genres[genreChoice]);
                        }
                        else {
                            printf("Error: File pointer is NULL. Unable to write to the file.\n");
                        }
                        break;
                    }
                }
            }

            // Print confirmation message
            printf("Successfully created the story file: %s\n", fileName);
            if (file != NULL) {
                fclose(file);
            }
            break;
        }
    }
}