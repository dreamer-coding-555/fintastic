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

int get_user_choice(const char *question, const char **menu, int num_options) {
    int choice;

    do {
        fscl_console_out("%s", question);

        for (int i = 0; i < num_options; i++) {
            fscl_console_out("%d. %s\n", i + 1, menu[i]);
        }

        choice = fscl_console_in_confirm_menu("Select an option (1-%d): ", menu, num_options);

        if (choice < 1 || choice > num_options) {
            fscl_console_out_color("light_red", "Invalid choice. Please try again.\n");
        }
    } while (choice < 1 || choice > num_options);

    return choice - 1; // Adjust to 0-based index
}

// The run_app function is designed to read data from a file named "data.txt"
// using a custom stream implementation (cstream).
// Returns EXIT_SUCCESS if the file is read successfully; otherwise, the
// behavior is undefined.
int run_app(int argc, char **argv) {
    display_intro();

    const_cstring menu[] = {"Match Mode", "Story Mode", "Exit"};
    int choice = get_user_choice("Choose a mode:", menu, 3);

    switch (choice) {
        case 0:  match_mode();      break;
        case 1:  story_mode();      break;
        case 2:  display_goodbye(); break;
        default: display_error();   break;
    }

    return EXIT_SUCCESS;
} // end of func
