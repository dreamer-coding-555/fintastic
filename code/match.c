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
#include "match.h"
#include "display.h"

void match_randomize_lamps(FishPlayer players[MAX_PLAYERS]) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        // Randomly set lamp position and velocity for each player
        players[i].fish.lamp.position = (double)fscl_lava_random() / (double)RAND_MAX;
        players[i].fish.lamp.velocity = (double)fscl_lava_random() / (double)RAND_MAX;
    }
}

void play_match_mode(FishPlayer players[MAX_PLAYERS]) {
    // Number of rounds to simulate
    int num_rounds = 3; // Adjust as needed

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
        determine_outcomes(players, MAX_PLAYERS);

        // Display the result
        display_result(players, MAX_PLAYERS);

        // Display the scoreboard at the end of each round
        scoreboard_display(scoreboard);
    }

    // Save the final scoreboard to a file
    cstream stream;
    if (fscl_stream_open(&stream, "scoreboard.txt", "w")) {
        scoreboard_save_to_file(&stream, scoreboard);
        fscl_stream_close(&stream);
    }
}
