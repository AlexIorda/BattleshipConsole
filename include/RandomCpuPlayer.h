#pragma once

#include "Player.h"

class RandomCpuPlayer : public Player
{
    public:
        RandomCpuPlayer();
        ~RandomCpuPlayer();
        void doMove() override;

    private:
        void setupShip(int shipSize) override;
        Ship* validSetup(int shipSize, char row, char col, char dir) override;
};
