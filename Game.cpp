#include "./Game.h"

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
