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
#include "input.h"

PlayerInput get_user_input() {
    PlayerInput player_input;

    fscl_console_out_color("light_blue", "Enter your move (Rock, Paper, or Scissor): ");
    fscl_console_in_get_line(player_input.raw_input);

    // Convert input to lowercase for case-insensitivity
    for (int i = 0; player_input.raw_input[i]; i++) {
        player_input.raw_input[i] = tolower(player_input.raw_input[i]);
    }

    // Check user input and set the corresponding Move type
    if (strstr(player_input.raw_input, "rock")) {
        player_input.move_type = ROCK;
    } else if (strstr(player_input.raw_input, "paper")) {
        player_input.move_type = PAPER;
    } else if (strstr(player_input.raw_input, "scissor") || strstr(player_input.raw_input, "scissors")) {
        player_input.move_type = SCISSOR;
    } else {
        // Default to invalid move in case of unrecognized input
        player_input.move_type = INVALID_MOVE;
    }

    return player_input;
}