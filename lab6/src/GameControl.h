#ifndef UNTITLED7_GAMECONTROL_H
#define UNTITLED7_GAMECONTROL_H
#include <iostream>

class GameControl {
public:
    char up, down, left, right;
    GameControl();
    void setControl(char up, char down, char left, char right);
    std::pair <int, int> step();
};


#endif //UNTITLED7_GAMECONTROL_H
