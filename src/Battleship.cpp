#include "Battleship.h"

Battleship::Battleship()
{
    std::cout << "Setup Player 1:\n\n";
    player1 = new Player();
    std::cout << "Setup Player 2:\n\n";
    player2 = new Player();
}

Battleship::~Battleship()
{
    delete player1;
    delete player2;
}
