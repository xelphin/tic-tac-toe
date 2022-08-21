/*
RUN TESTS:
g++ -std=c++11 -Wall -Werror -pedantic-errors -g *.cpp -o output
./ouptut
*/

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <random>
#include <cstdio>
#include <fstream>
#include <cstring>
#include "./Game.h"
#include "./Player.h"
#include "./Board.h"


// --RUN TESTS
bool run_all_tests();

// --UTILITIES
void run_test(std::function<bool()> test, std::string test_name, bool& okay);
bool compareFiles(const std::string &filename1, const std::string &filename2);
void deleteTextFile(const std::string &filename);
std::string readFileIntoString(const std::string& path);

// --TESTS

// BOARD TESTS
bool board_getSignTest();
bool board_addMoveToBoard_badHorizontal();
bool board_addMoveToBoard_badVertical();
bool board_addMoveToBoard();
bool board_checkWin();
bool board_checkWin_Hor();
bool board_checkWin_Ver();
bool board_checkWin_DiagLR();
bool board_checkWin_DiagRL();
bool board_printBoard();
// GAME TESTS
bool game_startGame();