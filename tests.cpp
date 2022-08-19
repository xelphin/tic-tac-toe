
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
    run_test(board_addMoveToBoard_badVertical, "board_addMoveToBoard_badVertical", okay);
    run_test(board_addMoveToBoard_badHorizontal, "board_addMoveToBoard_badHorizontal", okay);
    run_test(board_addMoveToBoard, "board_addMoveToBoard", okay);
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
    freopen("./test_files/tests_gameInput.txt", "r", stdin);
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
    freopen("./test_files/tests_gameInput.txt", "r", stdin);
    Game testGame;
    try {
        testGame.addPlayer("player 3");
    } catch (const OverflowPlayerAmount&) {
        return true;
    }
    return false;
}

bool board_addMoveToBoard_badVertical()
{
    Board testBoard;
    try {
        testBoard.addMoveToBoard(1,'4','a');
    } catch (const InvalidVerticalArgument&){
        return true;
    }
    return false;
}

bool board_addMoveToBoard_badHorizontal()
{
    Board testBoard;
    try {
        testBoard.addMoveToBoard(1,'2','d');
    } catch (const InvalidHorizontalArgument&){
        return true;
    }
    return false;
}

bool board_addMoveToBoard()
{
    Board testBoard;
    int caught = 0;
    testBoard.addMoveToBoard(1,'1','a');
    testBoard.addMoveToBoard(1,'2','a');
    testBoard.addMoveToBoard(1,'1','b');
    testBoard.addMoveToBoard(1,'3','b');
    testBoard.addMoveToBoard(1,'3','c');
    testBoard.addMoveToBoard(1,'1','c');
    try {
        testBoard.addMoveToBoard(1,'3','b');
    } catch (const UnavailableSlot&){
        caught++;
    }
    try {
        testBoard.addMoveToBoard(0,'2','a');
    } catch (const UnavailableSlot&){
        caught++;
    }
    testBoard.addMoveToBoard(0,'2','c');
    return caught==2;
}

