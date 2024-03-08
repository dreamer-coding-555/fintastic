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

void play_match_mode(FishPlayer players[MAX_PLAYERS], int num_players, ScoreBoard *scoreboard) {
    // Number of rounds to simulate
    int num_rounds = 3; // Adjust as needed

    for (int round = 1; round <= num_rounds; round++) {
        fscl_console_out_color("light_cyan", "===== ROUND %d =====\n", round);

        // Play a round using the utility function
        match_play_round(players, num_players, scoreboard);

        // Randomize the lava lamp states for the next round
        match_randomize_lamps(players, num_players);
    }

    // Save the final scoreboard using the utility function
    match_save_final_scoreboard(scoreboard);
    fscl_console_out_color("light_cyan", "===== MATCH ENDED =====\n");
}

void match_randomize_lamps(FishPlayer players[MAX_PLAYERS], int num_players) {
    // Randomize the lava lamp state for each player
    for (int i = 0; i < num_players; i++) {
        fscl_lava_randomize(players[i].fish->lamp, 1);
    }
}