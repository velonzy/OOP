#include "Game.h"
#include <cstdlib>

Game::Game() = default;

void Game::startGame() {
    int file, console;
    std::cout << "Choose loging method: file, console. 1 is for true, 0 is for false" << std::endl;
    std::cin >> file >> console;
    Logger logger(file, console);
    Board board(30, 15);
    int start_x = board.getStart()->getX();
    int start_y = board.getStart()->getY();

    board.printBoard();

    Player player(start_x, start_y + 1);
    board.setObject(player.getX(), player.getY(), 'p');
    Cell* player_place = board.getCell(player_place->getX(), player_place->getY());
    player.setMaxHP(10000);
    player.setHP(3000);
    player.setAttack(1000);
    //logger.checkObject(&player);


    CalmEnemy first;
    first.setX(std::rand() % (board.getWidth() - 2) + 1);
    first.setY(board.getHeight() / 3);
    board.setObject(first.getX(), first.getY(), 'f');
    Cell* first_place = board.getCell(first.getX(), first.getY());
    first.setHP(1000);
    first.setAttack(300);

    AngryEnemy second;
    second.setX(std::rand() % (board.getWidth() - 2) + 1);
    second.setY((board.getHeight() / 3) * 2);
    board.setObject(second.getX(), second.getY(), 's');
    Cell* second_place = board.getCell(second.getX(), second.getY());
    second.setHP(2500);
    second.setAttack(800);

    Boss third;
    third.setX(board.getFinish()->getX());
    third.setY(board.getFinish()->getY() - 1);
    board.setObject(third.getX(), third.getY(), 't');
    Cell* third_place = board.getCell(third.getX(), third.getY());
    third.setHP(6000);
    third.setAttack(2500);

    Sword sword;
    sword.setX(2);
    sword.setY(3);
    board.setObject(sword.getX(), sword.getY(), '!');
    Cell* sword_place = board.getCell(sword.getX(), sword.getY());
    sword.setAttack(std::rand() % 300 + 1000);
    sword.setHeal(0);
    //logger.checkObject(&sword);

    Diadem diadem;
    diadem.setX(25);
    diadem.setY(7);
    board.setObject(diadem.getX(), diadem.getY(), '@');
    Cell* diadem_place = board.getCell(diadem.getX(), diadem.getY());
    diadem.setAttack(std::rand() % 300 + 200);
    diadem.setHeal(std::rand() % 300 + 1000);

    KnightCup cup;
    cup.setX(15);
    cup.setY(12);
    board.setObject(cup.getX(), cup.getY(), 'U');
    Cell* cup_place = board.getCell(cup.getX(), cup.getY());
    cup.setAttack(0);
    cup.setHeal(std::rand() % 500 + 1500);

    board.printBoard();

    //enemyMove(&board, first_place, &first, 1, 0, 'f', &logger);
    BossMove(&board, third_place, &third, &logger);
    //board.printBoard();

}


void Game::enemyMove(Board* board, Cell *place, Enemy *enemy, int move_x, int move_y, char type, Logger *logger) {
    Cell* checkCell;
    checkCell = board->getCell(place->getX() + move_x, place->getY() + move_y);
    while (checkCell->getType() == ' ') {
        if (checkCell->getType() == 'p')
            return;
        place->setType(' ');
        place = checkCell;
        place->setType(type);
        checkCell = board->getCell(place->getX() + move_x, place->getY() + move_y);
        board->printBoard();
        enemy->setX(place->getX());
        enemy->setY(place->getY());
        logger->checkObject(enemy);
    }
    if (checkCell->getType() == 'p')
        return;
    move_x *= (-1);
    move_y *= (-1);
    enemyMove(board, place, enemy, move_x, move_y, type, logger);
}

bool Game::fighting(Player* player, Enemy* enemy, Logger *logger) {
    while(enemy->getStatus() && player->getStatus()){
        enemy->setHP(player->getAttack());
        player->setHP(enemy->getAttack());
        if(player->getHP() <= 0){
            player->getKilled();
            logger->checkObject(player);
            return false;
        }
        if(enemy->getHP() <= 0){
            enemy->getKilled();
            logger->checkObject(enemy);
            return true;
        }
    }
}

