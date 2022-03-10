#include "HelpMenuState.h"

bool HelpMenuState::printMenuHandle() const {
    std::cout << "/----------------------------------------\\\n";
    std::cout << "Help\n\n";

    std::cout << "|Object of the game\n";
    std::cout << "Be the first to sink all 5 of your opponent's ships.\n\n";

    std::cout << "|Prepare for battle\n";
    std::cout << "Secretly place your fleet of 5 ships on your ocean\n";
    std::cout << "grid. To place each ship, specify where you anchor\n";
    std::cout << "it and towards which direction you would lay it\n";
    std::cout << "Rules for placing ships:\n";
    std::cout << "- Place each ship in any horizontal or vertical\n";
    std::cout << "  direction, but not diagonally\n";
    std::cout << "- The ship must fit within the grid\n";
    std::cout << "- Two ships cannot overlap\n\n";

    std::cout << "|How to play\n";
    std::cout << "Pick a coordinate to hit on the other player's grid. If\n";
    std::cout << "that coordinate has a ship there, that part of the ship\n";
    std::cout << "is destroyed. Destroy all of the ships to win";

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
