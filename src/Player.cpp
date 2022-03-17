#include "Player.h"

Player::Player()
{
    grid_ = new Grid(4);
}

Player::~Player()
{
    delete grid_;
}

Grid* Player::getGrid()
{
    return grid_;
}

Ship* Player::validSetup(int shipSize, char row, char col, char dir)
{
    Ship* ship = new Ship(shipSize, row, col, dir);

    if (!ship->isValidCoord(ship->getEndCoord())) {
        std::cout << "This ship is not valid, try again!\n";
        return NULL;
    }

    for (std::pair<int, int> coords: ship->getCoordList())
        if (grid_->getCell(coords.first, coords.second)->isShip()) {
            std::cout << "Collision between ships, try again!\n";
            return NULL;
        }

    return ship;
}
