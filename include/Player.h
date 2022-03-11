#pragma once

#include <iostream>
#include <string>

#include "Grid.h"
#include "Cell.h"

class Player
{
    private:
        std::string name_;
        std::vector<Ship*> ships_;
        Grid* grid_;

    public:
        Player();
        ~Player();
        Grid* getGrid();
        void doMove();

    private:
        void setupShip(int shipSize);
        bool validRow(std::string row);
        bool validCol(std::string col);
        bool validDir(std::string dir);
        Ship* validSetup(int shipSize, char row, char col, char dir);
};
