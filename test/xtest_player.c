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
#include "player.h" // player source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT-CASES: list of test cases testing project features
//

XTEST_CASE(test_create_and_destroy_player) {
    // Arrange
    FishPlayer *player = player_create("TestPlayer", FISH_PLAYER);

    // Act & Assert
    TEST_ASSERT_NOT_CNULLPTR(player);
    TEST_ASSERT_EQUAL_CSTRING("TestPlayer", player->info->name);
    TEST_ASSERT_EQUAL_INT(0, player->info->score);
    TEST_ASSERT_EQUAL_INT(FISH_PLAYER, player->type);

    // Clean up
    player_destroy(player);
}

XTEST_CASE(test_set_and_get_move) {
    // Arrange
    FishPlayer *player = player_create("TestPlayer", FISH_PLAYER);
    player_set_move(player, "Paper covers rock", PAPER);

    // Act
    PlayerMove *move = player_get_move(player);

    // Assert
    TEST_ASSERT_NOT_CNULLPTR(move);
    TEST_ASSERT_EQUAL_CSTRING("Paper covers rock", move->move_message);
    TEST_ASSERT_EQUAL_INT(PAPER, move->move_type);

    // Clean up
    player_destroy(player);
}

XTEST_CASE(test_increment_and_get_score) {
    // Arrange
    FishPlayer *player = player_create("TestPlayer", FISH_PLAYER);
    
    // Act & Assert
    TEST_ASSERT_EQUAL_INT(0, player_get_score(player));
    player_increment_score(player);
    TEST_ASSERT_EQUAL_INT(1, player_get_score(player));

    // Clean up
    player_destroy(player);
}

XTEST_CASE(test_save_and_load_player_data) {
    // Arrange
    FishPlayer *player = player_create("TestPlayer", FISH_PLAYER);
    player_set_move(player, "Paper covers rock", PAPER);
    player_increment_score(player);

    // Act
    int saveResult = save_player_data(player, "test_player_data.dat");
    FishPlayer *loadedPlayer = load_player_data("test_player_data.dat");

    // Assert
    TEST_ASSERT_EQUAL_INT(1, saveResult);
    TEST_ASSERT_NOT_CNULLPTR(loadedPlayer);
    TEST_ASSERT_EQUAL_INT(player_get_type(player), player_get_type(loadedPlayer));
    TEST_ASSERT_EQUAL_INT(player_get_score(player), player_get_score(loadedPlayer));

    // Clean up
    player_destroy(player);
    player_destroy(loadedPlayer);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(player_group) {
    XTEST_RUN_UNIT(test_create_and_destroy_player);
    XTEST_RUN_UNIT(test_set_and_get_move);
    XTEST_RUN_UNIT(test_increment_and_get_score);
    XTEST_RUN_UNIT(test_save_and_load_player_data);
} // end of fixture