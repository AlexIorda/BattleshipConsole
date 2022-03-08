#pragma once

#include <iostream>

#include "Menu.h"
#include "GameMenuState.h"
#include "HelpMenuState.h"

class MainMenuState : public MenuState
{
    public:
        bool printMenuHandle() const override;
};
