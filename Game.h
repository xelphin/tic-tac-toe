#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <functional>
#include "./Board.h"
#include "./Player.h"
#include "./Exception.h"



class Game {

    public:
        static const int MAX_PLAYERS = 2;
        /*
        * C'tor of Game class
        *
        * @return
        *      A new instance of Game.
        */
        Game();

        /*
        * Get Sign
        *
        * @param signNumber - Digit of sign.
        * @return
        *      Character of requested sign.
        */
        char getSign(const int signNumber) const;

        /*
        * Add player to game
        *
        * @param name - Player's name.
        */
        void addPlayer(const std::string& name);

        /*
        * Print game.
        */
        friend std::ostream& operator<<(std::ostream& os, const Game& toPrint);

        Game(const Game& game) = delete;
        Game& operator=(const Game& game) = delete;

    private:
        int m_initPlayers = 0;
        std::vector<std::unique_ptr<Board>> m_boards;
        std::vector<std::unique_ptr<Player>> m_players;
        
};

#endif