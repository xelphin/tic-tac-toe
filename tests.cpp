
#include "./tests.h"

void run_all_tests() {
    run_test(game_getSignTest, "game_getSignTest");
    run_test(game_addPlayer, "game_addPlayer");
}

void run_test(std::function<bool()> test, std::string test_name)
{
    if(!test()){
        std::cout<< test_name <<" FAILED."<<std::endl;
        std::cout << std::endl;
        return;
    }
    std::cout<<test_name<<" SUCCEEDED."<<std::endl;
    std::cout << std::endl;
}

bool game_getSignTest()
{
    Game testGame;
    char zero = testGame.getSign(0);
    char one = testGame.getSign(1);
    bool bad = false;
    try {
        bad = testGame.getSign(2);
    } catch (const InvalidSign&){
        bad = true;
    }
    if (zero == 'X' && one == 'O' && bad)
        return true;
    return false;
}

bool game_addPlayer()
{
    Game testGame;
    testGame.addPlayer("player 1");
    testGame.addPlayer("player 2");
    bool flag = false;
    try {
        testGame.addPlayer("player 3");
    } catch (const OverflowPlayerAmount&){
        flag = true;
    }
    return flag;
}