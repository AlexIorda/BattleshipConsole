#include "Grid.h"

Grid::Grid(int gridSize)
{
    gridSize_ = gridSize;
    cells_.resize(gridSize_, std::vector<Cell*>(gridSize_));

    for (auto& row: cells_)
        for (auto& cell: row)
            cell = new Cell();
}

Grid::~Grid()
{

}

void Grid::printGrid()
{
    std::cout << "  ";
    for (int i = 0; i < gridSize_; ++i)
        std::cout << (char)('A' + i) << " ";
    std::cout << '\n';

    for (int i = 0; i < gridSize_; ++i) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < gridSize_; ++j)
            std::cout << cells_[i][j]->getSymbol() << " ";
        std::cout << '\n';
    }
    std::cout << '\n';
}

void Grid::hideCells()
{
    for (int i = 0; i < gridSize_; i++)
        for (int j = 0; j < gridSize_; j++)
            cells_[i][j]->setHidden(true);
}

Cell* Grid::getCell(int row, int col)
{
    return cells_[row][col];
}

void Grid::hitShip()
{
    --hiddenShips_;
}

void Grid::placeShip()
{
    ++hiddenShips_;
}

bool Grid::hasHiddenShips()
{
    return hiddenShips_ != 0;
}

std::map<int, std::string> Grid::getShipNames()
{
    return shipNames_;
}

int Grid::getGridSize()
{
    return gridSize_;
}
