#pragma once

#include <iostream>
#include <vector>
#include <map>

#include "Ship.h"
#include "Cell.h"

class Grid
{
    private:
        int gridSize_;
        int hiddenShips_ = 0;
        std::vector<std::vector<Cell*>> cells_;
        std::map<int, std::string> shipNames_ {
            {2, "Destroyer"},
            {3, "Submarine"},
            {4, "Battleship"},
            {5, "Carrier"}
        };

    public:
        Grid(int gridSize = 8);
        ~Grid();
        void hideCells();
        void printGrid();
        Cell* getCell(int row, int col);
        void hitShip();
        void placeShip();
        bool hasHiddenShips();
        std::map<int, std::string> getShipNames();
};
