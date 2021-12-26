#include "CalmEnemy.h"

CalmEnemy::~CalmEnemy() {
    delete this;
}

std::string CalmEnemy::getName() {
    return "CalmEnemy";
}

CalmEnemy::CalmEnemy(int x, int y, int Hp, int attack) {
    this->x = x;
    this->y = y;
    this->HP = Hp;
    this->attack = attack;
}