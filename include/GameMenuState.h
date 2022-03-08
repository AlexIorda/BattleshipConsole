#pragma once

#include <iostream>

#include "Menu.h"
#include "MainMenuState.h"

class GameMenuState : public MenuState
{
    public:
        bool printMenuHandle() const override;
};
