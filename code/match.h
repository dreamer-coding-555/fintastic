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
#ifndef INPUT_H
#define INPUT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <fossil/xcore.h> // core framework
#include <fossil/xutil.h> // base utilities
#include <fossil/xstring.h> // that string lib

#include "player.h"
#include "scoreboard.h"

void match_initialize_players(FishPlayer players[MAX_PLAYERS], int num_human_players, int num_players);
void match_play_round(FishPlayer players[MAX_PLAYERS], int num_players, ScoreBoard *scoreboard);
void match_save_final_scoreboard(ScoreBoard *scoreboard);

#ifdef __cplusplus
}
#endif

#endif