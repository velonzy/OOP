#ifndef UNTITLED7_ANGRYENEMY_H
#define UNTITLED7_ANGRYENEMY_H
#include "Enemy.h"

class AngryEnemy: public Enemy {
public:
    AngryEnemy() = default;
    ~AngryEnemy();
    std::string getName() override;
    AngryEnemy(int x, int y, int Hp, int attack);
};


#endif //UNTITLED7_ANGRYENEMY_H
