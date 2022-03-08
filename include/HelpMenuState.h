#pragma once

#include <iostream>

#include "Menu.h"
#include "MainMenuState.h"

class HelpMenuState : public MenuState
{
    public:
        bool printMenuHandle() const override;
};
