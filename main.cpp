
#include <iostream>
#include <string>
#include <assert.h>
#include "./Game.h"
#include "./Player.h"
#include "./Board.h"

#include "./tests.h"

int main() {
    assert(run_all_tests() == true);
    system("clear");
    Game game;
    return 0;
}
