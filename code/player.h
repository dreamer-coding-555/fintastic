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
#ifndef PLAYER_H
#define PLAYER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <fossil/xcore.h> // core framework
#include <fossil/xutil.h> // base utilities
#include <fossil/xstring.h> // that string lib

typedef enum {
    PAPER,
    ROCK,
    SCISSOR
} Move;

typedef enum {
    FISH_NPC,
    FISH_PLAYER
} PlayerType;

typedef struct {
    cstring move_message;
    Move move_type;
} PlayerMove;

typedef struct {
    cstring name;
    int score;
} PlayerInfo;

typedef struct {
    PlayerInfo *info;
    PlayerMove *move;
    PlayerType type;
} FishPlayer;

FishPlayer *player_create(cstring name, PlayerType type);
void player_set_move(FishPlayer *player, cstring move_message, Move move_type);
PlayerInfo *player_get_info(FishPlayer *player);
PlayerMove *player_get_move(FishPlayer *player);
PlayerType player_get_type(FishPlayer *player);
int player_get_score(FishPlayer *player);
void player_increment_score(FishPlayer *player);
int save_player_data(FishPlayer *player, cstring filename);
FishPlayer *load_player_data(cstring filename);
void player_destroy(FishPlayer *player);

#ifdef __cplusplus
}
#endif

#endif