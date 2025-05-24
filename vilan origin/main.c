#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fileSaving.h"
#include "questions.h"
#include "editingFiles.h"
#include "Structs&Enums.h"
#include "fileReading.h"
#include "fileComparison.h"
#include "general.h"

int main() {
    srand((unsigned int)time(NULL)); // Seed the RNG
    //Drama_villain drama_villain = { 0 };
    //Comedy_villain comedy_villain = { 0 };
    Output_Vilain_Struct test = { 0 };
    char answers_file[260];
    BOOL realistic = True;
    int match_lines[60] = { 0 };
    int match_count = 1;
    int n;
    int r;
    create_answers_file(answers_file);
    is_realistic(&realistic, answers_file);
    genre(realistic, answers_file);
    clear_console();
    char genre[30] = { 0 };
    int pull_line = 3;
    int genre_size = sizeof(genre);
    pull_line_from_file(answers_file, pull_line, genre, genre_size); // for genre pull line is 3 
    if (realistic) {// drama and comedy have the same questions
        how_long_you_met(answers_file, genre);
        clear_console();
        first_meeting_place(answers_file, genre);
        if (strcmp(genre, "Drama") == 0) {
            n = 2; //since theres 2 questions after genre
            compare_structs("drama_database.txt", n, answers_file, match_lines, &match_count);
            r = (rand() % match_count);
            analyzing_encounter_parameter();
            write_lines_to_struct("drama_database.txt", match_lines[r], n, &test);
        }
        else if (strcmp(genre, "Comedy") == 0) {
            n = 2; //since theres 2 questions after genre
            compare_structs("comedy_database.txt", n, answers_file, match_lines, &match_count);
            r = (rand() % match_count);
            analyzing_encounter_parameter();
            write_lines_to_struct("comedy_database.txt", match_lines[r], n, &test);
        }
    }
    else {// unrealistic
        if (strcmp(genre, "Thriller") == 0) {
            thriller_meeting_status(answers_file);
            char status_answer[30] = { 0 };
            pull_line = 4; //meeting status is written in line 4
            pull_line_from_file(answers_file, pull_line, status_answer, sizeof(status_answer));
            if (strcmp(status_answer, "Yes") == 0) {
                char meeting_answer[30] = { 0 };
                thriller_meeting_place(answers_file);
                pull_line = 5; //meeting place is written in line 5
                pull_line_from_file(answers_file, pull_line, meeting_answer, sizeof(meeting_answer));
                if (strcmp(meeting_answer, "Investigation Office") == 0) {
                    thriller_hero_duty(answers_file);
                    n = 3; //since theres 3 questions after genre
                    compare_structs("Thriller_have_met_database.txt", n, answers_file, match_lines, &match_count);
                    r = (rand() % match_count);
                    analyzing_encounter_parameter();
                    write_lines_to_struct("Thriller_have_met_database.txt", match_lines[r], n, &test);
                }
                else if (strcmp(meeting_answer, "Canteen") == 0) {
                    was_one_crew_member(answers_file, genre);
                    n = 3; //since theres 3 questions after genre
                    compare_structs("Thriller_have_met_database.txt", n, answers_file, match_lines, &match_count);
                    r = (rand() % match_count);
                    analyzing_encounter_parameter();
                    write_lines_to_struct("Thriller_have_met_database.txt", match_lines[r], n, &test);
                }
            }
            else if (strcmp(status_answer, "No") == 0) {
                thriller_hero_duty(answers_file);
                n = 2; //since theres 2 questions after genre
                compare_structs("Thriller_havent_met_database.txt", n, answers_file, match_lines, &match_count);
                r = (rand() % match_count);
                analyzing_encounter_parameter();
                write_lines_to_struct("Thriller_havent_met_database.txt", match_lines[r], n, &test);
            }
        }
        else if (strcmp(genre, "Science fiction") == 0) {
            char meeting_place[30] = { 0 };
            sci_fi_or_fantasy_meeting_place(answers_file,genre);
            pull_line = 4; // meeting place is written in line 4
            pull_line_from_file(answers_file, pull_line, meeting_place, sizeof(meeting_place));
            if (strcmp(meeting_place, "Enemy captivity") == 0 || strcmp(meeting_place, "Battlefield") == 0) {
                hero_villain_same_side(answers_file,genre);
                how_long_since_meeting(answers_file,genre);
                n = 3; //since theres 3 questions after genre
                compare_structs("Science_fiction_captivity_battlefield_database.txt", n, answers_file, match_lines, &match_count);
                r = (rand() % match_count);
                analyzing_encounter_parameter();
                write_lines_to_struct("Science_fiction_captivity_battlefield_database.txt", match_lines[r], n, &test);
            }
            else if (strcmp(meeting_place, "Canteen") == 0) {
                was_one_crew_member(answers_file,genre);
                n = 2; //since theres 2 questions after genre
                compare_structs("Science_fiction_canteen_databaset.txt", n, answers_file, match_lines, &match_count);
                r = (rand() % match_count);
                analyzing_encounter_parameter();
                write_lines_to_struct("Science_fiction_canteen_databaset.txt", match_lines[r], n, &test);
            }
        }
        else if (strcmp(genre, "Fantasy") == 0) {
            char meeting_place[30] = { 0 };
            sci_fi_or_fantasy_meeting_place(answers_file, genre);
            pull_line = 4; // meeting place is written in line 4
            pull_line_from_file(answers_file, pull_line, meeting_place, sizeof(meeting_place));
            if (strcmp(meeting_place, "Enemy captivity") == 0 || strcmp(meeting_place, "Battlefield") == 0) {
                hero_villain_same_side(answers_file, genre);
                how_long_since_meeting(answers_file, genre);
                n = 3; //since theres 3 questions after genre
                compare_structs("Fantasy_captivity_battlefield_database.txt", n, answers_file, match_lines, &match_count);
                r = (rand() % match_count);
                analyzing_encounter_parameter();
                write_lines_to_struct("Fantasy_captivity_battlefield_database.txt", match_lines[r], n, &test);
            }
            else if (strcmp(meeting_place, "Canteen") == 0) {
                was_one_crew_member(answers_file, genre);
                n = 2; //since theres 2 questions after genre
                compare_structs("Fantasy_Canteen_database.txt", n, answers_file, match_lines, &match_count);
                r = (rand() % match_count);
                analyzing_encounter_parameter();
                write_lines_to_struct("Fantasy_Canteen_database.txt", match_lines[r], n, &test);
            }
        }   
    }
    return 0;
}