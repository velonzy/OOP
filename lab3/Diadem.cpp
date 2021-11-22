#include "Diadem.h"

Diadem::~Diadem() {
    delete this;
}

std::string Diadem::getName() {
    return "Diadem";
}
