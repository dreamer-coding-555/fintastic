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

static void initialize_players(FishPlayer players[MAX_PLAYERS], int num_human_players, int num_players) {
    // Create human players
    for (int i = 0; i < num_human_players; i++) {
        char name[20];
        fscl_console_out("Enter name for Human Player %d: ", i + 1);
        fscl_console_in_get_line(name);
        players[i] = create_human_player(name);
    }

    // Create AI players
    for (int i = num_human_players; i < num_players; i++) {
        char name[20];
        snprintf(name, sizeof(name), "AI Player %d", i + 1);
        players[i] = create_ai_player(name);
    }
}

static void simulate_round(FishPlayer players[MAX_PLAYERS], int num_players) {
    // Simulate the lava lamp state for each player
    for (int i = 0; i < num_players; i++) {
        fscl_lava_capture_state(players[i].fish->lamp);
        players[i].move = determine_player_move(players[i].fish->lamp);
    }
}

static Move determine_player_move(clavalamp* lamp) {
    // Use the lava lamp state to determine the player's move
    // For simplicity, let's use a basic mapping
    if (lamp->position < 0.33) {
        return PAPER;
    } else if (lamp->position < 0.66) {
        return ROCK;
    } else {
        return SCISSOR;
    }
}

static void determine_outcomes(FishPlayer players[MAX_PLAYERS], int num_players, ScoreBoard *scoreboard) {
    for (int i = 0; i < num_players; i++) {
        for (int j = i + 1; j < num_players; j++) {
            GameOutcome outcome = determine_outcome(&players[i], &players[j]);

            // Display the result
            fscl_console_out_color("light_cyan", "%s vs %s: ", player_get_info(&players[i])->name, player_get_info(&players[j])->name);
            if (outcome == WIN) {
                fscl_console_out_color("light_green", "%s wins!\n", player_get_info(&players[i])->name);
                scoreboard_update_entry(scoreboard, player_get_info(&players[i])->name, scoreboard->entries[i].player_score + 1);
            } else if (outcome == LOSE) {
                fscl_console_out_color("light_red", "%s wins!\n", player_get_info(&players[j])->name);
                scoreboard_update_entry(scoreboard, player_get_info(&players[j])->name, scoreboard->entries[j].player_score + 1);
            } else {
                fscl_console_out_color("light_yellow", "It's a tie!\n");
            }
        }
    }
}

static void display_scoreboard(ScoreBoard *scoreboard) {
    fscl_console_out_color("light_cyan", "===== SCOREBOARD =====\n");
    scoreboard_display(scoreboard);
    fscl_console_out_color("light_cyan", "======================\n");
}

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