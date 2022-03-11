#pragma once

#include <iostream>

#include "Player.h"

class HumanPlayer : public Player
{
    public:
        HumanPlayer();
        ~HumanPlayer();
        void doMove() override;

    private:
        void setupShip(int shipSize) override;
        bool validRow(std::string row);
        bool validCol(std::string col);
        bool validDir(std::string dir);
        Ship* validSetup(int shipSize, char row, char col, char dir) override;
};
