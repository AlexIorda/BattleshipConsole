#pragma once

#include <string>

#include "Grid.h"
#include "Cell.h"

class Player
{
    protected:
        std::vector<Ship*> ships_;
        Grid* grid_;

    public:
        Player();
        virtual ~Player();
        Grid* getGrid();
        virtual void doMove(Grid* enemyGrid) = 0;

    private:
        virtual void setupShip(int shipSize) = 0;

    protected:
        Ship* validSetup(int shipSize, char row, char col, char dir);
};
