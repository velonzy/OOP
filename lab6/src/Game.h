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
#include <vector>
#include <functional>
#include "GameControl.h"
#include <cmath>
#include <string>
#include <iomanip>
#include <stdlib.h>

template<int angryEn, int calmEn, int numSw, int numDi, int numCu, int set_width, int set_height>
class Game {
public:
    Game() = default;
    std::vector<CalmEnemy*> calmEnemies;
    std::vector<AngryEnemy*> angryEnemies;
    std::vector<Item*> objects;
    std::vector<int> numOfObjects;
    GameControl* control;
private:
    void makeInfo(int swords, int diadems, int cups) {
        numOfObjects.push_back(swords);
        numOfObjects.push_back(diadems);
        numOfObjects.push_back(cups);
        //std::cout << numOfObjects[0] << " " << numOfObjects[1] << " " << numOfObjects[2] << std::endl;
    }
    void enemyMove(Board* board, Enemy *enemy, char type, Logger *logger) {
        Cell *place = board->getCell(enemy->getX(), enemy->getY());
        Cell* checkCell;
        std::pair<int, int> dir = enemy->getDir();
        checkCell = board->getCell(place->getX() + dir.first, place->getY() + dir.second);
        if(checkCell->getType() == 'p'){
            return;
        }
        if(checkCell->getType() != ' '){
            dir.first *= (-1);
            dir.second *= (-1);
            enemy->setDir(dir.first, dir.second);
            checkCell = board->getCell(place->getX() + dir.first, place->getY() + dir.second);
        }
        place->setType(' ');
        place = checkCell;
        place->setType(type);
        enemy->setX(place->getX());
        enemy->setY(place->getY());
        logger->checkObject(enemy);
    }

    bool fighting(Board* board, Player* player, Enemy* enemy, Logger *logger) {
        while(enemy->getStatus() && player->getStatus()){
            enemy->setDamage(player->getAttack());
            player->setDamage(enemy->getAttack());
            logger->checkObject(player);
            logger->checkObject(enemy);
            if(player->getHP() <= 0){
                player->getKilled();
                board->getCell(player->getX(), player->getY())->setType(' ');
                logger->checkObject(player);
                return false;
            }
            if(enemy->getHP() <= 0){
                enemy->getKilled();
                board->getCell(enemy->getX(), enemy->getY())->setType(' ');
                logger->checkObject(enemy);
                return true;
            }
        }
    }

    void takeObject(Board* board, Player* player, Item* object, Logger *logger){
        player->heal(object->checkHeal());
        player->strengthening(object->checkAttack());
        logger->checkObject(player);
        Cell* cell = board->getCell(object->getX(), object->getY());
        if(cell->getType() == '!'){
            numOfObjects[0]--;
        }else if(cell->getType() == '@'){
            numOfObjects[1]--;
        }else if(cell->getType() == 'U'){
            numOfObjects[2]--;
        }
        board->getCell(object->getX(), object->getY())->setType(' ');
        object->changeStatus();
    }

    void checkObject(Board* board, Player* player, Logger* logger){
        int i = 0;
        while(i < objects.size()){
            int object_x = objects[i]->getX(), object_y = objects[i]->getY();
            int player_x = player->getX(), player_y = player->getY();
            object_x -= player_x;
            object_y -= player_y;
            if (std::abs(object_x) <= 1 && std::abs(object_y) <= 1){
                takeObject(board, player, objects[i], logger);
                objects.erase(objects.begin() + i);
            } else {
                i++;
            }
        }
    }

    bool checkCharacter(Enemy* enemy, Player* player){
        int enemy_x = enemy->getX(), enemy_y = enemy->getY();
        int player_x = player->getX(), player_y = player->getY();
        enemy_x -= player_x;
        enemy_y -= player_y;
        if (std::abs(enemy_x) <= 1 && std::abs(enemy_y) <= 1){
            return true;
        }
        return false;
    }

