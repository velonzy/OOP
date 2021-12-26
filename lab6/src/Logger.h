#ifndef UNTITLED7_LOGGER_H
#define UNTITLED7_LOGGER_H
#include "Enemy.h"
#include "Player.h"
#include "Item.h"
#include "Logger.h"
#include <fstream>


class Logger {
private:
    bool file, console;
    std::ofstream fout;
public:
    Logger(bool file, bool console);
    ~Logger();
    template<class T>
    void checkObject(T *object) {
        if(this->file == 1){
            fout << object;
        }
        if(this->console == 1){
            std::cout << object;
        }
    }
    template<class T>
    void changeObject(T *object) {
        if(this->file == 1){
            fout << "Object is no longer on the field" << std::endl;
        }
        if(this->console == 1){
            std::cout << "Object is no longer on the field" << std::endl;
        }
    }

};


#endif //UNTITLED7_LOGGER_H
