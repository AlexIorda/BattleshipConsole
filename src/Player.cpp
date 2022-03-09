#include "Player.h"

Player::Player()
{
    grid_ = new Grid();
}

Player::~Player()
{
    delete grid_;
}

Grid* Player::getGrid()
{
    return grid_;
}
