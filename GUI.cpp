//
// Created by stefa on 6/19/2023.
//

#include <string>
#include <winbgim.h>
#include <iostream>
#include <algorithm>
#include <chrono>

#include "GUI.h"
#include "GameManager.h"

#define BOARDGREEN COLOR(70, 130, 100)
#define BOARDWHITE COLOR(255, 255, 255)
#define BOARDACCENT COLOR(107,135,76)
#define TEXTBLACK COLOR(0, 0, 0)


GUI::GUI(int width, int height, std::string title, GameManager &gm) {
    GUI::width = width;
    GUI::height = height;
    GUI::gm = &gm;
    boardSize = height - 40;
    rightSideWidth = width - boardSize - 60;
    rightSizeStartWidth = boardSize + 60;
    nextLine = 20;
    initwindow(width, height, title.c_str());
    determineFontSizeForScreenSize();
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
    int squareSize = boardSize / 8;

    setcolor(BOARDACCENT);
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
            }
        }
    }
}

Utils::Move GUI::readMove() {
    Utils::Move move{};
    int reads = 0;
    while (reads < 2){
        if (ismouseclick(WM_LBUTTONDOWN)){
            clearmouseclick(WM_LBUTTONDOWN);
            int x = mousex();
            int y = mousey();
            int squareSize = boardSize / 8;
            if ((x - 20) / squareSize > 8 || (y - 20) / squareSize > 8)
                continue;
            if (reads == 0){
                if ((gm->getBoardValue((y - 20) / squareSize, (x - 20) / squareSize) == 'd' && isDogTurn) ||
                    gm->getBoardValue((y - 20) / squareSize, (x - 20) / squareSize) == 'f' && !isDogTurn) {
                    move.pieceLine = (y - 20) / squareSize;
                    move.pieceColumn = (x - 20) / squareSize;
                } else {
                    continue;
                }
            } else{
                move.moveLine = (y - 20) / squareSize;
                move.moveColumn = (x - 20) / squareSize;
            }
            ++reads;
        }
    }
    return move;
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
    printPopUp("TEST");
}

void GUI::printPlayerTurn(bool isDogTurn) {
    setbkcolor(COLOR(255, 255, 255));
    cleardevice();

    GUI::isDogTurn = isDogTurn;

    drawPlayerTurn();

}

void GUI::printWinner(Utils::winner winner) {

}

void GUI::printMoveHistory(const std::vector<Utils::Move> &dogs_move, const std::vector<Utils::Move> &fox_move) {
    int active_buffer = getactivepage();
    setactivepage(getvisualpage());
    setvisualpage(active_buffer);
}

void GUI::determineFontSizeForScreenSize() {
    int size = 120;
    while (size > 6){
        settextstyle(DEFAULT_FONT, HORIZ_DIR, size);
        if ((textwidth("Now:") + 90) <= rightSideWidth)
            break;
        size -= 2;
    }
}

void GUI::printPopUp(std::string message) {
    int prev_active_page = getactivepage();
    int prev_visual_page = getvisualpage();
    setactivepage(3);
    setbkcolor(COLOR(255, 255, 255));
    cleardevice();
    drawBoard(gm->getBoard());
    drawPlayerTurn();
    setcolor(BOARDACCENT);
    char str[255];
    strcpy(str, message.c_str());
    drawFilledRectangle(0,(height / 2) - (textheight(str) / 2) - 20,width,(height / 2) + (textheight(str) / 2) + 20);
    setbkcolor(BOARDACCENT);
    setcolor(BLACK);
    outtextxy(width / 2 - textwidth(str) / 2, (height / 2) - (textheight(str) / 2), str);
    setvisualpage(3);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    clearmouseclick(WM_LBUTTONDOWN);

    do {
        end = std::chrono::steady_clock::now();
    } while (!ismouseclick(WM_LBUTTONDOWN) && std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() < 5);

    clearmouseclick(WM_LBUTTONDOWN);

    setactivepage(prev_active_page);
    setvisualpage(prev_visual_page);
}


void GUI::drawPlayerTurn() {
    setcolor(TEXTBLACK);

    int iconSize = std::max(textheight("Now:"), 60);
    if (iconSize > 60) {
        outtextxy(rightSizeStartWidth, nextLine, "Now: ");
        if (isDogTurn){
            readimagefile("dog.gif", rightSizeStartWidth + textwidth("Now:") + 10, nextLine,
                          rightSizeStartWidth + textwidth("Now:") + 10 + iconSize, nextLine + iconSize);
        } else {
            readimagefile("fox.gif", rightSizeStartWidth + textwidth("Now:") + 10, nextLine,
                          rightSizeStartWidth + textwidth("Now:") + 70, nextLine + 60);
        }
    } else {
        outtextxy(rightSizeStartWidth, nextLine + (60 - textheight("Now:")) / 2, "Now: ");
        if (isDogTurn){
            readimagefile("dog.gif", rightSizeStartWidth + textwidth("Now:") + 10, nextLine,
                          rightSizeStartWidth + textwidth("Now:") + 70, nextLine + 60);
        } else {
            readimagefile("fox.gif", rightSizeStartWidth + textwidth("Now:") + 10, nextLine,
                          rightSizeStartWidth + textwidth("Now:") + 70, nextLine + 60);
        }
    }
}



