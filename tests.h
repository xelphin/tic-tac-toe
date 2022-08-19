/*
RUN TESTS:
g++ -std=c++11 -Wall -Werror -pedantic-errors -g *.cpp -o output
./ouptut
*/

#include <iostream>
#include <sstream>
#include <string>
#include "./Game.h"
#include "./Player.h"
#include "./Board.h"

// --RUN TESTS
bool run_all_tests();

// --UTILITIES
void run_test(std::function<bool()> test, std::string test_name, bool& okay);

// --TESTS

// GAME TESTS
bool game_getSignTest();
bool game_addPlayer();
// BOARD TESTS
bool board_addMoveToBoard_badVertical();
bool board_addMoveToBoard_badHorizontal();
bool board_addMoveToBoard();