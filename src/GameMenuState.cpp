#include "GameMenuState.h"

bool GameMenuState::printMenuHandle() const
{
    std::cout << "/----------------------------------------\\\n";
    std::cout << "Not yet implemented\n\n";
    std::cout << "[B] Back\n";
    std::cout << "\\----------------------------------------/\n";
    std::cout << "> Select option: ";
    char option;
    std::cin >> option;
    switch (option) {
    case 'B':
    case 'b':
        this->menu_->changeState(new MainMenuState);
        return true;
    }
}
