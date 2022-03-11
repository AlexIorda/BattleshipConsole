#pragma once

#include <string>

#include "Grid.h"
#include "Cell.h"

class Player
{
    protected:
        std::string name_;
        std::vector<Ship*> ships_;
        Grid* grid_;

    public:
        Player();
        virtual ~Player();
        Grid* getGrid();
        virtual void doMove() = 0;

    private:
        virtual void setupShip(int shipSize) = 0;
        virtual Ship* validSetup(int shipSize, char row, char col, char dir) = 0;
};
