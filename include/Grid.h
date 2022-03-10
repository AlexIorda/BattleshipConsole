#pragma once

#include <vector>
#include <map>

#include "Ship.h"
#include "Cell.h"

#include <iostream>

class Grid
{
    private:
        int hiddenShips_ = 0;
        Cell *cells_[8][8];
        std::vector<Ship*> ships_;
        std::map<int, std::string> shipNames_ {
            {2, "Destroyer"},
            {3, "Submarine"},
            {4, "Battleship"},
            {5, "Carrier"}
        };

    public:
        Grid();
        ~Grid();
        void setupShip(int shipSize);
        void hideCells();
        void printGrid();
        Cell* getCell(int row, int col);
        bool validRow(std::string row);
        bool validCol(std::string col);
        void hitShip();
        bool hasHiddenShips();

    private:
        bool validDir(std::string dir);
        Ship* validSetup(int shipSize, char row, char col, char dir);
};
