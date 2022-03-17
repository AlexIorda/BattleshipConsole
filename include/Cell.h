#pragma once

class Cell
{
    private:
        bool isShip_ = false;
        bool isHit_ = false;
        bool isHidden_ = false;

    public:
        Cell();
        ~Cell();
        void setShip(bool isShip);
        void setHit(bool isHit);
        void setHidden(bool isHidden);
        bool isShip();
        bool isHit();
        bool isHidden();
        char getSymbol();
};

