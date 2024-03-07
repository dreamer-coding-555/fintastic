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
#include "scoreboard.h" // player source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

// Create a test cstream for file operations
static cstream test_stream;

//
// XUNIT-CASES: list of test cases testing project features
//

XTEST_CASE(test_create_and_destroy_scoreboard) {
    // Arrange & Act
    fscl_stream_open(&test_stream, "test_scoreboard_data.txt", "w");
    fscl_stream_close(&test_stream);
    ScoreBoard *board = scoreboard_create();

    // Assert
    TEST_ASSERT_NOT_CNULLPTR(board);
    TEST_ASSERT_EQUAL_INT(0, board->size);

    // Clean up
    scoreboard_destroy(board);
    fscl_stream_delete("test_scoreboard_data.txt");
}

XTEST_CASE(test_add_and_display_entry) {
    // Arrange
    fscl_stream_open(&test_stream, "test_scoreboard_data.txt", "w");
    fscl_stream_close(&test_stream);
    ScoreBoard *board = scoreboard_create();

    // Act
    scoreboard_add_entry(board, "Player1", 10);

    // Assert
    TEST_ASSERT_EQUAL_INT(1, board->size);

    // Display for manual verification
    printf("Display after adding entry:\n");
    scoreboard_display(board);

    // Clean up
    scoreboard_destroy(board);
    fscl_stream_delete("test_scoreboard_data.txt");
}

XTEST_CASE(test_update_entry) {
    // Arrange
    fscl_stream_open(&test_stream, "test_scoreboard_data.txt", "w");
    fscl_stream_close(&test_stream);
    ScoreBoard *board = scoreboard_create();
    scoreboard_add_entry(board, "Player1", 10);

    // Act
    scoreboard_update_entry(board, "Player1", 15);

    // Assert
    TEST_ASSERT_EQUAL_INT(15, board->entries[0].player_score);

    // Display for manual verification
    printf("Display after updating entry:\n");
    scoreboard_display(board);

    // Clean up
    scoreboard_destroy(board);
    fscl_stream_delete("test_scoreboard_data.txt");
}

XTEST_CASE(test_save_and_load_from_file) {
    // Arrange
    fscl_stream_open(&test_stream, "test_scoreboard_data.txt", "w");
    fscl_stream_close(&test_stream);
    ScoreBoard *board = scoreboard_create();
    scoreboard_add_entry(board, "Player1", 10);
    scoreboard_add_entry(board, "Player2", 5);

    // Act
    scoreboard_save_to_file(&test_stream, board);

    // Load the data back into a new scoreboard
    ScoreBoard *loadedBoard = scoreboard_load_from_file(&test_stream);

    // Assert
    TEST_ASSERT_NOT_CNULLPTR(loadedBoard);
    TEST_ASSERT_EQUAL_INT(2, loadedBoard->size);
    TEST_ASSERT_EQUAL_CSTRING("Player1", loadedBoard->entries[0].player_name);
    TEST_ASSERT_EQUAL_INT(10, loadedBoard->entries[0].player_score);
    TEST_ASSERT_EQUAL_CSTRING("Player2", loadedBoard->entries[1].player_name);
    TEST_ASSERT_EQUAL_INT(5, loadedBoard->entries[1].player_score);

    // Display for manual verification
    printf("Display after loading from file:\n");
    scoreboard_display(loadedBoard);

    // Clean up
    scoreboard_destroy(board);
    scoreboard_destroy(loadedBoard);
    fscl_stream_delete("test_scoreboard_data.txt");
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(scoreboard_group) {
    XTEST_RUN_UNIT(test_create_and_destroy_scoreboard);
    XTEST_RUN_UNIT(test_add_and_display_entry);
    XTEST_RUN_UNIT(test_update_entry);
    XTEST_RUN_UNIT(test_save_and_load_from_file);
} // end of fixture