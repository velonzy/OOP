#include "Sword.h"

Sword::~Sword() {

}

std::string Sword::getName() {
    return "Sword";
}

Sword::Sword(int x, int y, int heal, int attack) {
    this->x = x;
    this->y = y;
    this->heal = heal;
    this->attack = attack;
}
