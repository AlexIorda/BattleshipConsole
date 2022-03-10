#include "Player.h"

Player::Player()
{
    grid_ = new Grid();
    grid_->hideCells();
}

Player::~Player()
{
    delete grid_;
}

Grid* Player::getGrid()
{
    return grid_;
}

void Player::doMove()
{
    std::string row, col;

    std::cout << "Where do you thing their ship is?\n";
    do {
        do {std::cout << "> Row: "; std::cin >> row;} while (!grid_->validRow(row));
        do {std::cout << "> Col: "; std::cin >> col;} while (!grid_->validCol(col));
    } while (grid_->getCell(row[0] - '1', col[0] - 'A')->isHit());
    std::cout << "\n\n";

    grid_->getCell(row[0] - '1', col[0] - 'A')->setHit(true);
    if (grid_->getCell(row[0] - '1', col[0] - 'A')->isShip())
        grid_->hitShip();
}
