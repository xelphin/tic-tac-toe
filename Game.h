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
        * Print Title
        */
        void printTitle() const;

        /*
        * Print Instructions
        */
        void printInstructions() ;

        /*
        * Print Menu
        */
        void printMenu();

        /*
        * Print Leader Board
        */
        void printLeaderBoard() ;

        /*
        * Print game.
        */
        friend std::ostream& operator<<(std::ostream& os, const Game& toPrint);

        Game(const Game& game) = delete;
        Game& operator=(const Game& game) = delete;

    private:
        int m_initPlayers = 0;
        int m_turn = 0;
        std::unique_ptr<Player> m_player1;
        std::unique_ptr<Player> m_player2;
        static const int GAME_MIDDLE = -1;
        static const int PLAYER1_WON = 0;
        static const int PLAYER2_WON = 1;
        static const int TIE = 2;

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
        * Play a turn in game.
        * @param board - Board we are playing on.
        * @return
        *      True: Game has ended | False: Game continues
        */
        bool playTurn(Board& board, int& finalState);

        /*
        * Play a turn in game.
        */
        void getPlayerSpot(Board& board, const char sign, std::string& userInput);

        /*
        * Redirection.
        */
        void redirection();
};

#endif