
#include "./tests.h"

/* Avoids Console Printing If Not Debugging */
#ifdef NDEBUG // I DONT want to debug
void printFail ();
void printSuccess ();
#define printFail() ((void)0)
#define printSuccess() ((void)0)
#else // I DO want to debug
#define printFail() (std::cout<< test_name <<" FAILED."<<std::endl)
#define printSuccess() (std::cout<< test_name <<" SUCCESS."<<std::endl)
#endif

bool run_all_tests() {
    bool okay = true;
    run_test(game_getSignTest, "game_getSignTest", okay);
    run_test(game_addPlayer, "game_addPlayer", okay);
    return okay;
}

void run_test(std::function<bool()> test, std::string test_name, bool &okay)
{
    if(!test()){
        printFail();
        std::cout << std::endl;
        okay = false;
        return;
    }
    printSuccess();
    std::cout << std::endl;
}

bool game_getSignTest()
{
    freopen("./tests_gameInput.txt", "r", stdin);
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
    freopen("./tests_gameInput.txt", "r", stdin);
    Game testGame;
    bool flag = false;
    try {
        testGame.addPlayer("player 3");
    } catch (const OverflowPlayerAmount&) {
        flag = true;
    }
    return flag;
}