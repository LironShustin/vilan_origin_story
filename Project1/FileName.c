#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    char role[30];
    char traits[100];
    char backstory[200];
    char motivation[100];
} Villain;

void generateVillain(Villain* v, const char* role) {
    const char* names[] = { "Malrik", "Velora", "Drex", "Nerissa", "Karn", "Zira" };
    const char* traits[] = {
        "Manipulative, intelligent, vengeful",
        "Charismatic, deceptive, cold-hearted",
        "Ruthless, disciplined, loyal to a cause",
        "Ambitious, bitter, strategic",
        "Cunning, brutal, patient"
    };
    const char* backstories[] = {
        "Was betrayed by a close friend and swore revenge.",
        "Once a noble hero, now fallen from grace.",
        "Raised in the shadows, never knew love or justice.",
        "Lost their family in a war caused by the protagonist.",
        "Exiled from society for something they didn't do."
    };
    const char* motivations[] = {
        "Wants to prove they're better than the hero.",
        "Seeks justice for a forgotten crime.",
        "Wants to reshape the world through force.",
        "Acts to protect something they believe in.",
        "Fights because they believe the hero is wrong."
    };

    strcpy(v->name, names[rand() % 6]);
    strcpy(v->role, role);
    strcpy(v->traits, traits[rand() % 5]);
    strcpy(v->backstory, backstories[rand() % 5]);
    strcpy(v->motivation, motivations[rand() % 5]);
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void printWelcome() {
    printf("Welcome to the Villain Origin Story System!\n");
    printf("This system helps writers create compelling villain characters.\n\n");
}

char getYesOrNo(const char* question) {
    char answer;
    do {
        printf("%s (Y/N): ", question);
        scanf_s(" %c", &answer);
        clearInputBuffer();
        answer = toupper(answer);
    } while (answer != 'Y' && answer != 'N');
    return answer;
}

int getChoice(const char* question, const char* options[], int numOptions) {
    int choice = -1;
    printf("%s\n", question);
    for (int i = 0; i < numOptions; i++) {
        printf("  %d) %s\n", i + 1, options[i]);
    }
    do {
        printf("Enter choice number: ");
        scanf_s("%d", &choice);
        clearInputBuffer();
    } while (choice < 1 || choice > numOptions);
    return choice;
}

void runRealisticFlow() {
    const char* styles[] = { "Drama", "Comedy" };
    const char* durations[] = { "Just met", "Less than a year", "More than a year" };
    const char* meetingPlaces[] = { "Family", "Educational setting", "Workplace" };

    int style = getChoice("What is the story style?", styles, 2);
    int duration = getChoice("How long have you known each other?", durations, 3);
    int meeting = getChoice("Where did you first meet?", meetingPlaces, 3);

    printf("\nAnalyzing relationship...\n");

    // Simple logic for demonstration
    if (duration == 3 && meeting == 3) {
        printf("The rivalry has already begun!\n");
    }
    else {
        printf("The rivalry is building up...\n");
    }

    // Determine villain type
    const char* villainTypes[] = { "Main Villain", "Secondary Villain", "Hidden Villain" };
    Villain myVillain;
    generateVillain(&myVillain, villainTypes[rand() % 3]);

    printf("\n--- VILLAIN PROFILE ---\n");
    printf("Name: %s\n", myVillain.name);
    printf("Role: %s\n", myVillain.role);
    printf("Traits: %s\n", myVillain.traits);
    printf("Backstory: %s\n", myVillain.backstory);
    printf("Motivation: %s\n", myVillain.motivation);
    printf("------------------------\n\n");
}

void runFictionalFlow() {
    const char* styles[] = { "Thriller", "Science Fiction", "Fantasy" };
    int style = getChoice("Choose the genre:", styles, 3);

    if (style == 2 || style == 3) { // Sci-Fi or Fantasy
        const char* places[] = { "Battlefield", "Enemy captivity", "Cantina" };
        int meeting = getChoice("Where did you meet?", places, 3);

        if (meeting == 1 || meeting == 2) {
            const char* sides[] = { "Yes", "No" };
            int sameSide = getChoice("Were you on the same side?", sides, 2);
            const char* timePassed[] = { "Less than a week", "More than a week", "More than a year" };
            int time = getChoice("How much time has passed since then?", timePassed, 3);

            printf("\nAnalyzing relationship...\n");
            if (sameSide == 2 || time == 3) {
                printf("The rivalry has already begun!\n");
            }
            else {
                printf("The rivalry is forming...\n");
            }
        }
        else { // Cantina
            const char* crew[] = { "Yes", "No" };
            int isCrew = getChoice("Was one of you part of the staff there?", crew, 2);

            printf("\nAnalyzing relationship...\n");
            if (isCrew == 1) {
                printf("The villain is hiding in plain sight.\n");
            }
            else {
                printf("The rivalry is forming...\n");
            }
        }
    }
    else if (style == 1) { // Thriller
        const char* metOptions[] = { "Yes", "No" };
        int met = getChoice("Have you met before?", metOptions, 2);

        if (met == 1) {
            const char* where[] = { "Detective office", "Cantina" };
            int whereMet = getChoice("Where did you meet?", where, 2);
            if (whereMet == 2) {
                const char* crew[] = { "Yes", "No" };
                int isCrew = getChoice("Was one of you part of the staff there?", crew, 2);
                printf("\nAnalyzing relationship...\n");
                if (isCrew == 1) {
                    printf("The villain is undercover.\n");
                }
                else {
                    printf("The rivalry is forming...\n");
                }
            }
            else { // Detective office
                const char* roles[] = { "Detective", "Killer", "Victim", "Uninvolved" };
                int role = getChoice("What is the protagonist's role?", roles, 4);
                printf("\nAnalyzing relationship...\n");
                if (role == 2) {
                    printf("The rivalry is intense!\n");
                }
                else {
                    printf("The villain is watching from the shadows...\n");
                }
            }
        }
        else {
            const char* roles[] = { "Detective", "Killer", "Victim", "Uninvolved" };
            int role = getChoice("What is the protagonist's role?", roles, 4);
            printf("\nAnalyzing relationship...\n");
            if (role == 1 || role == 2) {
                printf("The rivalry is inevitable.\n");
            }
            else {
                printf("A hidden threat is rising...\n");
            }
        }
    }

    // Determine villain type
    int type = rand() % 3;
    const char* villainTypes[] = { "Main Villain", "Secondary Villain", "Hidden Villain" };
    printf("Generated Villain: %s\n\n", villainTypes[type]);
}

int main() {
    srand((unsigned int)time(NULL));
    char continueCreation = 'Y';

    printWelcome();

    while (continueCreation == 'Y') {
        const char* worldTypes[] = { "Realistic", "Fictional" };
        int worldChoice = getChoice("Is your story world realistic or fictional?", worldTypes, 2);

        if (worldChoice == 1) {
            runRealisticFlow();
        }
        else {
            runFictionalFlow();
        }

        continueCreation = getYesOrNo("Would you like to develop another villain?");
        printf("\n");
    }

    printf("Thank you for using the Villain Origin Story System. Happy writing!\n");
    return 0;
}
