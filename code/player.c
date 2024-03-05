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
#include "player.h"

// Function to create a new FishPlayer
FishPlayer *player_create(cstring name, PlayerType type) {
    FishPlayer *newPlayer = malloc(sizeof(FishPlayer));
    newPlayer->info = malloc(sizeof(PlayerInfo));
    newPlayer->move = malloc(sizeof(PlayerMove));

    newPlayer->info->name = name;
    newPlayer->info->score = 0;
    newPlayer->type = type;

    return newPlayer;
}

// Function to set the player's move
void player_set_move(FishPlayer *player, cstring move_message, Move move_type) {
    player->move->move_message = move_message;
    player->move->move_type = move_type;
}

// Function to get the player's move
PlayerMove *player_get_move(FishPlayer *player) {
    return player->move;
}

// Function to get the player's type
PlayerType player_get_type(FishPlayer *player) {
    return player->type;
}

// Function to get the player's score
int player_get_score(FishPlayer *player) {
    return player->info->score;
}

// Function to increment the player's score
void player_increment_score(FishPlayer *player) {
    player->info->score++;
}

// Function to destroy a FishPlayer and free allocated memory
void player_destroy(FishPlayer *player) {
    free(player->info);
    free(player->move);
    free(player);
}
