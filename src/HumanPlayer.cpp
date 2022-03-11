#include "HumanPlayer.h"

HumanPlayer::HumanPlayer()
{
    grid_->printGrid();
    setupShip(2);
    grid_->printGrid();
/*    setupShip(3);
    grid_->printGrid();
    setupShip(3);
    grid_->printGrid();
    setupShip(4);
    grid_->printGrid();
    setupShip(5);
    grid_->printGrid(); */
}

HumanPlayer::~HumanPlayer()
{
    for (Ship* ship: ships_)
        delete ship;
}

void HumanPlayer::doMove()
{
    std::string row, col;

    std::cout << "Where do you thing their ship is?\n";
    do {
        do {std::cout << "> Row: "; std::cin >> row;} while (!validRow(row));
        do {std::cout << "> Col: "; std::cin >> col;} while (!validCol(col));
    } while (grid_->getCell(row[0] - '1', col[0] - 'A')->isHit());
    std::cout << "\n\n";

    grid_->getCell(row[0] - '1', col[0] - 'A')->setHit(true);
    if (grid_->getCell(row[0] - '1', col[0] - 'A')->isShip())
        grid_->hitShip();
}

void HumanPlayer::setupShip(int shipSize)
{
    std::string row, col, dir;
    Ship* ship;

    std::cout << "Place your " << grid_->getShipNames().at(shipSize) << " (size " << shipSize << ")\n";
    do {
        do {std::cout << "> Row: "; std::cin >> row;} while (!validRow(row));
        do {std::cout << "> Col: "; std::cin >> col;} while (!validCol(col));
        do {std::cout << "> Up, Down, Left, Right? (U/D/L/R): "; std::cin >> dir;} while (!validDir(dir));
    } while ((ship = validSetup(shipSize, row[0], col[0], dir[0])) == NULL);

    for (std::pair<int, int> coords: ship->getCoordList()) {
        grid_->placeShip();
        grid_->getCell(coords.first, coords.second)->setShip(true);
    }
    ships_.push_back(ship);
}

bool HumanPlayer::validRow(std::string row)
{
    if (row.size() != 1) {
        std::cout << "Please enter one character!\n";
        return false;
    }
    if (row[0] < '0' || row[0] > '9') {
        std::cout << "Please enter a digit (0-9)!\n";
        return false;
    }
    return true;
}

bool HumanPlayer::validCol(std::string col)
{
    if (col.size() != 1) {
        std::cout << "Please enter one character!\n";
        return false;
    }
    if (col[0] < 'A' || col[0] > 'H') {
        std::cout << "Please enter a letter (A-G)!\n";
        return false;
    }
    return true;
}

bool HumanPlayer::validDir(std::string dir)
{
    if (dir.size() != 1) {
        std::cout << "Please enter one character!\n";
        return false;
    }
    if (dir[0] != 'U' && dir[0] != 'D' && dir[0] != 'L' && dir[0] != 'R') {
        std::cout << "Please enter a direction (U/D/L/R)!\n";
        return false;
    }
    return true;
}

Ship* HumanPlayer::validSetup(int shipSize, char row, char col, char dir)
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
