#include <iostream>
#include "Board.h"


void Board::setHeight(int height) {
    this->height = height;
}

void Board::setWidth(int width) {
    this->width = width;
}

int Board::getHeight(){
    return this->height;
}

int Board::getWidth() {
    return this->width;
}

Board::Board(int width, int height){
    setHeight(height);
    setWidth(width);
    board = new Cell**[height];
    for(int i = 0; i < height; i++){
        board[i] = new Cell*[width];
        for(int j = 0; j < width; j++){
            if((i == 0) || (i == height - 1) || (j == 0) || (j == width - 1))
                board[i][j] = new Cell(j, i, '#');
            else{
                board[i][j] = new Cell(j, i, ' ');
            }
        }
    }
    int k = std::rand() % width;
    board[0][k]->setType('0');
    this->start = board[0][k];
    k = std::rand() % height;
    board[height - 1][k]->setType('$');
    this->finish = board[height - 1][k];
}

Board::Board(const Board &other): height(other.height), width(other.width){
    board = new Cell**[height];
    start = other.start;
    finish = other.finish;
    for(int i = 0; i < height; i++) {
        board[i] = new Cell *[width];
        for (int j = 0; j < width; j++) {
            board[i][j] = new Cell(j, i, other.board[i][j]->getType());
        }
    }
}

Board& Board::operator = (const Board& other){
    if(this != &other){
        width = other.width;
        height = other.height;
        start = other.start;
        finish = other.finish;
        for(int i = 0; i < height; i++){
            for (int j = 0; j < width; j++)
                delete board[i][j];
            delete[] board[i];
        }
        delete[] board;
        board = new Cell** [height];
        for (int i = 0; i < height; i++){
            board[i] =  new Cell* [width];
            for(int j=0; j<width; j++) {
                board[i][j] = other.board[i][j];
            }
        }
    }
    return *this;
}

void Board::printBoard(){
    for(int i = 0; i < this->height; i++){
        for(int j = 0; j < this->width; j++){
            std::cout << board[i][j]->getType();
        }
        std::cout << std::endl;
    }
}

Board::Board(Board &&other) {
    std::swap(width, other.width);
    std::swap(height, other.height);
    std::swap(board, other.board);
    std::swap(start, other.start);
    std::swap(finish, other.finish);
}

Board& Board::operator = (Board&& other){
    if(this != &other){
        std::swap(width, other.width);
        std::swap(height, other.height);
        std::swap(board, other.board);
        std::swap(start, other.start);
        std::swap(finish, other.finish);
    }
    return *this;
}

Board::~Board() {
    for(int i = 0; i < this->height; i++){
        for(int j = 0; j < this->width; j++){
            delete[] board[i][j];
        }
        delete[] board[i];
    }
    delete[] board;
}

Cell*** Board::getBoard() {
    return this->board;
}

Cell* Board::setObject(int x, int y, char type){
    board[y][x]->setType(type);
    return board[y][x];
}

Cell* Board::getCell(int x, int y){
    return board[y][x];
}

Cell* Board::getStart(){
    return start;
}

Cell* Board::getFinish() {
    return finish;
}
