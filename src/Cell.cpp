#include "Cell.h"

Cell::Cell()
{

}

Cell::~Cell()
{

}

void Cell::setShip(bool isShip)
{
    isShip_ = isShip;
}

void Cell::setHit(bool isHit)
{
    isHit_ = isHit;
}

char Cell::getSymbol()
{
    if (!isHit_) return '?';
    if (isShip_) return 'X';
    return '.';
}

bool Cell::isShip()
{
    return isShip_;
}

bool Cell::isHit()
{
    return isHit_;
}
