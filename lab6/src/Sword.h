#ifndef UNTITLED7_SWORD_H
#define UNTITLED7_SWORD_H
#include <cstdlib>
#include "Item.h"

class Sword: public Item {
public:
    Sword() = default;
    ~Sword();
    std::string getName() override;
    Sword(int x, int y, int heal, int attack);
};


#endif //UNTITLED7_SWORD_H
