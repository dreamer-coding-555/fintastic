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
#ifndef MATCH_H
#define MATCH_H

#ifdef __cplusplus
extern "C" {
#endif

#include <fossil/xcore.h> // core framework
#include <fossil/xutil.h> // base utilities
#include <fossil/xstring.h> // that string lib

#include "player.h"
#include "scoreboard.h"

void play_match_mode(FishPlayer players[MAX_PLAYERS], int num_players, ScoreBoard *scoreboard);
void match_randomize_lamps(FishPlayer players[MAX_PLAYERS], int num_players);

#ifdef __cplusplus
}
#endif

#endif