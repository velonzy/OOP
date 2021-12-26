#include <iostream>
#include "Logger.h"

Logger::Logger(bool file, bool console){
    this->file = file;
    this->console = console;
    if(this->file){
        fout.open("Logger.txt");
    }
}

Logger::~Logger() {
    if (this->file){
        fout.close();
    }
}
