#pragma once

#include "MenuState.h"

class Menu
{
    public:
        Menu(MenuState *state);
        virtual ~Menu();

        void changeState(MenuState *state);
        bool printMenuRequest();
    private:
        MenuState *state_;
};