    void BossMove(Board *board, Enemy* boss, Logger *logger) {
        Cell* finish = board->getFinish();
        Cell* place = board->getCell(boss->getX(), boss->getY());
        int move_x, move_y;
        place->setType(' ');
        if (finish->getX() == place->getX() && finish->getY() - 1 == place->getY()){
            move_x = -1;
            move_y = 0;
        } else if (finish->getX() - 1 == place->getX() && finish->getY() - 1 == place->getY()){
            move_x = 0;
            move_y = -1;
        }else if (finish->getX() - 1 == place->getX() && finish->getY() - 2 == place->getY()){
            move_x = 1;
            move_y = 0;
        }else if(finish->getX() == place->getX() && finish->getY() - 2 == place->getY()){
            move_x = 1;
            move_y = 0;
        }else if (finish->getX() + 1 == place->getX() && finish->getY() - 2 == place->getY()){
            move_x = 0;
            move_y = 1;
        }else if (finish->getX() + 1 == place->getX() && finish->getY() - 1 == place->getY()){
            move_x = -1;
            move_y = 0;
        }
        place = board->getCell(place->getX() + move_x, place->getY() + move_y);
        boss->setX(place->getX());
        boss->setY(place->getY());
        logger->checkObject(boss);
        place->setType('t');
    }
    void makeCalmEnemies(int size, Board* board, Logger* logger){
        for(int i = 0; i < size; i++){
            calmEnemies.push_back(new CalmEnemy());
            calmEnemies[i]->setX(std::rand() % (board->getWidth() - 2) + 1);
            calmEnemies[i]->setY(board->getHeight() / 3);
            calmEnemies[i]->setDir(1, 0);
            board->setObject(calmEnemies[i]->getX(), calmEnemies[i]->getY(), 'f');
            calmEnemies[i]->setHP(std::rand() % 500 + 300);
            calmEnemies[i]->setAttack(std::rand() % 300 + 200);
            logger->template checkObject(calmEnemies[i]);
        }
    }
    void makeAngryEnemies(int size, Board* board, Logger* logger){
        for(int i = 0; i < size; i++){
            angryEnemies.push_back(new AngryEnemy());
            angryEnemies[i]->setX(std::rand() % (board->getWidth() - 2) + 1);
            angryEnemies[i]->setY((board->getHeight() / 3) * 2);
            angryEnemies[i]->setDir(0, 1);
            board->setObject(angryEnemies[i]->getX(), angryEnemies[i]->getY(), 's');
            angryEnemies[i]->setHP(std::rand() % 1500 + 500);
            angryEnemies[i]->setAttack(std::rand() % 800 + 400);
            logger->template checkObject(angryEnemies[i]);
        }
    }

    void makeObjects(Board* board, Logger* logger){
        for(int i = 0; i < numOfObjects[0]; i++) {
            objects.push_back(new Sword());
            objects[i]->setX(std::rand() % (board->getWidth() - 2) + 1);
            objects[i]->setY(std::rand() % (board->getHeight() / 4) + 1);
            board->setObject(objects[i]->getX(), objects[i]->getY(), '!');
            objects[i]->setAttack(std::rand() % 300 + 1500);
            objects[i]->setHeal(0);
            logger->template checkObject(objects[i]);
        }
        for(int i = numOfObjects[0]; i < numOfObjects[1] + numOfObjects[0]; i++) {
            objects.push_back(new Diadem());
            objects[i]->setX(std::rand() % (board->getWidth() - 2) + 1);
            objects[i]->setY(std::rand() % ((board->getHeight() / 4) * 2));
            board->setObject(objects[i]->getX(), objects[i]->getY(), '@');
            objects[i]->setAttack(std::rand() % 300 + 300);
            objects[i]->setHeal(std::rand() % 300 + 1500);
            logger->template checkObject(objects[i]);
        }
        for(int i = numOfObjects[1] + numOfObjects[0]; i < numOfObjects[2] + numOfObjects[1] + numOfObjects[0]; i++) {
            objects.push_back(new KnightCup());
            objects[i]->setX(std::rand() % (board->getWidth() - 2) + 1);
            objects[i]->setY(std::rand() % (board->getHeight() - 2) + 1);
            board->setObject(objects[i]->getX(), objects[i]->getY(), 'U');
            objects[i]->setAttack(0);
            objects[i]->setHeal(std::rand() % 500 + 2500);
            logger->template checkObject(objects[i]);
        }
    }
    void moving(Board* board, Player* player, Boss* boss, Logger* logger){
        bool alive = true;
        while(player->getStatus() || (player->getX() == board->getFinish()->getX() &&
                                      player->getY() + 1 == board->getFinish()->getY())){
            playerMoving(board, player, logger);
            checkObject(board, player, logger);
            if(boss->getStatus()){
                BossMove(board, boss, logger);
                if(checkCharacter(boss, player)){
                    board->printBoard();
                    if(fighting(board, player, boss, logger)){
                        board->getCell(boss->getX(), boss->getY())->setType(' ');
                        boss->getKilled();
                    }else {
                        std::cout << "You are killed......" << std::endl;
                        alive = false;
                        break;
                    }
                }
            }
            int i = 0;
            while(i < calmEnemies.size()){
                enemyMove(board, calmEnemies[i], 'f', logger);
                if (checkCharacter(calmEnemies[i], player)){
                    board->printBoard();
                    if(fighting(board, player, calmEnemies[i], logger)){
                        calmEnemies.erase(calmEnemies.begin() + i);
                    }
                } else {
                    i++;
                }
            }
            i = 0;
            while(i < angryEnemies.size()){
                enemyMove(board, angryEnemies[i], 's', logger);
                if (checkCharacter(angryEnemies[i], player)){
                    if(fighting(board, player, angryEnemies[i], logger)){
                        angryEnemies.erase(angryEnemies.begin() + i);
                    }
                } else {
                    i++;
                }
            }
            if(player->getX() == board->getFinish()->getX() &&
               player->getY() + 1 == board->getFinish()->getY()){
                std::cout << "You win!!";
            }
            board->printBoard();
            writeInFile(board, player, boss);
        }
    }
    void playerMoving(Board *board, Player* player, Logger *logger){
        std::pair<int, int> move;
        move = control->step();
        Cell* check_place = board->getCell(player->getX() + move.first, player->getY() + move.second);
        while(check_place->getType() == '#' || check_place->getType() == '0'){
            std::cout << "Oops.... You want to go through the wall, try again" << std::endl;
            move = control->step();
            check_place = board->getCell(player->getX() + move.first, player->getY() + move.second);
        }
        Cell* current_place = board->getCell(player->getX(), player->getY());
        current_place->setType(' ');
        player->setX(current_place->getX() + move.first);
        player->setY(current_place->getY() + move.second);
        current_place = board->getCell(player->getX(), player->getY());
        current_place->setType('p');
        logger->template checkObject(player);
    }

