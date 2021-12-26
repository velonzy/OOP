#ifndef UNTITLED7_CALMENEMY_H
#define UNTITLED7_CALMENEMY_H
#include "Enemy.h"

class CalmEnemy: public  Enemy{
public:
    CalmEnemy() = default;
    ~CalmEnemy();
    std::string getName() override;
    CalmEnemy(int x, int y, int Hp, int attack);
};


#endif //UNTITLED7_CALMENEMY_H
