#pragma once

#include "HumanPlayer.h"
#include "RandomCpuPlayer.h"

class Battleship
{
    private:
        Player *player1, *player2;
        bool turn = 0;

    public:
        Battleship();
        virtual ~Battleship();
};
