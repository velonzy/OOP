#include "Diadem.h"

Diadem::~Diadem() {
    delete this;
}

std::string Diadem::getName() {
    return "Diadem";
}

Diadem::Diadem(int x, int y, int heal, int attack) {
    this->x = x;
    this->y = y;
    this->heal = heal;
    this->attack = attack;
}