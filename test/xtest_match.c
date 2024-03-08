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
#include "match.h" // player source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT-CASES: list of test cases testing project features
//

XTEST_CASE(test_match_randomize_lamps) {
    // Initialize players and scoreboard
    FishPlayer players[MAX_PLAYERS];
    ScoreBoard *scoreboard = scoreboard_create();

    // Randomize lamps and check if positions change
    match_randomize_lamps(players, 4);
    for (int i = 0; i < 4; i++) {
        TEST_ASSERT_NOT_EQUAL(0.0, fscl_lava_get_position(players[i].fish->lamp));
    }
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(match_group) {
    XTEST_RUN_UNIT(test_match_randomize_lamps);
} // end of fixture