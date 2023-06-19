//
// Created by stefa on 6/19/2023.
//

#ifndef UNTITLED4_UI_H
#define UNTITLED4_UI_H

#include <string>
#include <vector>

#include "Utils.h"
#include "Board.h"

class UI{
public:
    UI(){};
    virtual ~UI(){};
    virtual void printMainMenu() = 0;
    virtual void printBoard(Board board) = 0;
    virtual Utils::menuOptions readMenuOption() = 0;
    virtual Utils::Move readMove() = 0;
    virtual void printError(std::string error) = 0;
    virtual void printPlayerTurn(bool isDogTurn) = 0;
    virtual void printWinner(Utils::winner winner) = 0;
    virtual void printMoveHistory(const std::vector<Utils::Move> &dogs_move, const std::vector<Utils::Move> &fox_move) {};
};

#endif //UNTITLED4_UI_H
