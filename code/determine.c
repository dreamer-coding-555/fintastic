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
#include "determine.h"

GameOutcome determine_outcome(FishPlayer **players) {
    int num_players = sizeof(players) / sizeof(players[0]);

    if (num_players < 2 || num_players > 4) {
        // Invalid number of players
        return TIE;
    }

    for (int i = 0; i < num_players; ++i) {
        for (int j = i + 1; j < num_players; ++j) {
            Move move1 = player_get_move(players[i])->move_type;
            Move move2 = player_get_move(players[j])->move_type;

            if (move1 == move2) {
                return TIE; // At least one tie, no winner
            }

            // Check for winning conditions
            if ((move1 == PAPER && move2 == ROCK) ||
                (move1 == ROCK && move2 == SCISSOR) ||
                (move1 == SCISSOR && move2 == PAPER)) {
                return WIN;
            }

            // Reverse check for winning conditions
            if ((move2 == PAPER && move1 == ROCK) ||
                (move2 == ROCK && move1 == SCISSOR) ||
                (move2 == SCISSOR && move1 == PAPER)) {
                return LOSE;
            }
        }
    }

    return TIE; // No winner found
}

GameResult get_game_result(FishPlayer **players) {
    GameResult result = {-1, -1};
    GameOutcome outcome = determine_outcome(players);

    if (outcome == WIN || outcome == LOSE) {
        // Find the winner and loser indices
        int num_players = sizeof(players) / sizeof(players[0]);
        for (int i = 0; i < num_players; ++i) {
            for (int j = i + 1; j < num_players; ++j) {
                Move move1 = player_get_move(players[i])->move_type;
                Move move2 = player_get_move(players[j])->move_type;

                if (outcome == WIN && ((move1 == PAPER && move2 == ROCK) ||
                                       (move1 == ROCK && move2 == SCISSOR) ||
                                       (move1 == SCISSOR && move2 == PAPER))) {
                    result.winner_index = i;
                    result.loser_index = j;
                } else if (outcome == LOSE && ((move2 == PAPER && move1 == ROCK) ||
                                               (move2 == ROCK && move1 == SCISSOR) ||
                                               (move2 == SCISSOR && move1 == PAPER))) {
                    result.winner_index = j;
                    result.loser_index = i;
                }
            }
        }
    }

    return result;
}
