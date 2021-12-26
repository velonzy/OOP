#include "InterfaceCell.h"
#include <iostream>

class Cell: public InterfaceCell{
private:
    int x, y;
    char type;
public:
    Cell(int x, int y, char type);
    char getType() final;
    void setType(char type) final;
    int getX() final;
    void setX(int x) final;
    int getY() final;
    void setY(int y) final;
};