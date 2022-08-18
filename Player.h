#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Player {

    public:
        /*
        * C'tor of Player class.
        *
        * @return
        *      A new instance of Player.
        */
        Player(const std::string name, const int sign);

        /*
        * Add win.
        */
        void addWin();

        /*
        * Get player sign
        *
        * @return
        *      int version of sign.
        */
        int getSign();

        /*
        * Get player wins
        *
        * @return
        *      Amount of wins player has.
        */
        int getWins();

        friend std::ostream& operator<<(std::ostream& os, const Player& toPrint);

    private:

        std::string m_name;
        int m_sign;
        int m_wins;
};

#endif