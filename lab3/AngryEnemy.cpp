#include "AngryEnemy.h"

AngryEnemy::~AngryEnemy() {
    delete this;
}

std::string AngryEnemy::getName() {
    return "AngryEnemy";
}
