#pragma once

#include <iostream>
#include <string>

#include "Grid.h"

class Player
{
    private:
        std::string name_;
        Grid* grid_;
    public:
        Player();
        ~Player();
        Grid* getGrid();
};
