#pragma once

#include "HumanPlayer.h"

class Battleship
{
    private:
        Player *player1, *player2;
        bool turn = 0;

    public:
        Battleship();
        virtual ~Battleship();
};
