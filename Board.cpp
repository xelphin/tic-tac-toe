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
    int index = Board::translateColRowToSlot(col, row);
    if(sign == Board::EMPTY_SLOT)
        throw IllegalSign();
    if(index<0 || index>=LENGTH*LENGTH)
        throw IndexOutOfBounds(index);
    if(m_board[index] != Board::EMPTY_SLOT)
        throw UnavailableSlot();
    m_board[index] = sign;
}

int Board::translateColRowToSlot(const char verSpot, const char horSpot) const
{
    int ver, hor;
    if (verSpot<'1' || verSpot>'3') 
        throw InvalidVerticalArgument();
    if(horSpot<'a' ||horSpot>'c')
        throw InvalidHorizontalArgument();
    ver = (int)(verSpot-'1');
    hor = (int)(horSpot-'a');
    return ver*Board::LENGTH + hor;
}
