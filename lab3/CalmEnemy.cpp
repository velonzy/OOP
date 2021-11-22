#include "CalmEnemy.h"

CalmEnemy::~CalmEnemy() {
    delete this;
}

std::string CalmEnemy::getName() {
    return "CalmEnemy";
}
