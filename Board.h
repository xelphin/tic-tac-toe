#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>

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
        bool addMoveToBoard(const int sign,const std::string col, const std::string row);

        /*
        * Check whether move has caused a win
        *
        * @param col - Column where move took place.
        * @param row - Row where move took place.
        * @return
        *      True: There is a win from move | False: There is no win from move
        */
        bool checkWin(const std::string col, const std::string row) const;

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
        static const int m_empty_slot = -1;
        static const int m_length = 3;

        /*
        * Board array
        * m_length*m_length sized array that saves the moves the players have made.
        */
        int* m_board;

        /*
        * Translate col/row string into index inside of m_board
        *
        * @param col - Column.
        * @param row - Row.
        * @return
        *      Index of col/row inside of m_length*m_length array
        */
        int translateColRowToSlot(const std::string verSpot, const std::string horSpot) const;
};

#endif