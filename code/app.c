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

    // Your match mode logic here
    // For example, a simple rock-paper-scissors game between players

    // Create an array to store players
    FishPlayer players[MAX_PLAYERS];

    // Create human players
    for (int i = 0; i < num_human_players; i++) {
        char name[20];
        fscl_console_out("Enter name for Human Player %d: ", i + 1);
        fscl_console_in_get_line(name);
        players[i] = create_fish_player(name, get_user_input().move_type);
    }

    // Create AI players
    for (int i = num_human_players; i < num_players; i++) {
        char name[20];
        snprintf(name, sizeof(name), "AI Player %d", i + 1);
        players[i] = create_ai_fish_player(name);
    }

    // Simulate a game round for each player
    for (int i = 0; i < num_players; i++) {
        players[i].move = create_player_move(players[i].name, get_user_input().move_type);
    }

    // Determine the game outcome
    for (int i = 0; i < num_players; i++) {
        for (int j = i + 1; j < num_players; j++) {
            GameOutcome outcome = determine_outcome(&players[i], &players[j]);

            // Display the result
            fscl_console_out_color("light_cyan", "%s vs %s: ", players[i].name, players[j].name);
            if (outcome == WIN) {
                fscl_console_out_color("light_green", "%s wins!\n", players[i].name);
            } else if (outcome == LOSE) {
                fscl_console_out_color("light_red", "%s wins!\n", players[j].name);
            } else {
                fscl_console_out_color("light_yellow", "It's a tie!\n");
            }
        }
    }
}

void play_story_mode() {
    // Your story mode logic here
    fscl_console_out_color("light_blue", "Welcome to the story mode! Implement your story here.\n");
    // Add your story-related functionality
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
        fscl_console_out_color("light_cyan", "1. Match Mode\n");
        fscl_console_out_color("light_cyan", "2. Story Mode\n");
        fscl_console_out_color("light_cyan", "0. Exit\n");
        fscl_console_in_get_line(mode_choice);

        if (strcmp(mode_choice, "match") == 0) {
            play_match_mode();
        } else if (strcmp(mode_choice, "story") == 0) {
            play_story_mode();
        } else if (strcmp(mode_choice, "exit") == 0) {
            fscl_console_out_color("reset", "Goodbye!\n");
        } else {
            fscl_console_out_color("light_red", "Invalid choice. Try again.\n");
        }
    } while (strcmp(mode_choice, "0") != 0);

    return EXIT_SUCCESS;
} // end of func
