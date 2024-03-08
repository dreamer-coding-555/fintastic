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

void match_initialize_players(FishPlayer players[MAX_PLAYERS], int num_human_players, int num_players) {
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

void match_play_round(FishPlayer players[MAX_PLAYERS], int num_players, ScoreBoard *scoreboard) {
    // Simulate a game round for each player
    simulate_round(players, num_players);

    // Determine the game outcome
    determine_outcomes(players, num_players, scoreboard);

    // Display the scoreboard at the end of each round
    display_scoreboard(scoreboard);
}

void match_save_final_scoreboard(ScoreBoard *scoreboard) {
    // Save the final scoreboard to a file
    cstream stream;
    if (fscl_stream_open(&stream, "scoreboard.txt", "w")) {
        scoreboard_save_to_file(&stream, scoreboard);
        fscl_stream_close(&stream);
    }

    // Clean up the scoreboard
    scoreboard_destroy(scoreboard);
}
