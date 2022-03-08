#include "HelpMenuState.h"

bool HelpMenuState::printMenuHandle() const {
    std::cout << "/----------------------------------------\\\n";
    std::cout << "Help\n\n";
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
