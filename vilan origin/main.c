#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "fileSaving.h"

//// Function to randomly select an antagonist and plot based on the current file answers
//void generateAntagonistAndPlot(const char* genre_file_name, const char* story_file_name) {
//    printf("Trying to open genre file: %s\n", genre_file_name);
//    FILE* db_file = NULL;
//    errno_t errdb = fopen_s(&db_file, genre_file_name, "r");
//    if (errdb != 0 || !db_file) {
//        printf("Error opening the database file: %s\n", genre_file_name);
//        return;
//    }
//
//    // Read the current story details
//    char type[50] = { 0 }, duration[50] = { 0 }, place[50] = { 0 }; // Initialize to ensure null-termination
//    FILE* story_file = NULL;
//    errno_t errs = fopen_s(&story_file, story_file_name, "r");
//    if (errs != 0 || !story_file) {
//        printf("Error opening the story file: %s\n", story_file_name);
//        fclose(db_file);
//        return;
//    }
//    char line[256];
//    while (fgets(line, sizeof(line), story_file)) {
//        if (strncmp(line, "Type: ", 6) == 0) {
//            strcpy_s(type, sizeof(type), line + 6);
//            type[strcspn(type, "\n")] = '\0'; // Ensure null-termination
//        }
//        else if (strncmp(line, "Relationship Duration: ", 23) == 0) {
//            strcpy_s(duration, sizeof(duration), line + 23);
//            duration[strcspn(duration, "\n")] = '\0'; // Ensure null-termination
//        }
//        else if (strncmp(line, "First Meeting Place: ", 22) == 0) {
//            strcpy_s(place, sizeof(place), line + 22);
//            place[strcspn(place, "\n")] = '\0'; // Ensure null-termination
//        }
//    }
//    fclose(story_file);
//
//    // Prepare for random selection
//    srand((unsigned int)time(NULL));
//    int matchCount = 0;
//    char matchedAntagonists[10][256];
//    char matchedPlots[10][256];
//    char dbLine[256];
//    while (fgets(dbLine, sizeof(dbLine), db_file)) {
//        char dbType[50] = { 0 }, dbDuration[50] = { 0 }, dbPlace[50] = { 0 }, dbAntagonist[256] = { 0 }, dbPlot[256] = { 0 };
//        if (sscanf_s(dbLine, "Type: %49[^\n]", dbType, (unsigned)_countof(dbType)) == 1 &&
//            fgets(dbLine, sizeof(dbLine), db_file) && sscanf_s(dbLine, "Duration: %49[^\n]", dbDuration, (unsigned)_countof(dbDuration)) == 1 &&
//            fgets(dbLine, sizeof(dbLine), db_file) && sscanf_s(dbLine, "Place: %49[^\n]", dbPlace, (unsigned)_countof(dbPlace)) == 1 &&
//            fgets(dbLine, sizeof(dbLine), db_file) && sscanf_s(dbLine, "Antagonist: %255[^\n]", dbAntagonist, (unsigned)_countof(dbAntagonist)) == 1 &&
//            fgets(dbLine, sizeof(dbLine), db_file) && sscanf_s(dbLine, "Plot: %255[^\n]", dbPlot, (unsigned)_countof(dbPlot)) == 1) {
//            // Ensure null-termination for safety
//            dbType[sizeof(dbType) - 1] = '\0';
//            dbDuration[sizeof(dbDuration) - 1] = '\0';
//            dbPlace[sizeof(dbPlace) - 1] = '\0';
//            dbAntagonist[sizeof(dbAntagonist) - 1] = '\0';
//            dbPlot[sizeof(dbPlot) - 1] = '\0';
//            // Check if this entry matches the story details
//            if (strcmp(type, dbType) == 0 && strcmp(duration, dbDuration) == 0 && strcmp(place, dbPlace) == 0) {
//                strcpy_s(matchedAntagonists[matchCount], sizeof(matchedAntagonists[matchCount]), dbAntagonist);
//                strcpy_s(matchedPlots[matchCount], sizeof(matchedPlots[matchCount]), dbPlot);
//                matchCount++;
//            }
//        }
//    }
//
//    fclose(db_file);
//
//    if (matchCount == 0) {
//        printf("No matching antagonist and plot found in the database.\n");
//        return;
//    }
//
//    // Pick a random match
//    int choice = rand() % matchCount;
//    printf("Antagonist: %s\n", matchedAntagonists[choice]);
//    printf("Plot: %s\n", matchedPlots[choice]);
//
//    // Ask to save the generated details
//    char saveChoice[10];
//    printf("Would you like to save this antagonist and plot to your story file? (Y/N): ");
//    if (fgets(saveChoice, sizeof(saveChoice), stdin) != NULL && (saveChoice[0] == 'Y' || saveChoice[0] == 'y')) {
//        FILE* storyAppend = fopen(story_file_name, "a");
//        if (storyAppend) {
//            fprintf(storyAppend, "Antagonist: %s\n", matchedAntagonists[choice]);
//            fprintf(storyAppend, "Plot: %s\n", matchedPlots[choice]);
//            fclose(storyAppend);
//            printf("Antagonist and plot saved successfully.\n");
//        }
//        else {
//            printf("Error saving antagonist and plot.\n");
//        }
//    }
//}

int main() {
	char answers_file[260];
	create_answers_file(answers_file);
}