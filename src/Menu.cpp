#include "../include/Menu.h"

Menu::Menu(MenuState *state) : state_(nullptr) {
    this->changeState(state);
}

Menu::~Menu()
{
    delete state_;
}

void Menu::changeState(MenuState *state) {
    if (this->state_ != nullptr)
        delete this->state_;
    this->state_ = state;
    this->state_->set_menu(this);
}

bool Menu::printMenuRequest() {
    return this->state_->printMenuHandle();
}
