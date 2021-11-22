#ifndef UNTITLED7_ITEM_H
#define UNTITLED7_ITEM_H
#include "Artifacts.h"

class Item: public Artifacts{
protected:
    int attack;
    int heal;
    bool status;
    int x, y;
public:
    Item() = default;
    ~Item();
    int checkAttack() override;
    bool checkStatus() override;
    int checkHeal() override;
    void changeStatus() override;
    void setAttack(int attack) override;
    void setHeal(int heal) override;
    int getX() override;
    void setX(int x) override;
    int getY() override;
    void setY(int y) override;
    std::string getName() override;
    friend std::ostream& operator<<(std::ostream &os, Item *item);
};


#endif //UNTITLED7_ITEM_H
