#ifndef UNTITLED7_DIADEM_H
#define UNTITLED7_DIADEM_H
#include <cstdlib>
#include "Item.h"


class Diadem: public Item {
public:
    Diadem() = default;
    ~Diadem();
    std::string getName() override;
    Diadem(int x, int y, int heal, int attack);
};


#endif //UNTITLED7_DIADEM_H
