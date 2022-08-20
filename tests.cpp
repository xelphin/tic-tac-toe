
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
    run_test(board_addMoveToBoard_badHorizontal, "board_addMoveToBoard_badHorizontal", okay);
    run_test(board_addMoveToBoard_badVertical, "board_addMoveToBoard_badVertical", okay);
    run_test(board_addMoveToBoard, "board_addMoveToBoard", okay);
    run_test(board_checkWin_Hor, "board_checkWin_Hor", okay);
    run_test(board_checkWin_Ver, "board_checkWin_Ver", okay);
    run_test(board_checkWin_DiagLR, "board_checkWin_DiagLR", okay);
    run_test(board_checkWin_DiagRL, "board_checkWin_DiagRL", okay);
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

bool board_addMoveToBoard_badHorizontal()
{
    Board testBoard;
    try {
        testBoard.addMoveToBoard(1,'a','4');
    } catch (const InvalidHorizontalArgument&){
        return true;
    }
    return false;
}

bool board_addMoveToBoard_badVertical()
{
    Board testBoard;
    try {
        testBoard.addMoveToBoard(1,'d','2');
    } catch (const InvalidVerticalArgument&){
        return true;
    }
    return false;
}

bool board_addMoveToBoard()
{
    Board testBoard;
    int caught = 0;
    testBoard.addMoveToBoard(1,'a','1');
    testBoard.addMoveToBoard(1,'a','2');
    testBoard.addMoveToBoard(1,'b','1');
    testBoard.addMoveToBoard(1,'b','3');
    testBoard.addMoveToBoard(1,'c','3');
    testBoard.addMoveToBoard(1,'c','1');
    try {
        testBoard.addMoveToBoard(1,'b','3');
    } catch (const UnavailableSlot&){
        caught++;
    }
    try {
        testBoard.addMoveToBoard(0,'a','2');
    } catch (const UnavailableSlot&){
        caught++;
    }
    testBoard.addMoveToBoard(0,'c','2');
    return caught==2;
}

bool board_checkWin_Hor()
{
    Board testBoard;
    int count = 0;
    testBoard.addMoveToBoard(1,'a','1');
    count += !(testBoard.checkWin('a','1'));
    testBoard.addMoveToBoard(1,'a','2');
    testBoard.addMoveToBoard(0,'b','2');
    count += !(testBoard.checkWin('a','1'));
    try {
        testBoard.checkWin('b', '3');
    } catch (const IllegalSlot&) {
        count++;
    }
    count += !(testBoard.checkWin('a','2'));
    testBoard.addMoveToBoard(1,'a','3');
    count += (testBoard.checkWin('a','1'));
    count += (testBoard.checkWin('a','2'));
    count += (testBoard.checkWin('a','3'));
    return count==7;
}

bool board_checkWin_Ver()
{
    Board testBoard;
    int count = 0;
    testBoard.addMoveToBoard(1,'a','1');
    count += !(testBoard.checkWin('a','1'));
    testBoard.addMoveToBoard(1,'b','1');
    testBoard.addMoveToBoard(0,'b','2');
    count += !(testBoard.checkWin('a','1'));
    try {
        testBoard.checkWin('b', '3');
    } catch (const IllegalSlot&) {
        count++;
    }
    count += !(testBoard.checkWin('a','1'));
    testBoard.addMoveToBoard(1,'c','1');
    count += (testBoard.checkWin('a','1'));
    count += (testBoard.checkWin('b','1'));
    count += (testBoard.checkWin('c','1'));
    return count==7;
}

bool board_checkWin_DiagLR()
{
    Board testBoard;
    int count = 0;
    testBoard.addMoveToBoard(1,'a','1');
    count += !(testBoard.checkWin('a','1'));
    testBoard.addMoveToBoard(1,'b','2');
    testBoard.addMoveToBoard(0,'b','1');
    count += !(testBoard.checkWin('a','1'));
    try {
        testBoard.checkWin('b', '3');
    } catch (const IllegalSlot&) {
        count++;
    }
    count += !(testBoard.checkWin('a','1'));
    testBoard.addMoveToBoard(1,'c','3');
    count += (testBoard.checkWin('a','1'));
    count += (testBoard.checkWin('b','2'));
    count += (testBoard.checkWin('c','3'));
    return count==7;
}

bool board_checkWin_DiagRL()
{
    Board testBoard;
    int count = 0;
    testBoard.addMoveToBoard(1,'c','1');
    count += !(testBoard.checkWin('c','1'));
    testBoard.addMoveToBoard(1,'b','2');
    testBoard.addMoveToBoard(0,'b','1');
    count += !(testBoard.checkWin('c','1'));
    try {
        testBoard.checkWin('b', '3');
    } catch (const IllegalSlot&) {
        count++;
    }
    count += !(testBoard.checkWin('c','1'));
    testBoard.addMoveToBoard(1,'a','3');
    count += (testBoard.checkWin('c','1'));
    count += (testBoard.checkWin('b','2'));
    count += (testBoard.checkWin('a','3'));
    return count==7;
}