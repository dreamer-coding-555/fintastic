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
#include "determine.h" // player source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT-CASES: list of test cases testing project features
//

XTEST_CASE(test_determine_outcome) {
    // Create FishPlayers with different moves
    FishPlayer player1 = create_fish_player("Player1", PAPER);
    FishPlayer player2 = create_fish_player("Player2", ROCK);

    // Get outcome
    GameOutcome outcome = determine_outcome(&player1, &player2);

    // Check if the outcome is as expected
    TEST_ASSERT_EQUAL(WIN, outcome);
}

XTEST_CASE(test_get_game_result) {
    // Create FishPlayers with different moves
    FishPlayer player1 = create_fish_player("Player1", PAPER);
    FishPlayer player2 = create_fish_player("Player2", ROCK);

    // Get game result
    GameResult result = get_game_result(&player1, &player2);

    // Check if the result is as expected
    TEST_ASSERT_EQUAL(0, result.winner_index);
    TEST_ASSERT_EQUAL(1, result.loser_index);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(determine_group) {
    XTEST_RUN_UNIT(test_determine_outcome);
    XTEST_RUN_UNIT(test_get_game_result);
} // end of fixture