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

enum {
    MIN_PLAYERS = 2,
    MAX_PLAYERS = 4
};

void play_match_mode() {
    // Get the number of players from the user
    int num_players;
    fscl_console_in_valid_input("Enter the number of players (2 to 4): ", &num_players);

    // Validate the number of players
    if (num_players < MIN_PLAYERS || num_players > MAX_PLAYERS) {
        fscl_console_out_color("light_red", "Invalid number of players. Please choose between 2 and 4.\n");
        return;
    }

    // Get the number of human players from the user
    int num_human_players;
    fscl_console_in_valid_input("Enter the number of human players (0 to 4): ", &num_human_players);

    // Validate the number of human players
    if (num_human_players < 0 || num_human_players > num_players) {
        fscl_console_out_color("light_red", "Invalid number of human players. Please choose between 0 and the total number of players.\n");
        return;
    }

    // Create an array to store players
    FishPlayer players[MAX_PLAYERS];

    // Create an array to store the scoreboard
    ScoreBoard scoreboard;
    scoreboard_init(&scoreboard);

    // Initialize players for the match using utility function
    match_initialize_players(players, num_human_players, num_players);

    // Number of rounds to simulate
    int num_rounds = 3; // Adjust as needed

    for (int round = 1; round <= num_rounds; round++) {
        fscl_console_out_color("light_cyan", "===== ROUND %d =====\n", round);

        // Play a round using the utility function
        match_play_round(players, num_players, &scoreboard);
    }

    // Save the final scoreboard using the utility function
    match_save_final_scoreboard(&scoreboard);
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
    // Attempt to open the file "data.txt" in read-only mode
    char mode_choice[20];
    do {
        fscl_console_out_color("light_cyan", "Choose a mode:\n");
        fscl_console_out_color("light_cyan", "match: play a quick match\n");
        fscl_console_out_color("light_cyan", "story: play story mode\n");
        fscl_console_out_color("light_cyan", "score: view the scoreboard\n");
        fscl_console_out_color("light_cyan", "exit : swim away from game\n");
        fscl_console_in_get_line(mode_choice);

        if (strcmp(mode_choice, "match") == 0) {
            play_match_mode();
        } else if (strcmp(mode_choice, "story") == 0) {
            play_story_mode();
        } else if (strcmp(mode_choice, "score") == 0) {
            view_scoreboard(scoreboard);
        } else if (strcmp(mode_choice, "exit") == 0) {
            fscl_console_out_color("reset", "Goodbye!\n");
        } else {
            fscl_console_out_color("light_red", "Invalid choice. Try again.\n");
        }
    } while (strcmp(mode_choice, "0") != 0);

    return EXIT_SUCCESS;
} // end of func
