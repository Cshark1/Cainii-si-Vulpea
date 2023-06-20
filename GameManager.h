//
// Created by stefan on 6/18/2023.
//

#ifndef UNTITLED4_GAMEMANAGER_H
#define UNTITLED4_GAMEMANAGER_H

#include <vector>

#include "Board.h"
#include "Utils.h"
#include "CLI.h"
#include "GUI.h"

class UI;

class GameManager {
private:
    int width;
    int height;
    Board board;
    bool isDogTurn = true;
    bool isGameStarted = false;
    UI* ui;
    Utils::gameMode gameMode = Utils::PvP;
    Utils::mode mode;

    Utils::winner checkForWinner();
    std::vector<Utils::directions> getDirections(int pieceLine, int pieceColumn);

    std::vector<Utils::Move> dogs_move;
    std::vector<Utils::Move> fox_move;

    bool isMoveValid(int initialLine, int initialColumn, int finalLine, int finalColumn);
    void handleMenuOption(Utils::menuOptions);
    void resetGame();

    [[noreturn]] void gameLoop();
public:
    explicit GameManager(Utils::mode mode = Utils::GUI);
    int getWidth();
    int getHeight();
    Board getBoard();
    bool isGameRunning();
    char getBoardValue(int line, int column);
    bool movePiece(Utils::Move move);
    void startGame(Utils::gameMode gm = Utils::PvP);
};


#endif //UNTITLED4_GAMEMANAGER_H
