#ifndef UNTITLED7_ARTIFACTS_H
#define UNTITLED7_ARTIFACTS_H
#include <string>
#include <iostream>

class Artifacts{
public:
    virtual int checkAttack() = 0;
    virtual int checkHeal() = 0;
    virtual bool checkStatus() = 0;
    virtual void setAttack(int attack) = 0;
    virtual void setHeal(int heal) = 0;
    virtual void changeStatus() = 0;
    virtual int getX() = 0;
    virtual void setX(int x) = 0;
    virtual int getY() = 0;
    virtual void setY(int y) = 0;
    virtual std::string getName() = 0;
};

#endif //UNTITLED7_ARTIFACTS_H
