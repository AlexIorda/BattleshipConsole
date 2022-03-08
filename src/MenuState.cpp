#include "MenuState.h"

MenuState::MenuState() {}

MenuState::~MenuState() {}

void MenuState::set_menu(Menu *menu)
{
    this->menu_ = menu;
}
