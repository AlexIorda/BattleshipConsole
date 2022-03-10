#pragma once

class Cell
{
    private:
        bool isShip_ = false;
        bool isHit_ = true;

    public:
        Cell();
        ~Cell();
        void setShip(bool isShip);
        void setHit(bool isHit);
        bool isShip();
        bool isHit();
        char getSymbol();
};

