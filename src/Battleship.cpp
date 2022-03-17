#include "Battleship.h"

Battleship::Battleship()
{
    std::cout << "Setup Player 1:\n\n";
    player1 = new HumanPlayer();
    std::cout << "Setup ended.\n\n";
    std::cout << "Setup CPU:\n\n";
    player2 = new RandomCpuPlayer();
    std::cout << "Setup ended.\n\n";

    while (player1->getGrid()->hasHiddenShips()
           && player2->getGrid()->hasHiddenShips()) {
        if (!turn) {
            std::cout << "|Player turn|\n";
            player2->getGrid()->printGrid();
            player1->doMove(player2->getGrid());
//            player2->getGrid()->printGrid();

        }
        else {
            std::cout << "|CPU turn|\n";
            player2->doMove(player1->getGrid());
            player1->getGrid()->printGrid();
        }

        turn ^= 1;
    }

    if (turn) {
        std::cout << "\n\n";
        player2->getGrid()->printGrid();
        std::cout << "Player 1 wins!!!\n\n";
    }
    else {
        std::cout << "\n\n";
        player1->getGrid()->printGrid();
        std::cout << "Player 2 wins!!!\n\n";
    }
}

Battleship::~Battleship()
{
    delete player1;
    delete player2;
}
