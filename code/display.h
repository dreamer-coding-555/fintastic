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
#ifndef DISPLAY_H
#define DISPLAY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <fossil/xcore.h> // core framework
#include <fossil/xutil.h> // base utilities
#include <fossil/xstring.h> // that string lib

#include "scoreboard.h"

void display_intro();
void display_round(int round_number);
void display_player_moves(FishPlayer players[MAX_PLAYERS], int num_players);
void display_result(FishPlayer players[MAX_PLAYERS], int num_players, ScoreBoard *scoreboard);
void display_instructions();
void display_goodbye();
void display_error();
void display_loading();

#ifdef __cplusplus
}
#endif

#endif