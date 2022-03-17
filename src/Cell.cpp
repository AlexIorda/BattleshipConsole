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

void Cell::setHidden(bool isHidden)
{
    isHidden_ = isHidden;
}

char Cell::getSymbol()
{
    if (isHidden_) return '?';
    if (isHit_) {
        if (isShip_) return 'X';
        else return 'x';
    }
    if (isShip_) return '#';
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

bool Cell::isHidden()
{
    return isHidden_;
}
