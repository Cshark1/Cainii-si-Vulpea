//
// Created by stefa on 6/19/2023.
//

#ifndef UNTITLED4_GUI_H
#define UNTITLED4_GUI_H

#include <string>

#include "UI.h"
#include "Board.h"
#include "GameManager.h"

class GameManager;

class GUI : public UI{
private:
    int width;
    int height;
    int boardSize;
    int rightSideWidth;
    int rightSizeStartWidth;
    int nextLine;
    bool isDogTurn;
    void *ptr[4];
    GameManager* gm;
    void drawBoard(Board board);
    void drawPlayerTurn();
    void drawFilledRectangle(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY);
    void determineFontSizeForScreenSize();
    void printPopUp(std::string messag);
public:
    GUI(int width, int height, std::string title, GameManager &gm);
    Utils::Move readMove() final;
    Utils::menuOptions readMenuOption() final;
    void printMainMenu() final;
    void printBoard(Board board) final;
    void printError(std::string error) final;
    void printPlayerTurn(bool isDogTurn) final;
    void printWinner(Utils::winner winner) final;
    void printMoveHistory(const std::vector<Utils::Move> &dogs_move, const std::vector<Utils::Move> &fox_move) final;
};


#endif //UNTITLED4_GUI_H
