#ifndef UNTITLED7_SWORD_H
#define UNTITLED7_SWORD_H
#include <cstdlib>
#include "Item.h"

class Sword: public Item {
public:
    Sword() = default;
    ~Sword();
    std::string getName() override;
};


#endif //UNTITLED7_SWORD_H
