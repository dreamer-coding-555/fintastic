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
#include "input.h" // player source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

// Mock for console input
char mock_input[50];  // Adjust the size based on your needs

// Mocked fscl_console_in_read_line
char* fscl_mock_console_input(const char* prompt) {
    // Return the mocked input
    return mock_input;
}

//
// XUNIT-CASES: list of test cases testing project features
//

XTEST_CASE(test_get_user_input_rock) {
    // Simulate user input for "rock"
    // Mock the console input
    char mock_input[] = "rock\n";
    fscl_mock_console_input(mock_input);

    PlayerInput result = get_user_input();

    // Ensure the Move type is correct
    TEST_ASSERT_EQUAL(ROCK, result.move_type);
}

XTEST_CASE(test_get_user_input_paper) {
    // Simulate user input for "paper"
    // Mock the console input
    char mock_input[] = "paper\n";
    fscl_mock_console_input(mock_input);

    PlayerInput result = get_user_input();

    // Ensure the Move type is correct
    TEST_ASSERT_EQUAL(PAPER, result.move_type);
}

XTEST_CASE(test_get_user_input_scissors) {
    // Simulate user input for "scissors"
    // Mock the console input
    char mock_input[] = "scissors\n";
    fscl_mock_console_input(mock_input);

    PlayerInput result = get_user_input();

    // Ensure the Move type is correct
    TEST_ASSERT_EQUAL(SCISSOR, result.move_type);
}

XTEST_CASE(test_get_user_input_invalid) {
    // Simulate user input for an invalid move
    // Mock the console input
    char mock_input[] = "invalid_input\n";
    fscl_mock_console_input(mock_input);

    PlayerInput result = get_user_input();

    // Ensure the Move type is INVALID_MOVE
    TEST_ASSERT_EQUAL(INVALID_MOVE, result.move_type);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(input_group) {
    XTEST_RUN_UNIT(test_get_user_input_rock);
    XTEST_RUN_UNIT(test_get_user_input_paper);
    XTEST_RUN_UNIT(test_get_user_input_scissors);
    XTEST_RUN_UNIT(test_get_user_input_invalid);
} // end of fixture