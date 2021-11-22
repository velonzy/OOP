#ifndef UNTITLED7_KNIGHTCUP_H
#define UNTITLED7_KNIGHTCUP_H
#include <cstdlib>
#include "Item.h"

class KnightCup: public  Item{
public:
    KnightCup() = default;
    ~KnightCup();
    std::string getName() override;
};


#endif //UNTITLED7_KNIGHTCUP_H
