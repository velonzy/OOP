cmake_minimum_required(VERSION 3.17)
project(untitled7)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled7 main.cpp Board.cpp Board.h Cell.cpp Cell.h InterfaceCell.h CalmEnemy.cpp CalmEnemy.h AngryEnemy.cpp AngryEnemy.h Boss.cpp Boss.h Player.cpp Player.h Artifacts.h KnightCup.cpp KnightCup.h Sword.cpp Sword.h Diadem.cpp Diadem.h Game.cpp Game.h Enemy.cpp Enemy.h Character.h Item.h Item.cpp Logger.cpp Logger.h)