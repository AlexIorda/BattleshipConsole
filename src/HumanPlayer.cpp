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

//    grid_->hideCells();
}

HumanPlayer::~HumanPlayer()
{
    for (Ship* ship: ships_)
        delete ship;
}

void HumanPlayer::doMove(Grid* enemyGrid)
{
    std::string row, col;

    std::cout << "Where do you think their ship is?\n";
    do {
        do {std::cout << "> Row: "; std::cin >> row;} while (!validRow(row));
        do {std::cout << "> Col: "; std::cin >> col;} while (!validCol(col));
    } while (enemyGrid->getCell(row[0] - '1', col[0] - 'A')->isHit());
    std::cout << "\n\n";

    enemyGrid->getCell(row[0] - '1', col[0] - 'A')->setHit(true);
    enemyGrid->getCell(row[0] - '1', col[0] - 'A')->setHidden(false);
    if (enemyGrid->getCell(row[0] - '1', col[0] - 'A')->isShip())
        enemyGrid->hitShip();
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
    if (col[0] < 'A' || col[0] > 'A' + grid_->getGridSize()) {
        std::cout << "Please enter a letter (A-" << 'A' + grid_->getGridSize() << ")!\n";
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
