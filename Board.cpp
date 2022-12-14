#include "./Board.h"

Board::Board() :
    m_board(new int[LENGTH*LENGTH])
{
    for (int i=0; i<LENGTH*LENGTH; i++) {
        m_board[i] = Board::EMPTY_SLOT;
    }
}

void Board::addMoveToBoard(const int sign,const char col, const char row)
{
    int index = Board::inputToIndex(col, row);
    if(sign == Board::EMPTY_SLOT)
        throw InvalidSign();
    if(m_board[index] != Board::EMPTY_SLOT)
        throw UnavailableSlot();
    m_board[index] = sign;
    m_moves++;
}

bool Board::checkWin(const char verSpot, const char horSpot) const
{
    int col, row;
    Board::inputToColRow(verSpot, horSpot, col, row);
    int sign = m_board[colRowToIndex(col, row)];
    if (sign==Board::EMPTY_SLOT)
        throw IllegalSlot();
    if (m_board[colRowToIndex((col+1)%3, row)] == sign 
        && m_board[colRowToIndex((col+2)%3, row)] == sign){ // hor
        return true;
    }
    if (m_board[colRowToIndex(col, (row+1)%3)] == sign 
        && m_board[colRowToIndex(col, (row+2)%3)] == sign){ // ver
        return true;
    }
    if (col==row && m_board[colRowToIndex((col+1)%3, (row+1)%3)] == sign
        && m_board[colRowToIndex((col+2)%3, (row+2)%3)] == sign){ // diag lr
        return true;
    }
    if (col==2-row && m_board[colRowToIndex((col+2)%3, (row+1)%3)] == sign 
        && m_board[colRowToIndex((col+1)%3, (row+2)%3)] == sign){ // diag rl
        return true;
    }
    return false;
}

bool Board::checkEnd() const
{
    return m_moves == LENGTH*LENGTH;
}

int Board::inputToIndex(const char verSpot, const char horSpot) const
{
    int row, col;
    inputToColRow(verSpot, horSpot, row, col);
    int index = colRowToIndex(row, col);
    return index;
}

void Board::inputToColRow(const char verSpot, const char horSpot, int &row, int &col) const
{
    if (horSpot<'1' || horSpot>'3') 
        throw InvalidHorizontalArgument();
    if(verSpot<'a' ||verSpot>'c')
        throw InvalidVerticalArgument();
    row = (int)(horSpot-'1');
    col = (int)(verSpot-'a');
}

int Board::colRowToIndex(const int col, const int row) const
{
    int index = row*Board::LENGTH + col;
    if(index<0 || index>=LENGTH*LENGTH)
        throw IndexOutOfBounds(index);
    return index;
}

char Board::getSign(const int signNumber) const
{
    switch(signNumber) {
    case 0:
        return 'X';
        break;
    case 1:
        return 'O';
        break;
    case -1:
        return ' ';
        break;
    default:
        throw InvalidSign();
    }
}

std::ostream& operator<<(std::ostream& os, const Board& toPrint)
{
    os << " | a | b | c" << std::endl;
    for(int i=0; i<3; i++) {
        os << i+1;
        for(int j=0; j<3; j++) {
            os << "| ";
            int signNumber = toPrint.m_board[toPrint.colRowToIndex(i,j)];
            os << toPrint.getSign(signNumber) << " ";
        }
        os << std::endl;
    }
    os << std::endl;
    return os;
}