
#include <iostream>
#include <string>
#include <assert.h>
#include "./Game.h"
#include "./Player.h"
#include "./Board.h"

#include "./tests.h"

int main() {
    assert(run_all_tests() == true);
    std::cout << "Tic Tac Toe" << std::endl;
    Game game;
    game.startGame();
    return 0;
}
