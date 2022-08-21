#include "./Player.h"

Player::Player(const std::string name, const int sign) :
    m_name(name),
    m_sign(sign)
{}


std::string Player::getName()
{
    return m_name;
}

int Player::getSign()
{
    return m_sign;
}

void Player::addWin()
{
    m_wins++;
}