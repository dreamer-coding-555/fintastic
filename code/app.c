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
#include "app.h"

// The run_app function is designed to read data from a file named "data.txt"
// using a custom stream implementation (cstream).
// Returns EXIT_SUCCESS if the file is read successfully; otherwise, the
// behavior is undefined.
int run_app(int argc, char **argv) {
    display_intro();

    intchar mode_choice[10];

    // Display the main menu
    fscl_console_out_color("light_cyan", "===== FISH RPS GAME =====\n");
    fscl_console_out("1. Play Match Mode\n");
    fscl_console_out("2. Play Story Mode\n");
    fscl_console_out("3. Exit\n");

    fscl_console_in_get_line(mode_choice);
    lower_case(mode_choice);

    if (strcmp(mode_choice, MATCH_MODE) == 0) {
        match_mode();
    } else if (strcmp(mode_choice, STORY_MODE) == 0) {
        story_mode();
    } else if (strcmp(mode_choice, EXIT_MODE) == 0) {
        fscl_console_out_color("light_yellow", "Thanks for playing! Goodbye.\n");
    } else {
        fscl_console_out_color("light_red", "Invalid choice. Exiting.\n");
    }

    return EXIT_SUCCESS;
} // end of func
