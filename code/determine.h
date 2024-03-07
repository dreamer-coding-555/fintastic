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
#ifndef DETERMINE_H
#define DETERMINE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <fossil/xcore.h> // core framework
#include <fossil/xutil.h> // base utilities
#include <fossil/xstring.h> // that string lib

#include "player.h"

typedef enum {
    WIN,
    LOSE,
    TIE
} GameOutcome;

typedef struct {
    int winner_index;
    int loser_index;
} GameResult;

GameOutcome determine_outcome(FishPlayer *players[]);
GameResult get_game_result(FishPlayer *players[]);
const_cstring get_outcome_message(GameOutcome outcome, FishPlayer *players[]);
const_cstring get_result_message(GameResult result, FishPlayer *players[]);
const_cstring read_message_from_file(const_cstring filename);

#ifdef __cplusplus
}
#endif

#endif