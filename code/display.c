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
    fscl_console_out_color("light_cyan", "===== Welcome Fintastic Foes =====\n");
    fscl_console_out_color("light_blue", "><(((('>  \n");
    fscl_console_out_color("light_green", "~~~~~~~\n");
    fscl_console_out_color("light_green", "~~~~~~~\n");
    fscl_datetime_sleep(1000);

    fscl_console_out_color("light_cyan", "===== Welcome Fintastic Foes =====\n");
    fscl_console_out_color("light_blue", "   ><(((('>  \n");
    fscl_console_out_color("light_green", " ~~~~~~~\n");
    fscl_console_out_color("light_green", "~~~~~~~\n");
    fscl_datetime_sleep(1000);
    
    fscl_console_out_color("light_cyan", "===== Welcome Fintastic Foes =====\n");
    fscl_console_out_color("light_blue", "     ><(((('>  \n");
    fscl_console_out_color("light_green", "~~~~~~~\n");
    fscl_console_out_color("light_green", "~~~~~~~\n");
    fscl_datetime_sleep(1000);
    
    fscl_console_out_color("light_cyan", "===== Welcome Fintastic Foes =====\n");
    fscl_console_out_color("light_blue", "         ><(((('>  \n");
    fscl_console_out_color("light_green", " ~~~~~~~\n");
    fscl_console_out_color("light_green", "~~~~~~~\n");
    fscl_datetime_sleep(1000);
    
    fscl_console_out_color("light_cyan", "===== Welcome Fintastic Foes =====\n");
    fscl_console_out_color("light_blue", "            ><(((('>  \n");
    fscl_console_out_color("light_green", "~~~~~~~\n");
    fscl_console_out_color("light_green", "~~~~~~~\n");
    fscl_datetime_sleep(1000);
}

void display_goodbye() {
    fscl_console_out_color("light_cyan", "===== THANK YOU FOR PLAYING! GOODBYE! =====\n");
}

void display_error() {
    fscl_console_out_color("light_red", "===== ERROR OCCURRED! PLEASE TRY AGAIN =====\n");
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
