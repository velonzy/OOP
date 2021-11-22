#include <iostream>

class InterfaceCell{
public:
    virtual char getType() = 0;
    virtual void setType(char type) = 0;
    virtual int getX() = 0;
    virtual void setX(int x) = 0;
    virtual int getY() = 0;
    virtual void setY(int y) = 0;
};