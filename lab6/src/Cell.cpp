#include "Cell.h"
#include <iostream>

Cell::Cell(int x, int y, char type) {
    this->x = x;
    this->y = y;
    this->type = type;
}

char Cell::getType() {
    return this->type;
}

void Cell::setType(char type) {
    this->type = type;
}

int Cell::getX() {
    return this->x;
}

void Cell::setX(int x) {
    this-> x = x;
}

int Cell::getY() {
    return this->y;
}

void Cell::setY(int y) {
    this->y = y;
}