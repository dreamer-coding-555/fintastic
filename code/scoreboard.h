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
#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <fossil/xcore.h> // core framework
#include <fossil/xutil.h> // base utilities
#include <fossil/xstring.h> // that string lib

typedef struct {
    cstring player_name;
    int player_score;
} ScoreEntry;

typedef struct {
    ScoreEntry *entries;
    int size;
} ScoreBoard;

ScoreBoard *scoreboard_create();
void scoreboard_add_entry(ScoreBoard *board, cstring player_name, int player_score);
void scoreboard_update_entry(ScoreBoard *board, cstring player_name, int new_score);
void scoreboard_display(ScoreBoard *board);
void scoreboard_save_to_file(cstream *stream, ScoreBoard *board);
ScoreBoard *scoreboard_load_from_file(cstream *stream);
void scoreboard_destroy(ScoreBoard *board);

#ifdef __cplusplus
}
#endif

#endif