void Game::takeObject(Player* player, Item* object, Logger *logger){
    player->heal(object->checkHeal());
    player->strengthening(object->checkAttack());
    logger->checkObject(player);
    object->changeStatus();
}

bool Game::checkEnemy(Board *board, Cell* place) {
    Cell* checkCell;
    checkCell = board->getCell(place->getX() - 1, place->getY() - 1);
    if (checkCell->getType() == 'f' || checkCell->getType() == 's' || checkCell->getType() == 't')
        return true;

    checkCell = board->getCell(place->getX(), place->getY() - 1);
    if (checkCell->getType() == 'f' || checkCell->getType() == 's' || checkCell->getType() == 't')
        return true;

    checkCell = board->getCell(place->getX() + 1, place->getY() -1);
    if (checkCell->getType() == 'f' || checkCell->getType() == 's' || checkCell->getType() == 't')
        return true;

    checkCell = board->getCell(place->getX() + 1, place->getY());
    if (checkCell->getType() == 'f' || checkCell->getType() == 's' || checkCell->getType() == 't')
        return true;

    checkCell = board->getCell(place->getX() + 1, place->getY() + 1);
    if (checkCell->getType() == 'f' || checkCell->getType() == 's' || checkCell->getType() == 't')
        return true;

    checkCell = board->getCell(place->getX(), place->getY() + 1);
    if (checkCell->getType() == 'f' || checkCell->getType() == 's' || checkCell->getType() == 't')
        return true;

    checkCell = board->getCell(place->getX() - 1, place->getY() + 1);
    if (checkCell->getType() == 'f' || checkCell->getType() == 's' || checkCell->getType() == 't')
        return true;

    checkCell = board->getCell(place->getX() - 1, place->getY());
    if (checkCell->getType() == 'f' || checkCell->getType() == 's' || checkCell->getType() == 't')
        return true;

    return false;
}

bool Game::checkPlayer(Board *board, Cell* place){
    Cell* checkCell;
    checkCell = board->getCell(place->getX() - 1, place->getY() - 1);
    if (checkCell->getType() == 'p')
        return true;

    checkCell = board->getCell(place->getX(), place->getY() - 1);
    if (checkCell->getType() == 'p')
        return true;

    checkCell = board->getCell(place->getX() + 1, place->getY() -1);
    if (checkCell->getType() == 'p')
        return true;

    checkCell = board->getCell(place->getX() + 1, place->getY());
    if (checkCell->getType() == 'p')
        return true;

    checkCell = board->getCell(place->getX() + 1, place->getY() + 1);
    if (checkCell->getType() == 'p')
        return true;

    checkCell = board->getCell(place->getX(), place->getY() + 1);
    if (checkCell->getType() == 'p')
        return true;

    checkCell = board->getCell(place->getX() - 1, place->getY() + 1);
    if (checkCell->getType() == 'p')
        return true;

    checkCell = board->getCell(place->getX() - 1, place->getY());
    if (checkCell->getType() == 'p')
        return true;

    return false;
}

void Game::BossMove(Board *board, Cell *place, Enemy* boss, Logger *logger) {
    int move_x, move_y;
    int step = 1;
    while (!checkPlayer(board, place)) {
        place->setType(' ');
        if (step == 1){
            move_x = -1;
            move_y = 0;
        }
        if (step == 2){
            move_x = 0;
            move_y = -1;
        }
        if (step == 3){
            move_x = 1;
            move_y = 0;
        }
        if(step == 4){
            move_x = 1;
            move_y = 0;
        }
        if (step == 5){
            move_x = 0;
            move_y = 1;
        }
        if (step == 6){
            move_x = -1;
            move_y = 0;
            step = 1;
        } else {
            step ++;
        }
        place = board->getCell(place->getX() + move_x, place->getY() + move_y);
        boss->setX(place->getX());
        boss->setY(place->getY());
        logger->checkObject(boss);
        place->setType('t');
        board->printBoard();
    }
}

std::string Game::victory(Board *board, Player* player, Logger *logger){
    if(player->getX() == board->getFinish()->getX() &&
            player->getY() + 1 == board->getFinish()->getY()){
        std::cout << "You win!!";
    }
}