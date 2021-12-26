#ifndef UNTITLED7_ENEMY_H
#define UNTITLED7_ENEMY_H
#include "Character.h"
#include <string>

class Enemy: public Character{
protected:
    int HP, attack;
    int x, y;
    bool alive = true;
    std::pair<int, int> dir;
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
    void setDir(int move_x, int move_y);
    std::pair<int, int> getDir();
    friend std::ostream& operator<<(std::ostream &os, Enemy *enemy);

};


#endif //UNTITLED7_ENEMY_H
