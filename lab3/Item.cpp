#include "Item.h"

void Item::changeStatus(){
    this->status = false;
}

int Item::checkAttack() {
    return this->attack;
}

bool Item::checkStatus() {
    return this->status;
}

int Item::checkHeal() {
    return this->heal;
}

int Item::getX() {
    return this->x;
}

void Item::setX(int x) {
    this-> x = x;
}

int Item::getY() {
    return this->y;
}

void Item::setY(int y) {
    this->y = y;
}

Item::~Item() {
    delete this;
}

std::string Item::getName() {
    return "Item";
}

std::string getName(){
    return "Item";
}

std::ostream &operator<<(std::ostream &os, Item *item) {
    os << item->getName() << ": position(" << item->getX() << "," << item->getY() << ")," <<
       " can heal:" << item->checkHeal() <<", get attack: " << item->checkAttack() << std::endl;
    return os;
}

void Item::setAttack(int attack) {
    this->attack = attack;
}

void Item::setHeal(int heal) {
    this->heal = heal;
}
