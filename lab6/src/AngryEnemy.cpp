#include "AngryEnemy.h"

AngryEnemy::~AngryEnemy() {
    delete this;
}

std::string AngryEnemy::getName() {
    return "AngryEnemy";
}

AngryEnemy::AngryEnemy(int x, int y, int Hp, int attack) {
    this->x = x;
    this->y = y;
    this->HP = Hp;
    this->attack = attack;
}
