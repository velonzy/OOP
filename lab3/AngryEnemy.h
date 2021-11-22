#ifndef UNTITLED7_ANGRYENEMY_H
#define UNTITLED7_ANGRYENEMY_H
#include "Enemy.h"

class AngryEnemy: public Enemy {
public:
    AngryEnemy() = default;
    ~AngryEnemy();
    std::string getName() override;
};


#endif //UNTITLED7_ANGRYENEMY_H
