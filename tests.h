
#include <iostream>
#include <sstream>
#include <string>
#include "./Game.h"
#include "./Player.h"
#include "./Board.h"

// --RUN TESTS
void run_all_tests();

// --UTILITIES
void run_test(std::function<bool()> test, std::string test_name);

// --TESTS

// GAME TESTS
bool game_getSignTest();
bool game_addPlayer();