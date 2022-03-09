#include <iostream>

#include "Menu.h"
#include "MainMenuState.h"

int main()
{
    Menu *menu = new Menu(new MainMenuState);

    while (menu->printMenuRequest());

    delete menu;

    return 0;
}
