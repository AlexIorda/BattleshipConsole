#include "MainMenuState.h"

bool MainMenuState::printMenuHandle() const {
    std::cout << "/----------------------------------------\\\n";
    std::cout << "My Game\n\n";
    std::cout << "[S] Start\n";
    std::cout << "[H] Help\n";
    std::cout << "[E] Exit\n";
    std::cout << "\\----------------------------------------/\n";
    std::cout << "> Select option: ";
    char option;
    std::cin >> option;
    switch (option) {
        case 'S':
        case 's':
            this->menu_->changeState(new GameMenuState);
            return true;
        case 'H':
        case 'h':
            this->menu_->changeState(new HelpMenuState);
            return true;
        case 'E':
        case 'e':
            return false;
    }
}
