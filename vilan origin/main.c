#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "liron.h"

// Function to randomly select an antagonist and plot based on the current file answers
void generateAntagonistAndPlot(const char* genreFile, const char* storyFile) {
    FILE* dbFile = fopen(genreFile, "r");
    if (!dbFile) {
        printf("Error opening the database file: %s\n", genreFile);
        return;
    }

    // Read the current story details
    char type[50], duration[50], place[50];
    FILE* story = fopen(storyFile, "r");
    if (!story) {
        printf("Error opening the story file: %s\n", storyFile);
        fclose(dbFile);
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), story)) {
        if (strncmp(line, "Type: ", 6) == 0) {
            strcpy_s(type, sizeof(type), line + 6);
            type[strcspn(type, "\n")] = 0;
        }
        else if (strncmp(line, "Relationship Duration: ", 23) == 0) {
            strcpy_s(duration, sizeof(duration), line + 23);
            duration[strcspn(duration, "\n")] = 0;
        }
        else if (strncmp(line, "First Meeting Place: ", 22) == 0) {
            strcpy_s(place, sizeof(place), line + 22);
            place[strcspn(place, "\n")] = 0;
        }
    }
    fclose(story);

    // Prepare for random selection
    srand((unsigned int)time(NULL));
    int matchCount = 0;
    char matchedAntagonists[10][256];
    char matchedPlots[10][256];
    char dbLine[256];
    while (fgets(dbLine, sizeof(dbLine), dbFile)) {
        char dbType[50], dbDuration[50], dbPlace[50], dbAntagonist[256], dbPlot[256];
        if (sscanf_s(dbLine, "Type: %49[^\n]", dbType, (unsigned)_countof(dbType)) == 1 &&
            fgets(dbLine, sizeof(dbLine), dbFile) && sscanf_s(dbLine, "Duration: %49[^\n]", dbDuration, (unsigned)_countof(dbDuration)) == 1 &&
            fgets(dbLine, sizeof(dbLine), dbFile) && sscanf_s(dbLine, "Place: %49[^\n]", dbPlace, (unsigned)_countof(dbPlace)) == 1 &&
            fgets(dbLine, sizeof(dbLine), dbFile) && sscanf_s(dbLine, "Antagonist: %[^\n]", dbAntagonist, (unsigned)_countof(dbAntagonist)) == 1 &&
            fgets(dbLine, sizeof(dbLine), dbFile) && sscanf_s(dbLine, "Plot: %[^\n]", dbPlot, (unsigned)_countof(dbPlot)) == 1) {

            // Check if this entry matches the story details
            if (strcmp(type, dbType) == 0 && strcmp(duration, dbDuration) == 0 && strcmp(place, dbPlace) == 0) {
                strcpy_s(matchedAntagonists[matchCount], sizeof(matchedAntagonists[matchCount]), dbAntagonist);
                strcpy_s(matchedPlots[matchCount], sizeof(matchedPlots[matchCount]), dbPlot);
                matchCount++;
            }
        }
    }
    fclose(dbFile);

if (matchCount == 0) {
    printf("No matching antagonist and plot found in the database.\n");
    return;
}

// Pick a random match
int choice = rand() % matchCount;
printf("Antagonist: %s\n", matchedAntagonists[choice]);
printf("Plot: %s\n", matchedPlots[choice]);

// Ask to save the generated details
char saveChoice[10];
printf("Would you like to save this antagonist and plot to your story file? (Y/N): ");
if (fgets(saveChoice, sizeof(saveChoice), stdin) != NULL && (saveChoice[0] == 'Y' || saveChoice[0] == 'y')) {
    FILE* storyAppend = fopen(storyFile, "a");
    if (storyAppend) {
        fprintf(storyAppend, "Antagonist: %s\n", matchedAntagonists[choice]);
        fprintf(storyAppend, "Plot: %s\n", matchedPlots[choice]);
        fclose(storyAppend);
        printf("Antagonist and plot saved successfully.\n");
    }
    else {
        printf("Error saving antagonist and plot.\n");
    }
}
}

int main() {
    // Existing code...
    // After the story file creation, add the antagonist generator call
    char genreFile[260];
	int genreChoice = -1;
	char fileName[260];
	questions(&genreChoice, &fileName);
    if (genreChoice == 1) {
        strcpy_s(genreFile, sizeof(genreFile), "drama_database.txt");
    }
    else if (genreChoice == 2) {
        strcpy_s(genreFile, sizeof(genreFile), "comedy_database.txt");
    }
    generateAntagonistAndPlot(genreFile, fileName);
    return 0;
}