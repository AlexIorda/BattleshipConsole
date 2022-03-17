#pragma once

#include "Player.h"

#include <random>
#include <ctime>

class RandomCpuPlayer : public Player
{
    public:
        RandomCpuPlayer();
        ~RandomCpuPlayer();
        void doMove(Grid* enemyGrid) override;

    private:
        void setupShip(int shipSize) override;
};
