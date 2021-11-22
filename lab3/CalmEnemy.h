#ifndef UNTITLED7_CALMENEMY_H
#define UNTITLED7_CALMENEMY_H
#include "Enemy.h"

class CalmEnemy: public  Enemy{
public:
    CalmEnemy() = default;
    ~CalmEnemy();
    std::string getName() override;
};


#endif //UNTITLED7_CALMENEMY_H
