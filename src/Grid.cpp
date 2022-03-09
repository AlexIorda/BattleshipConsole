#include "Grid.h"

Grid::Grid()
{
    printGrid();
    setupShip(2);
    printGrid();
    setupShip(3);
    printGrid();
    setupShip(3);
    printGrid();
    setupShip(4);
    printGrid();
    setupShip(5);
    printGrid();

    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            cells_[i][j] = Cell();

    for (Ship* ship: ships_)
        for (std::pair<int, int> coords: ship->getCoordList())
            cells_[coords.first][coords.second].content = 8;
}

Grid::~Grid()
{
    for (Ship* ship: ships_)
        delete ship;
}

void Grid::setupShip(int shipSize)
{
    std::string row, col, dir;
    Ship* ship;

    std::cout << "Place your " << shipNames_.at(shipSize) << " (size " << shipSize << ")\n";
    do {
        do {std::cout << "> Row: "; std::cin >> row;} while (!validRow(row));
        do {std::cout << "> Col: "; std::cin >> col;} while (!validCol(col));
        do {std::cout << "> Up, Down, Left, Right? (U/D/L/R): "; std::cin >> dir;} while (!validDir(dir));
    } while ((ship = validSetup(shipSize, row[0], col[0], dir[0])) == NULL);

    ships_.push_back(new Ship(shipSize, row[0], col[0], dir[0]));
}

bool Grid::validRow(std::string row)
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

bool Grid::validCol(std::string col)
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

bool Grid::validDir(std::string dir)
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

Ship* Grid::validSetup(int shipSize, char row, char col, char dir)
{
    Ship* ship = new Ship(shipSize, row, col, dir);
    if (ship->isValidCoord(ship->getEndCoord()))
        return ship;
    std::cout << "This ship is not valid, try again!\n";
    return NULL;
}

void Grid::printGrid()
{
    for (Ship* ship: ships_)
        for (std::pair<int, int> coords: ship->getCoordList())
            cells_[coords.first][coords.second].content = 8;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j)
            std::cout << cells_[i][j].content << " ";
        std::cout << '\n';
    }
    std::cout << '\n';
}
