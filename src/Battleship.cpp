#include "Battleship.h"

Battleship::Battleship()
{
    std::cout << "Setup Player 1:\n\n";
    player1 = new Player();
    std::cout << "Setup Player 2:\n\n";
    player2 = new Player();

    while (player1->getGrid()->hasHiddenShips()
           && player2->getGrid()->hasHiddenShips()) {
        if (!turn) {
            std::cout << "|Player 1|\n";
            player2->getGrid()->printGrid();
            player1->doMove();
        }
        else {
            std::cout << "|Player 2|\n";
            player1->getGrid()->printGrid();
            player2->doMove();
        }

        turn ^= 1;
    }

    if (turn) {
        std::cout << "\n\n";
        player1->getGrid()->printGrid();
        std::cout << "Player 1 wins!!!\n\n";
    }
    else {
        std::cout << "\n\n";
        player2->getGrid()->printGrid();
        std::cout << "Player 2 wins!!!\n\n";
    }
}

Battleship::~Battleship()
{
    delete player1;
    delete player2;
}
