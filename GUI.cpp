//
// Created by stefa on 6/19/2023.
//

#include <string>
#include <winbgim.h>
#include <iostream>

#include "GUI.h"

#define BOARDGREEN COLOR(70, 130, 100)
#define BOARDWHITE COLOR(255, 255, 255)

GUI::GUI(int width, int height, std::string title) {
    GUI::width = width;
    GUI::height = height;
    boardSize = height - 40;
    initwindow(width, height, title.c_str());
    setbkcolor(COLOR(255, 255, 255));
    cleardevice();
    setactivepage(2);
    setbkcolor(COLOR(255, 255, 255));
    cleardevice();
}

void GUI::drawFilledRectangle(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY) {
    int poly[8];
    poly[0] = topLeftX;
    poly[1] = topLeftY;
    poly[2] = bottomRightX;
    poly[3] = topLeftY;
    poly[4] = bottomRightX;
    poly[5] = bottomRightY;
    poly[6] = topLeftX;
    poly[7] = bottomRightY;
    setfillstyle(SOLID_FILL, getcolor());
    fillpoly(4, poly);
}


void GUI::drawBoard(Board board) {
    boardSize;
    int squareSize = boardSize / 8;

    setcolor(BOARDGREEN);
    drawFilledRectangle(18, 18, 22 + boardSize, 22 + boardSize);

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2 == 0) setcolor(BOARDWHITE);
            else setcolor(BOARDGREEN);
            drawFilledRectangle( (j * squareSize) + 20, (i * squareSize) + 20,
                                 ((j + 1) * squareSize) + 20, ((i + 1) * squareSize) + 20);

            if (board.getBoardValue(i, j) == 'd'){
                readimagefile(  "dog.gif", (j * squareSize) + 30, (i * squareSize) + 30, ((j + 1) * squareSize) + 10,
                        ((i + 1) * squareSize) + 10);
            }
            if (board.getBoardValue(i, j) == 'f'){
                readimagefile( "fox.gif", (j * squareSize) + 30, (i * squareSize) + 30, ((j + 1) * squareSize) + 10,
                               ((i + 1) * squareSize) + 10);
                std::cout << "Left: " << (j * squareSize) + 20 << std::endl;
                std::cout << "Top: " << (i * squareSize) + 20 << std::endl;
                std::cout << "Right: " << ((j + 1) * squareSize) + 20 << std::endl;
                std::cout << "Bottom: " << ((i + 1) * squareSize) + 600 << std::endl;
            }

        }
    }
}

Utils::Move GUI::readMove() {
    return Utils::Move();
}

Utils::menuOptions GUI::readMenuOption() {
    return Utils::StartPvEGame;
}

void GUI::printMainMenu() {

}

void GUI::printBoard(Board board) {
    drawBoard(board);
}

void GUI::printError(std::string error) {

}

void GUI::printPlayerTurn(bool isDogTurn) {
    setbkcolor(COLOR(255, 255, 255));
    cleardevice();


}

void GUI::printWinner(Utils::winner winner) {

}

void GUI::printMoveHistory(const std::vector<Utils::Move> &dogs_move, const std::vector<Utils::Move> &fox_move) {
    swapbuffers();
    UI::printMoveHistory(dogs_move, fox_move);
}


