#include "./Game.h"

Game::Game()
{
    Game::printTitle();
    while(m_initPlayers!=Game::MAX_PLAYERS) {
        std::cout << "Enter the name of the player" << std::endl;
        std::string userInput;
        std::getline(std::cin, userInput);
        this->addPlayer(userInput);
    }
    system("clear");
    Game::printTitle();
    Game::printMenu();
}

void Game::addPlayer(const std::string& name)
{
    if (m_initPlayers > Game::MAX_PLAYERS-1) {
        throw OverflowPlayerAmount();
    }
    if (m_initPlayers==0)
        this->m_player1=std::unique_ptr<Player>(new Player(name, m_initPlayers));
    else
        this->m_player2=std::unique_ptr<Player>(new Player(name, m_initPlayers));
    m_initPlayers++;
}

void Game::startGame()
{
    Board board;
    int finalState = Game::GAME_MIDDLE;
    while(!playTurn(board, finalState)){
        m_turn = (m_turn+1)%2;
    }
    if (finalState == Game::TIE) {
        std::cout << "It's a tie." << std::endl;
    } else {
        std::string name = !finalState ? (*m_player1).getName() : (*m_player2).getName();
        std::cout << "Congratulations " << name << ", you won the game!" << std::endl;
        !m_turn ? (*m_player1).addWin() : (*m_player2).addWin();
    }
    std::cout << board;
    m_turn = (m_turn+1)%2;
    Game::printMenu();
}

bool Game::playTurn(Board& board, int& finalState)
{
    std::string name;
    char sign;
    if(!m_turn) {
        name = (*m_player1).getName();
        sign = (*m_player1).getSign();
    } else {
        name = (*m_player2).getName();
        sign = (*m_player2).getSign();
    }
    std::cout << board;
    std::cout << "It's " << name << "'s turn. Please enter spot." << std::endl;
    std::string userInput;
    Game::getPlayerSpot(board, sign, userInput);
    bool end = false;
    if (board.checkWin(userInput[0], userInput[1])) {
        finalState = m_turn;
        end = true;
    } else if (board.checkEnd()) {
        finalState = Game::TIE;
        end = true;
    }
    return end;
}

void Game::getPlayerSpot(Board& board, const char sign, std::string& userInput)
{
    bool legalInput = false;
    while(userInput.length()!=2 || !legalInput) {
        std::getline(std::cin, userInput);
        if (userInput.length()!=2) {
            std::cout << "The spot identifier needs to be of format [letter of row][letter of col]" << std::endl;
            continue;
        }
        try {
            board.addMoveToBoard(sign, userInput[0],userInput[1]);
            legalInput = true;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
            legalInput = false;
        }
    }
}

void Game::printTitle() const 
{
    std::cout << "---------------------------" << std::endl; 
    std::cout << "------- TIC TAC TOE -------" << std::endl;
    std::cout << "---------------------------" << std::endl;
}

void Game::printInstructions()
{
    std::cout << "INSTRUCTIONS" << std::endl;
    std::cout << "- Aim: First to fill three slots horizontally/vertically/diagonally with your symbol." << std::endl;
    std::cout << "- Choose spot: you need to choose the column with the letter and row with a number" << std::endl;
    std::cout << "  For example: \"a2\" will choose the first column and second row." << std::endl;
    Game::printMenu();
}

void Game::printMenu()
{
    std::cout << "MENU: \"l\" - See leader board | \"p\" - Play a game | \"i\" - Instructions | \"e\" - Exit" << std::endl;
    Game::redirection();
}

void Game::printLeaderBoard()
{
    std::cout << "LEADER BOARD" << std::endl;
    std::cout << *m_player1;
    std::cout << *m_player2;
    Game::printMenu();
}

void Game::redirection() 
{
    std::string userInput;
    std::getline(std::cin, userInput);
    if(userInput.length()!=1) {
        std::cout << "Your input needs to be one character long (l/p/i/e)" << std::endl;
        Game::redirection();
    } else if (userInput!="l" && userInput!="p" && userInput!="i" && userInput!="e") {
        std::cout << "Your input needs to be one of the following: l/p/i/e" << std::endl;
        Game::redirection();
    } else {
        char ans = userInput[0];
        system("clear");
        Game::printTitle();
        switch(ans) {
            case 'l':
                Game::printLeaderBoard();
                break;
            case 'p':
                this->startGame();
                break;
            case 'i':
                Game::printInstructions();
                break;
            default:
                std::cout << "Goodbye." << std::endl;
        }
    }
}