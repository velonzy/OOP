#include "KnightCup.h"

KnightCup::~KnightCup() {
    delete this;
}

std::string KnightCup::getName() {
    return "KnightCup";
}

KnightCup::KnightCup(int x, int y, int heal, int attack) {
    this->x = x;
    this->y = y;
    this->heal = heal;
    this->attack = attack;
}