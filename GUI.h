//
// Created by stefa on 6/19/2023.
//

#ifndef UNTITLED4_GUI_H
#define UNTITLED4_GUI_H

#include "UI.h"

class GUI : public UI{
    GUI() = default;
    Utils::Move readMove() final;
    Utils::menuOptions readMenuOption() final;
    void printMainMenu() final;
    void printBoard(Board board) final;
    void printError(std::string error) final;
    void printPlayerTurn(bool isDogTurn) final;
    void printWinner(Utils::winner winner) final;
};


#endif //UNTITLED4_GUI_H
