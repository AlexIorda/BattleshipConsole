#include "RandomCpuPlayer.h"

RandomCpuPlayer::RandomCpuPlayer()
{
   //     grid_->printGrid();
    setupShip(2);
  //  grid_->printGrid();
/*    setupShip(3);
    grid_->printGrid();
    setupShip(3);
    grid_->printGrid();
    setupShip(4);
    grid_->printGrid();
    setupShip(5);
    grid_->printGrid(); */

    grid_->hideCells();
}

RandomCpuPlayer::~RandomCpuPlayer()
{
    for (Ship* ship: ships_)
        delete ship;
}

void RandomCpuPlayer::doMove(Grid* enemyGrid)
{
    srand(time(NULL));

    int row, col;

    do {
        row = rand() % enemyGrid->getGridSize();
        col = rand() % enemyGrid->getGridSize();
    } while (enemyGrid->getCell(row, col)->isHit());

    enemyGrid->getCell(row, col)->setHit(true);
    if (enemyGrid->getCell(row, col)->isShip())
            enemyGrid->hitShip();
}

void RandomCpuPlayer::setupShip(int shipSize)
{
    srand(time(NULL));
    Ship* ship;

    const char dirs[] = {'U', 'D', 'L', 'R'};
    char row, col, dir;
    do {
        row = '1' + rand() % grid_->getGridSize();
        col = 'A' + rand() % grid_->getGridSize();
        dir = dirs[rand() % 4];
    } while ((ship = validSetup(shipSize, row, col, dir)) == NULL);

    for (std::pair<int, int> coords: ship->getCoordList()) {
        grid_->placeShip();
        grid_->getCell(coords.first, coords.second)->setShip(true);
    }
    ships_.push_back(ship);
}
