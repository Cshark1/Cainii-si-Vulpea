//
// Created by stefa on 6/18/2023.
//

#ifndef UNTITLED4_CLI_H
#define UNTITLED4_CLI_H

#include <string>

#include "GameManager.h"
#include "UI.h"
#include "Board.h"

class GameManager;

class CLI : public UI{
public:
    CLI() = default;
    Utils::Move readMove() final;
    Utils::menuOptions readMenuOption() final;
    void printMainMenu() final;
    void printBoard(Board board) final;
    void printError(std::string error) final;
    void printPlayerTurn(bool isDogTurn) final;
    void printWinner(Utils::winner winner) final;
};


#endif //UNTITLED4_CLI_H
