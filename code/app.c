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

void match_mode() {
    // Create an array to store players
    FishPlayer players[MAX_PLAYERS];

    // Create an array to store the scoreboard
    ScoreBoard *scoreboard = scoreboard_create();

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

    // Create human players
    for (int i = 0; i < num_human_players; i++) {
        char name[20];
        fscl_console_out("Enter name for Human Player %d: ", i + 1);
        fscl_console_in_get_line(name);
        players[i] = player_create(name, FISH_PLAYER);
    }

    // Create AI players
    for (int i = num_human_players; i < num_players; i++) {
        char name[20];
        snprintf(name, sizeof(name), "AI Player %d", i + 1);
        players[i] = player_create(name, FISH_NPC);
    }

    // Play the match mode
    play_match_mode(players, scoreboard);

    // Clean up
    scoreboard_destroy(scoreboard);
}

void story_mode() {
    // Create an array to store players (you can adjust this based on your story mode)
    FishPlayer players[MAX_PLAYERS];

    // Play the story mode
    play_story_mode(players);

    // Additional story mode logic goes here
}

void lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// The run_app function is designed to read data from a file named "data.txt"
// using a custom stream implementation (cstream).
// Returns EXIT_SUCCESS if the file is read successfully; otherwise, the
// behavior is undefined.
int run_app(int argc, char **argv) {
    display_intro();

    intchar mode_choice[10];

    // Display the main menu
    fscl_console_out_color("light_cyan", "===== FISH RPS GAME =====\n");
    fscl_console_out("1. Play Match Mode\n");
    fscl_console_out("2. Play Story Mode\n");
    fscl_console_out("3. Exit\n");

    fscl_console_in_get_line(mode_choice);
    lower_case(mode_choice);

    if (strcmp(mode_choice, MATCH_MODE) == 0) {
        match_mode();
    } else if (strcmp(mode_choice, STORY_MODE) == 0) {
        story_mode();
    } else if (strcmp(mode_choice, EXIT_MODE) == 0) {
        fscl_console_out_color("light_yellow", "Thanks for playing! Goodbye.\n");
    } else {
        fscl_console_out_color("light_red", "Invalid choice. Exiting.\n");
    }

    return EXIT_SUCCESS;
} // end of func
