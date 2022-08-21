#include "./Game.h"

#ifdef NDEBUG // I DONT want to debug
#define askPlayerName() (std::cout << "Enter the name of the player" << std::endl)
#else // I DO want to debug
void askPlayerName ();
#define askPlayerName() ((void)0) 
#endif

Game::Game()
{
    while(m_initPlayers!=Game::MAX_PLAYERS) {
        askPlayerName();
        std::string userInput;
        std::getline(std::cin, userInput);
        this->addPlayer(userInput);
    }
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
    while(!playTurn(board)){
        m_turn = (m_turn+1)%2;
    }
    std::string name = !m_turn ? (*m_player1).getName() : (*m_player2).getName();
    std::cout << "Congratulations " << name << ", you won the game!" << std::endl;
    std::cout << board;
    !m_turn ? (*m_player1).addWin() : (*m_player2).addWin();
    m_turn = (m_turn+1)%2;
    // TODO: add board to vector
}

bool Game::playTurn(Board& board)
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
    return board.checkWin(userInput[0], userInput[1]);
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