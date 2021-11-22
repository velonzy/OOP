#ifndef UNTITLED7_ENEMY_H
#define UNTITLED7_ENEMY_H
#include "Character.h"
#include <string>

class Enemy: public Character{
protected:
    int HP, attack;
    int x, y;
    bool alive;
public:
    Enemy();
    ~Enemy();
    int getHP() override;
    void setHP(int HP) override;
    void setDamage (int damage) override;
    void setAttack(int attack) override;
    int getAttack() override;
    int getStatus() override;
    void getKilled() override;
    int getX() override;
    void setX(int x) override;
    int getY() override;
    void setY(int y) override;
    std::string getName() override;
    friend std::ostream& operator<<(std::ostream &os, Enemy *enemy);

};


#endif //UNTITLED7_ENEMY_H
