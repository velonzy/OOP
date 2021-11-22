#include "Boss.h"

std::string Boss::getName() {
    return "Boss";
}

Boss::~Boss() {
    delete this;
}
