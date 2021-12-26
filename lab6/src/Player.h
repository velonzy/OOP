#ifndef UNTITLED7_PLAYER_H
#define UNTITLED7_PLAYER_H
#include "Character.h"

class Player: public Character {
private:
    int maxHP, attack, HP;
    bool alive = true;
    int x, y;
public:
    Player(int x, int y);
    ~Player();
    void heal(int heal);
    void strengthening(int attack);
    int getMaxHP();
    int getHP() override;
    void setHP(int HP) override;
    void setMaxHP(int inp_HP);
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
    friend std::ostream& operator<<(std::ostream &os, Player *player);
};


#endif //UNTITLED7_PLAYER_H
