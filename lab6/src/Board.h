#include "Cell.h"
#include <iostream>
#include <fstream>

class Board{
private:
    int height, width;
    Cell*** board;
    Cell* start;
    Cell* finish;
    Cell*** getBoard();
public:
    Board(int width, int height);
    void setHeight(int height);
    void setWidth(int width);
    int getHeight();
    int getWidth();
    void printBoard();
    Board(const Board &other);
    Board& operator = (const Board& other);
    Board(Board&& other);
    Board& operator = (Board&& other);
    Cell* setObject(int x, int y, char type);
    Cell* getCell(int x, int y);
    Cell* getStart();
    Cell* getFinish();
    ~Board();
};