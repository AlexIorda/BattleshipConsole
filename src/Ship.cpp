#include "Ship.h"

Ship::Ship(int shipSize, char row, char col, char dir)
{
    start_x_ = row - '1';
    start_y_ = col - 'A';
    shipSize_ = shipSize;
    dir_ = dir;
}

std::pair<int, int> Ship::getEndCoord() {
    int end_x, end_y;
    switch(dir_) {
        case 'U': {
            end_x = start_x_ - shipSize_ + 1;
            end_y = start_y_;
            break;
        }
        case 'D': {
            end_x = start_x_ + shipSize_ - 1;
            end_y = start_y_;
            break;
        }
        case 'L': {
            end_x = start_x_;
            end_y = start_y_ - shipSize_ + 1;
            break;
        }
        case 'R': {
            end_x = start_x_;
            end_y = start_y_ + shipSize_ - 1;
            break;
        }
    }

    return {end_x, end_y};
}

std::vector<std::pair<int, int>> Ship::getCoordList()
{
    std::vector<std::pair<int, int>> coords;
    int start_x = start_x_, start_y = start_y_;
    int end_x, end_y;
    std::tie(end_x, end_y) = getEndCoord();

    if (start_x > end_x) std::swap(start_x, end_x);
    if (start_y > end_y) std::swap(start_y, end_y);

    for (int x = start_x; x <= end_x; ++x)
        for (int y = start_y; y <= end_y; ++y)
            coords.push_back({x, y});

    return coords;
}

bool Ship::isValidCoord(std::pair<int, int> coords)
{
    if (coords.first < 0 || coords.first > 8)
        return false;
    if (coords.second < 0 || coords.second > 8)
        return false;
    return true;
}
