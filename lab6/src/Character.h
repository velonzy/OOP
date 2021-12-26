#ifndef UNTITLED7_CHARACTER_H
#define UNTITLED7_CHARACTER_H
#include <iostream>

class Character {
public:
    virtual int getHP() = 0;
    virtual void setAttack(int attack) = 0;
    virtual int getAttack() = 0;
    virtual int getStatus() = 0;
    virtual int getX() = 0;
    virtual void setX(int x) = 0;
    virtual int getY() = 0;
    virtual void setY(int y) = 0;
    virtual void setHP(int HP) = 0;
    virtual void setDamage(int damage) = 0;
    virtual void getKilled() = 0;
    virtual std::string getName() = 0;
};


#endif //UNTITLED7_CHARACTER_H
