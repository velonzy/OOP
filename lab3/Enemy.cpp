#include "Enemy.h"

Enemy::Enemy() = default;

void Enemy::setHP(int HP) {
    this->HP = HP;
}

void Enemy::setDamage(int damage) {
    this->HP -= damage;
    if (this->HP <= 0){
        this->getKilled();
    }
}

void Enemy::getKilled() {
    this->alive = false;
}

int Enemy::getHP() {
    return this->HP;
}

int Enemy::getAttack() {
    return this->attack;
}

int Enemy::getStatus() {
    return this->alive;
}

int Enemy::getX() {
    return this->x;
}

void Enemy::setX(int x) {
    this->x = x;
}

int Enemy::getY() {
    return this->y;
}

void Enemy::setY(int y) {
    this->y = y;
}

std::string Enemy::getName() {
    return "Enemy";
}

std::ostream &operator<<(std::ostream &os, Enemy *enemy) {
    os << enemy->getName() << ": position(" << enemy->getX() << "," << enemy->getY() << ")" <<
       " current HP:" << enemy->getHP() <<", attack: "<< enemy->getAttack() << std::endl;
    return os;
}

Enemy::~Enemy() {
    delete this;
}

void Enemy::setAttack(int attack) {
    this->attack = attack;
}

