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
        * Add player to game
        *
        * @param name - Player's name.
        */
        void addPlayer(const std::string& name);

        /*
        * Starts a Tic-Tac-Toe game between two players
        */
        void startGame();



        /*
        * Print game.
        */
        friend std::ostream& operator<<(std::ostream& os, const Game& toPrint);

        Game(const Game& game) = delete;
        Game& operator=(const Game& game) = delete;

    private:
        int m_initPlayers = 0;
        int m_turn = 0;
        std::vector<std::unique_ptr<Board>> m_boards;
        std::unique_ptr<Player> m_player1;
        std::unique_ptr<Player> m_player2;

        /*
        * Play a turn in game.
        */
        bool playTurn(Board& board);

        /*
        * Play a turn in game.
        */
        void getPlayerSpot(Board& board, const char sign, std::string& userInput);
};

#endif