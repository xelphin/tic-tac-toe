#include "./Game.h"

Game::Game()
{
    while(m_initPlayers!=Game::MAX_PLAYERS) {
        std::cout << "Enter the name of the player" << std::endl;
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