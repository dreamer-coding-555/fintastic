/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include "app.h"

void play_match_mode() {
    // Number of rounds to simulate
    int num_rounds = 3; // Adjust as needed

    // Create an array to store players
    FishPlayer players[MAX_PLAYERS];

    // Create an array to store the scoreboard
    ScoreBoard *scoreboard = scoreboard_create();

    // Create random lamps for the match
    match_randomize_lamps(players);

    for (int round = 1; round <= num_rounds; round++) {
        display_round(round);
        display_weapon_menu();

        // Simulate a game round for each player
        for (int i = 0; i < MAX_PLAYERS; i++) {
            int weapon_choice;
            fscl_console_in_valid_input("Choose your weapon (1-3): ", &weapon_choice);

            // Set player move based on the weapon choice
            switch (weapon_choice) {
                case 1:
                    player_set_move(&players[i], "Rock", ROCK);
                    break;
                case 2:
                    player_set_move(&players[i], "Paper", PAPER);
                    break;
                case 3:
                    player_set_move(&players[i], "Scissors", SCISSOR);
                    break;
                default:
                    display_error();
                    return;
            }
        }

        // Display player moves
        display_player_moves(players, MAX_PLAYERS);

        // Determine the game outcome
        determine_outcomes(players, MAX_PLAYERS, scoreboard);

        // Display the result
        display_result(players, MAX_PLAYERS, scoreboard);

        // Display the scoreboard at the end of each round
        scoreboard_display(scoreboard);
    }

    // Save the final scoreboard to a file
    cstream stream;
    if (fscl_stream_open(&stream, "scoreboard.txt", "w")) {
        scoreboard_save_to_file(&stream, scoreboard);
        fscl_stream_close(&stream);
    }

    // Clean up the scoreboard
    scoreboard_destroy(scoreboard);
}

void play_story_mode() {
    // Your story mode logic here
    fscl_console_out_color("light_blue", "Welcome to the story mode! Implement your story here.\n");
    // Add your story-related functionality
}

// Function to handle the view scoreboard option
void view_scoreboard(ScoreBoard *scoreboard) {
    fscl_console_clear();
    fscl_console_out_color("light_cyan", "===== SCOREBOARD =====\n");
    scoreboard_display(scoreboard);
    fscl_console_out_color("light_cyan", "======================\n");
    fscl_console_pause();
}

// The run_app function is designed to read data from a file named "data.txt"
// using a custom stream implementation (cstream).
// Returns EXIT_SUCCESS if the file is read successfully; otherwise, the
// behavior is undefined.
int run_app(int argc, char **argv) {
    display_intro();

    char mode_choice[20];
    do {
        display_start_menu();
        fscl_console_in_get_line(mode_choice);

        if (strcmp(mode_choice, "match") == 0) {
            play_match_mode();
        } else if (strcmp(mode_choice, "story") == 0) {
            play_story_mode();
        } else if (strcmp(mode_choice, "score") == 0) {
            view_scoreboard(scoreboard);
        } else if (strcmp(mode_choice, "exit") == 0) {
            display_goodbye();
        } else {
            display_error();
        }
    } while (strcmp(mode_choice, "0") != 0);

    return EXIT_SUCCESS;
} // end of func
