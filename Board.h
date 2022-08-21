#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>
#include "./Exception.h"

class Board {

    public:
        /*
        * C'tor of Board class
        *
        * @return
        *      A new instance of Board.
        */
        Board();

        /*
        * Add Move to Board
        *
        * @param sign - Player's sign.
        * @param col - Column where to place sign.
        * @param row - Row where to place sign.
        * @return
        *      True: Move has been successfully added | False: Failed to add move
        */
        void addMoveToBoard(const int sign,const char col, const char row);

        /*
        * Check whether move has caused a win
        *
        * @param verSpot - Column where move took place.
        * @param horSpot - Row where move took place.
        * @return
        *      True: There is a win from move | False: There is no win from move
        */
        bool checkWin(const char verSpot, const char horSpot) const;

        /*
        * Check whether game has reached an end (all slots filled).
        *
        * @return
        *      True: Reached end | False: Hasn't reached end.     
        */  
        bool checkEnd() const;

        /*
        * Get Sign
        *
        * @param signNumber - Digit of sign.
        * @return
        *      Character of requested sign.
        */
        char getSign(const int signNumber) const;

        /*
        * Clear board.
        */
        void clearBoard();

        /*
        * Print board.
        */
        friend std::ostream& operator<<(std::ostream& os, const Board& toPrint);

        Board(const Board& board) = delete;
        Board& operator=(const Board& board) = delete;

    private:
        static const int EMPTY_SLOT = -1;
        static const int LENGTH = 3;

        /*
        * Board array
        * m_length*m_length sized array that saves the moves the players have made.
        */
        int* m_board;

        /*
        * Amount of moves that have been taken.
        */
        int m_moves = 0;

        /*
        * Translate verSpot/horSpot string into index inside of m_board
        *
        * @param verSpot - Vertical character.
        * @param horSpot - Horizontal character.
        * @return
        *      Index of verSpot/horSpot inside of m_length*m_length array
        */
        int inputToIndex(const char verSpot, const char horSpot) const;

        /*
        * Translate verSpot/horSpot string into row/col 
        *
        * @param verSpot - Vertical character.
        * @param horSpot - Horizontal character.
        * @param row - Reference to row number.
        * @param col - Reference to col number.
        */
        void inputToColRow(const char verSpot, const char horSpot, int &row, int &col) const;

        /*
        * Translate row/col into index inside of m_board
        *
        * @param col - Chosen col.
        * @param row - Chosen row.
        * @return
        *      Index of col/row inside of m_length*m_length array
        */
        int colRowToIndex(const int col, const int row) const;

};

#endif