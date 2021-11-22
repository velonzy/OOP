#ifndef UNTITLED7_GAME_H
#define UNTITLED7_GAME_H
#include "Board.h"
#include "CalmEnemy.h"
#include "Boss.h"
#include "AngryEnemy.h"
#include "Diadem.h"
#include "Sword.h"
#include "KnightCup.h"
#include "Logger.h"
#include <cstdlib>

class Game {
public:
    Game();
    void startGame();
private:
    void enemyMove(Board* board, Cell* place, Enemy* enemy, int move_x, int move_y, char type, Logger *logger); //для CalmEnemy и AngryEnemy
    void BossMove(Board* board, Cell* place, Enemy* enemy, Logger *logger); //передвижение объекта Boss
    bool fighting(Player* player, Enemy* enemy, Logger *logger);
    void takeObject(Player* player, Item* object, Logger *logger);
    bool checkEnemy(Board *board, Cell* place);
    bool checkPlayer(Board *board, Cell *place);
    std::string victory(Board *board, Player* player, Logger *logger);
    //void playerMoving(Board *board, Player* player, Cell* place, int dir_x, int dir_y, Logger *logger);
};


#endif //UNTITLED7_GAME_H
