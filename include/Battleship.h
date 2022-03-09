#pragma once

#include "Player.h"

class Battleship
{
    private:
        Player *player1, *player2;
        bool turn = 0;

    public:
        Battleship();
        ~Battleship();
};
