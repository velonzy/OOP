#include <iostream>
#include "Player.h"

Player::Player(int x, int y) {
    this->x = x;
    this->y = y;
}

std::string Player::getName() {
    return "Player";
}

void Player::setHP(int HP){
    this->HP = HP;
}

void Player::setMaxHP(int inp_HP) {
    this->maxHP = inp_HP;
}

void Player::strengthening(int attack){
    this->attack += attack;
}

void Player::heal(int heal){
    if (this->HP + heal >= this->maxHP){
        this->HP = this->maxHP;
    } else {
        this->HP += heal;
    }
}

int Player::getMaxHP() {
    return this->maxHP;
}

void Player::setDamage(int damage) {
    this->HP -= damage;
    if (this->HP <= 0){
        this->getKilled();
    }
}

void Player::getKilled() {
    this->alive = false;
}

int Player::getHP() {
    return this->HP;
}

int Player::getAttack() {
    return this->attack;
}

int Player::getStatus() {
    return this->alive;
}

int Player::getX() {
    return this->x;
}

void Player::setX(int x) {
    this-> x = x;
}

int Player::getY() {
    return this->y;
}

void Player::setY(int y) {
    this->y = y;
}

Player::~Player() {
    delete this;
}

void Player::setAttack(int attack) {
    this->attack = attack;
}

std::ostream &operator<<(std::ostream &os, Player *player) {
    os << player->getName() << ": position(" << player->getX() << "," << player->getY() << "), maxHP:" <<
       player->getMaxHP() << ", current HP:" << player->getHP() <<", attack: "<< player->getAttack() << std::endl;
    return os;
}
