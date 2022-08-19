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

char Game::getSign(const int signNumber) const
{
    switch(signNumber) {
    case 0:
        return 'X';
        break;
    case 1:
        return 'O';
        break;
    default:
        throw InvalidSign();
    }
}

void Game::addPlayer(const std::string& name)
{
    if (m_initPlayers > Game::MAX_PLAYERS-1) {
        throw OverflowPlayerAmount();
    }
    m_players.push_back((std::unique_ptr<Player>(new Player(name, m_initPlayers))));
    m_initPlayers++;
}