    void writeInFile(Board* board, Player* player, Boss* boss){
        std::ofstream fout;
        fout.open("Restoring.txt");
        fout << 1 << std::endl;
        fout << board->getStart()->getX() << " " << board->getStart()->getY() << " "
        << board->getFinish()->getX() << " " << board->getFinish()->getY() << std::endl;
        fout << calmEnemies.size() << " " << angryEnemies.size() << " ";
        fout << numOfObjects[0] << " " << numOfObjects[1] << " " << numOfObjects[2] << std::endl;
        fout << player->getX() << " " << player->getY() << " " << player->getMaxHP() << " " << player->getHP() <<
        " " << player->getAttack() << std::endl;
        fout << boss->getX() << " " << boss->getY() << " " << boss->getHP() << " " << boss->getAttack() << std::endl;
        for (int i = 0; i < calmEnemies.size(); i++) {
            fout << calmEnemies[i]->getX() << " " << calmEnemies[i]->getY() << " "
                 << calmEnemies[i]->getHP() << " " << calmEnemies[i]->getAttack() << " "
                 << calmEnemies[i]->getDir().first << " " << calmEnemies[i]->getDir().second << std::endl;
        }
        for(int i = 0; i < angryEnemies.size(); i++){
            fout << angryEnemies[i]->getX() << " " << angryEnemies[i]->getY() << " "
                 << angryEnemies[i]->getHP() << " " << angryEnemies[i]->getAttack() << " "
                 << angryEnemies[i]->getDir().first << " " << angryEnemies[i]->getDir().second << std::endl;
        }
        for(int i = 0; i < objects.size(); i++){
            fout << objects[i]->getX() << " " << objects[i]->getY() << " " << objects[i]->checkHeal() << " "
            << objects[i]->checkAttack()  << std::endl;
        }
        fout.close();
    }

public:
    void startGame() {
        std::ifstream fin;
        fin.open("Restoring.txt");
        if(fin.is_open()){
            control = new GameControl();
            int file, console, buttons;
            std::cout << "Choose loging method: file, console. 1 is for true, 0 is for false" << std::endl;
            std::cin >> file >> console;
            Logger logger(file, console);
            std::cout << "default control buttons: up - " << control->up << ", down - " <<
                      control->down << ", left - " << control->left << ", right - " << control->right << std::endl;
            Board board(set_width, set_height);
            int start_x = board.getStart()->getX();
            int start_y = board.getStart()->getY();
            Player player(start_x, start_y + 1);
            Boss third;
            int is_restore;
            fin >> is_restore;
            if(is_restore == 0) {
                fin.close();
                makeInfo(numSw, numDi, numCu);
                //making player
                board.setObject(player.getX(), player.getY(), 'p');
                player.setMaxHP(10000);
                player.setHP(3000);
                player.setAttack(1000);
                logger.checkObject(&player);

                //making enemies and objects
                makeCalmEnemies(calmEn, &board, &logger);
                makeAngryEnemies(angryEn, &board, &logger);
                third.setX(board.getFinish()->getX());
                third.setY(board.getFinish()->getY() - 1);
                board.setObject(third.getX(), third.getY(), 't');
                third.setHP(6000);
                third.setAttack(2500);
                makeObjects(&board, &logger);
                board.printBoard();
                writeInFile(&board, &player, &third);
                moving(&board, &player, &third, &logger);
            } else {
                int start_x, start_y, finish_x, finish_y;
                fin >> start_x >> start_y >> finish_x >> finish_y;
                board.getCell(board.getStart()->getX(), board.getStart()->getY())->setType('#');
                board.getCell(board.getFinish()->getX(), board.getFinish()->getY())->setType('#');
                board.getCell(start_x, start_y)->setType('0');
                board.getCell(finish_x, finish_y)->setType('$');
                board.getStart()->setX(start_x);
                board.getStart()->setY(start_y);
                board.getFinish()->setX(finish_x);
                board.getFinish()->setY(finish_y);
                int size_ofCalm, size_ofAngry, swords, diadems, cups;
                int x, y, attack, HP, maxHP, heal, dir_1, dir_2;
                fin >> size_ofCalm >> size_ofAngry >> swords >> diadems >> cups;
                //std::cout << size_ofCalm << " " << size_ofAngry << " " << swords << " " << diadems << " " << cups << std::endl;
                fin >> x >> y >> maxHP >> HP >> attack;
                //std::cout << x << " " << y << " " << maxHP << " " << HP << " " << attack << std::endl;
                player.setX(x); player.setY(y); player.setAttack(attack); player.setMaxHP(maxHP); player.setHP(HP);
                board.setObject(player.getX(), player.getY(), 'p');
                fin >> x >> y >> HP >> attack;
                //std::cout << x << " " << y << " " << HP << " " << attack << std::endl;
                third.setX(x); third.setY(y); third.setAttack(attack); third.setHP(HP);
                board.setObject(third.getX(), third.getY(), 't');
                makeInfo(swords, diadems, cups);
                for(int i = 0; i < size_ofCalm; i++) {
                    fin >> x >> y >> HP >> attack >> dir_1 >> dir_2;
                    calmEnemies.push_back(new CalmEnemy(x, y, HP, attack));
                    board.getCell(x, y)->setType('f');
                    calmEnemies[i]->setDir(dir_1, dir_2);
                    //std::cout << x << " " << y << " " << HP << " " << attack<< std::endl;
                }
                for(int i = 0; i < size_ofAngry; i++) {
                    fin >> x >> y >> HP >> attack >> dir_1 >> dir_2;
                    angryEnemies.push_back(new AngryEnemy(x, y, HP, attack));
                    board.getCell(x, y)->setType('s');
                    angryEnemies[i]->setDir(dir_1, dir_2);
                    //std::cout << x << " " << y << " " << HP << " " << attack << std::endl;
                }
                for(int i = 0; i < swords; i++) {
                    fin >> x >> y >> heal >> attack;
                    objects.push_back(new Sword(x, y, heal, attack));
                    board.getCell(x, y)->setType('!');
                    //std::cout << x << " " << y << " " << heal << " " << attack << std::endl;
                }
                for(int i = 0; i < diadems; i++){
                    fin >> x >> y >> heal >> attack;
                    objects.push_back(new Diadem(x, y, heal, attack));
                    board.getCell(x, y)->setType('@');
                    //std::cout << x << " " << y << " " << heal << " " << attack << std::endl;
                }
                for(int i = 0; i < cups; i++){
                    fin >> x >> y >> heal >> attack;
                    objects.push_back(new KnightCup(x, y, heal, attack));
                    board.getCell(x, y)->setType('U');
                    //std::cout << x << " " << y << " " << heal << " " << attack << std::endl;
                }
                board.printBoard();
                moving(&board, &player, &third, &logger);
                fin.close();
                std::ofstream fout;
                fout.open("Restoring.txt");
                fout << 0 << std::endl;
                fout.close();
            }

        }
    }
};


#endif //UNTITLED7_GAME_H
