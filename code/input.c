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

Move get_player_input(PlayerInput *player) {
    fscl_console_out_color("reset", "%s, it's your turn.\n", player->name);
    fscl_console_out_color("reset", "Enter your move:\n");
    fscl_console_out_color("light_blue", "1. Rock\n");
    fscl_console_out_color("light_green", "2. Paper\n");
    fscl_console_out_color("light_yellow", "3. Scissors\n");

    char* options[] = {"Rock", "Paper", "Scissors"};
    char* input = fscl_console_in_confirm_menu("Type the name of your choice: ", options, 3);

    Move move;
    if (strcmp(input, "Rock") == 0) {
        move = ROCK;
    } else if (strcmp(input, "Paper") == 0) {
        move = PAPER;
    } else {
        move = SCISSOR;
    }

    return move;
}
