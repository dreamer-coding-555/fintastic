/**
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
#include "story.h"
#include "display.h"

void story_mode() {
    // Display story introduction
    fscl_console_out_color("light_cyan", "===== STORY MODE =====\n");

    // Add your story text here
    fscl_console_out("Once upon a time in the vast ocean...\n");
    fscl_console_out("A group of fish gathered for an epic Rock-Paper-Scissors battle.\n");
    fscl_console_out("Join our brave fish as they embark on a thrilling adventure!\n");
}
