#include <iostream>
#include <unordered_map>
#include <stdexcept>
#include <mutex>

#include "Menu.h"
#include "MainMenuState.h"

using namespace std;

int main()
{
    Menu *menu = new Menu(new MainMenuState);

    while (menu->printMenuRequest());
    delete menu;

    return 0;
}
