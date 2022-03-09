#pragma once

#include <vector>
#include <utility>
#include <tuple>

class Ship
{
    private:
        int start_x_, start_y_;
        int shipSize_;
        char dir_;

    public:
        Ship(int shipSize, char row, char col, char dir);
        std::pair<int, int> getEndCoord();
        std::vector<std::pair<int, int> > getCoordList();
        bool isValidCoord(std::pair<int, int> coords);
};
