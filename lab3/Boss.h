#ifndef UNTITLED7_BOSS_H
#define UNTITLED7_BOSS_H
#include "Enemy.h"
#include <iostream>

class Boss: public Enemy {
public:
    Boss() = default;
    ~Boss();
    std::string getName() override;
};


#endif //UNTITLED7_BOSS_H
