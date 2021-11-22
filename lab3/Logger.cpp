#include <iostream>
#include "Logger.h"

Logger::Logger(bool file, bool console){
    this->file = file;
    this->console = console;
    if(this->file){
        fout.open("Logger.txt");
    }
}

Logger::~Logger() {
    if (this->file){
        fout.close();
    }
}
/*
void Logger::playerIsKilled(Player *player) {
    if(this->file == 1){
        fout << "Player is killed\n";
    }
    if(this->console == 1){
        std::cout << "Player is killed\n";
    }
}

void Logger::enemyIsKilled(Enemy *enemy) {
    if(this->file == 1){
        fout << enemy->getName() << "is killed\n";
    }
    if(this->console == 1){
        std::cout << enemy->getName() << "is killed\n";
    }
}

void Logger::itemBeingUsed(Player *player, Item *item) {
    if(this->file == 1){
        fout << item->getName() << "was used\n";
        fout << player;
    }
    if(this->console == 1){
        std::cout << item->getName() << "was used\n";
        std::cout << player;
    }
}

void Logger::playerCheck(Player *player) {
    if(this->file == 1){
        fout << player;
    }
    if(this->console == 1){
        std::cout << player;
    }
}

void Logger::itemCheck(Item *item) {
    if(this->file == 1){
        fout << item;
    }
    if(this->console == 1){
        std::cout << item;
    }
}
*/
/*
template<class T>
void Logger::checkObject(T *object) {
    if(this->file == 1){
        fout << object;
    }
    if(this->console == 1){
        std::cout << object;
    }
}
*/
/*
void Logger::enemyCheck(Enemy *enemy) {
    if(this->file == 1){
        fout << enemy;
    }
    if(this->console == 1){
        std::cout << enemy;
    }
}*/

/*
std::ostream &operator<<(std::ostream &os, Enemy *enemy) {
    os << enemy->getName() << ": position(" << enemy->getX() << "," << enemy->getY() << ")" <<
       " current HP:" << enemy->getHP() <<", attack: "<< enemy->getAttack() << std::endl;
    return os;
}*/
/*
std::ostream &operator<<(std::ostream &os, Player *player) {
    os << player->getName() << ": position(" << player->getX() << "," << player->getY() << "), maxHP:" <<
       player->getMaxHP() << ", current HP:" << player->getHP() <<", attack: "<< player->getAttack() << std::endl;
    return os;
}*/
/*
std::ostream &operator<<(std::ostream &os, Item *item) {
    os << item->getName() << ": position(" << item->getX() << "," << item->getY() << ")," <<
       " can heal:" << item->checkHeal() <<", get attack: " << item->checkAttack() << std::endl;
    return os;
}*/
