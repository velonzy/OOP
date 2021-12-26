#include "GameControl.h"

GameControl::GameControl() {
    this->up = 'w';
    this->down = 's';
    this->left = 'a';
    this->right = 'd';
}

void GameControl::setControl(char up, char down, char left, char right) {
    this->up = up;
    this->down = down;
    this->left = left;
    this->right = right;
}

std::pair <int, int> GameControl::step() {
    char step;
    std::pair<int, int> move;
    std::cout << "Please, make a step" << std::endl;
    std::cin >> step;
    if(step != this->up && step != this->down && step != this->right && step != this->left){
        std::cout << "Incorrect input, please, press one of the control keys" << std::endl;
        move = this->step();
    } else {
        if(step == this->up){
            move.first = 0;
            move.second = -1;
        } else if(step == this->down){
            move.first = 0;
            move.second = 1;
        } else if(step == this->right){
            move.first = 1;
            move.second = 0;
        } else if(step == this->left){
            move.first = -1;
            move.second = 0;
        }
    }
    return move;

}

