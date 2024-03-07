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

enum { MAX_FILENAME_LENGTH = 256};

GameOutcome determine_outcome(FishPlayer **players) {
    int num_players = sizeof(players) / sizeof(players[0]);

    if (num_players < 2 || num_players > 4) {
        // Invalid number of players
        return TIE;
    }

    Move moves[num_players];
    
    for (int i = 0; i < num_players; ++i) {
        moves[i] = player_get_move(players[i])->move_type;
    }

    // Check for all moves being the same
    for (int i = 1; i < num_players; ++i) {
        if (moves[i] != moves[0]) {
            return TIE; // At least one different move, no winner
        }
    }

    // Check for winning conditions
    if ((moves[0] == PAPER && moves[1] == ROCK) ||
        (moves[0] == ROCK && moves[1] == SCISSOR) ||
        (moves[0] == SCISSOR && moves[1] == PAPER)) {
        return WIN;
    }

    // Reverse check for winning conditions
    if ((moves[1] == PAPER && moves[0] == ROCK) ||
        (moves[1] == ROCK && moves[0] == SCISSOR) ||
        (moves[1] == SCISSOR && moves[0] == PAPER)) {
        return LOSE;
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

const_cstring get_outcome_message(GameOutcome outcome, FishPlayer **players) {
    const_cstring filename;

    switch (outcome) {
        case WIN:
            filename = "determine_rock.txt";  // Assume winning with rock for simplicity
            break;
        case LOSE:
            filename = "determine_scissors.txt";  // Assume losing to scissors for simplicity
            break;
        case TIE:
            filename = "determine_paper.txt";  // Assume tying with paper for simplicity
            break;
        default:
            return "Invalid outcome";
    }

    return read_message_from_file(filename);
}

const_cstring get_result_message(GameResult result, FishPlayer **players) {
    if (result.winner_index != -1 && result.loser_index != -1) {
        char *winner_name = player_get_info(players[result.winner_index])->name;
        char *loser_name = player_get_info(players[result.loser_index])->name;
        char *winner_move = player_get_move(players[result.winner_index])->move_message;
        char *loser_move = player_get_move(players[result.loser_index])->move_message;

        const_cstring filename = (result.winner_index == 0) ? "result_win.txt" : "result_lose.txt";
        const_cstring template = read_message_from_file(filename);

        // Allocate memory for the final message
        size_t message_size = snprintf(NULL, 0, template, winner_name, winner_move, loser_name, loser_move);
        char *message = malloc(message_size + 1);

        // Populate the final message
        snprintf(message, message_size + 1, template, winner_name, winner_move, loser_name, loser_move);

        return message;
    } else {
        return "Invalid result";
    }
}
