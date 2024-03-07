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
#include "scoreboard.h"


ScoreBoard *scoreboard_create() {
    ScoreBoard *newBoard = malloc(sizeof(ScoreBoard));
    newBoard->entries = cnullptr;
    newBoard->size = 0;

    return newBoard;
}

void scoreboard_add_entry(ScoreBoard *board, cstring player_name, int player_score) {
    board->entries = realloc(board->entries, (board->size + 1) * sizeof(ScoreEntry));
    board->entries[board->size].player_name = fscl_string_strdup(player_name);
    board->entries[board->size].player_score = player_score;
    board->size++;
}

void scoreboard_update_entry(ScoreBoard *board, cstring player_name, int new_score) {
    for (int i = 0; i < board->size; ++i) {
        if (fscl_string_compare(board->entries[i].player_name, player_name) == 0) {
            board->entries[i].player_score = new_score;
            break;
        }
    }
}

void scoreboard_display(ScoreBoard *board) {
    fscl_console_put("Score Board:");
    for (int i = 0; i < board->size; ++i) {
        fscl_console_out("%s: %d\n", board->entries[i].player_name, board->entries[i].player_score);
    }
    fscl_console_out("\n");
}

void scoreboard_save_to_file(cstream *stream, ScoreBoard *board) {
    if (fscl_stream_open(stream, stream->filename, "w") == 0) {
        fscl_error_set(FSCL_CERROR_MEDIA_OPEN_FAILED);
        fscl_console_err("%s", fscl_error_wait());
        return;
    }

    for (int i = 0; i < board->size; ++i) {
        fprintf(stream->file, "%s %d\n", board->entries[i].player_name, board->entries[i].player_score);
    }

    fscl_stream_close(stream);
}

ScoreBoard *scoreboard_load_from_file(cstream *stream) {
    if (fscl_stream_open(stream, stream->filename, "r") == 0) {
        fscl_error_set(FSCL_CERROR_MEDIA_OPEN_FAILED);
        fscl_console_err("%s", fscl_error_wait());
        return cnullptr;
    }

    ScoreBoard *loadedBoard = scoreboard_create();
    char name[50]; // Assuming player names are no longer than 50 characters
    int score;

    while (fscanf(stream->file, "%s %d", name, &score) == 2) {
        scoreboard_add_entry(loadedBoard, name, score);
    }

    fscl_stream_close(stream);
    return loadedBoard;
}

void scoreboard_destroy(ScoreBoard *board) {
    for (int i = 0; i < board->size; ++i) {
        free(board->entries[i].player_name);
    }
    free(board->entries);
    free(board);
}
