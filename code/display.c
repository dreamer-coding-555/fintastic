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
#include "display.h"

void display_intro() {
    fscl_console_out_color("light_cyan", "===== WELCOME TO FISH RPS GAME =====\n");
    // Add fish ASCII art here
    fscl_console_out_color("light_blue", "      ><(((('>  \n");

    // Add seaweed ASCII art here
    fscl_console_out_color("light_green", "~~~~~~~\n");
    fscl_console_out_color("light_green", "~~~~~~~\n");
}

void display_round(int round_number) {
    fscl_console_out_color("light_cyan", "===== ROUND %d =====\n", round_number);
}

void display_player_moves(FishPlayer players[MAX_PLAYERS], int num_players) {
    for (int i = 0; i < num_players; i++) {
        fscl_console_out("%s's move: %s\n", player_get_info(&players[i])->name, player_get_move(&players[i])->move_message);
    }
}

void display_result(FishPlayer players[MAX_PLAYERS], int num_players, ScoreBoard *scoreboard) {
    for (int i = 0; i < num_players; i++) {
        fscl_console_out_color("light_cyan", "===== RESULT =====\n");
        fscl_console_out_color("light_cyan", "%s's move: %s\n", player_get_info(&players[i])->name, player_get_move(&players[i])->move_message);
    }

    // Determine outcomes and display the results
    determine_outcomes(players, num_players, scoreboard);
    display_scoreboard(scoreboard);
}

void display_instructions() {
    fscl_console_out_color("light_yellow", "===== GAME INSTRUCTIONS =====\n");
    fscl_console_out_color("light_yellow", "Enter your move choice: 1 (Rock), 2 (Paper), 3 (Scissors)\n");
}

void display_goodbye() {
    fscl_console_out_color("light_cyan", "===== THANK YOU FOR PLAYING! GOODBYE! =====\n");
}

void display_error() {
    fscl_console_out_color("light_red", "===== ERROR OCCURRED! PLEASE TRY AGAIN =====\n");
}

void display_loading() {
    fscl_console_out_color("light_yellow", "Loading... Please wait.\n");
}

void display_start_menu() {
    fscl_console_out_color("light_cyan", "===== FISH RPS GAME =====\n");
    // Add start menu ASCII art here
    fscl_console_out_color("light_blue", "      ><(((('>  \n");
    fscl_console_out_color("light_yellow", "-. story: Play story mode\n");
    fscl_console_out_color("light_yellow", "-. match: Play a match\n");
    fscl_console_out_color("light_yellow", "-. score: View scoreboard\n");
    fscl_console_out_color("light_yellow", "-. exit: Exit the game\n");
}

void display_weapon_menu() {
    fscl_console_out_color("light_yellow", "===== WEAPON SELECTION =====\n");
    // Add weapon menu ASCII art here
    fscl_console_out_color("light_cyan", "      (1) rock   \n");
    fscl_console_out_color("light_cyan", "      (2) paper  \n");
    fscl_console_out_color("light_cyan", "      (3) scissors\n");
}
