//
// Created by stefan on 6/18/2023.
//

#include "GameManager.h"
#include "Utils.h"
#include "CLI.h"
#include "GUI.h"

#include <vector>
#include <iostream>

GameManager::GameManager(Utils::mode mode) {
    GameManager::board = Board{ };
    GameManager::mode = mode;

    //TODO: Get resolution from settings
    width = 800;
    height = 600;

    if (mode == Utils::CLI){
        GameManager::ui = new CLI();
    } else {
        GameManager::ui = new GUI(800, 600, "Cainii si Vulpea");
    }

    gameLoop();
}

int GameManager::getWidth() {
    return width;
}

int GameManager::getHeight() {
    return height;
}

bool GameManager::isMoveValid(int initialLine, int initialColumn, int finalLine, int finalColumn) {
    //Check if destination is empty
    if (board.getBoardValue(finalLine, finalColumn) != 'e') return false;
    //TODO: Add check for move out of bounds

    if (board.getBoardValue(initialLine, initialColumn) == 'd'){ //Checks if piece moved is Dog
        if (!isDogTurn) return false; //Check if it is Dogs turn
        if ( ((initialLine - finalLine) != 1) || Utils::Utils::abs(initialColumn - finalColumn) != 1) return false; //Check if move is legal
    } else if (board.getBoardValue(initialLine, initialColumn) == 'f'){ //Checks if piece moved is fox
        if (isDogTurn) return false; //Check if it is Foxes turn
        if ( abs(initialLine - finalLine) != 1 || Utils::Utils::abs(initialColumn - finalColumn) != 1 ) return false; //Check if move is legal
    } else {
        return false;
    }

    return true;
}

bool GameManager::movePiece(Utils::Move move) {

    if (isMoveValid(move.pieceLine, move.pieceColumn, move.moveLine, move.moveColumn)){
        board.swap(move.pieceLine, move.pieceColumn, move.moveLine, move.moveColumn);

        if (isDogTurn) {
            //TODO: Play "Woof!" sound
        } else {
            //TODO: Play fox sound
        }

        isDogTurn = !isDogTurn;

        return true;
    }

    //TODO: Play "Wrong!" sound

    return false;
}

char GameManager::getBoardValue(int line, int column) {
    return board.getBoardValue(line, column);
}

void GameManager::startGame(Utils::gameMode gm) {
    isGameStarted = true;
    gameMode = gm;
    board = Board{ };
    isDogTurn = true;
}

bool GameManager::isGameRunning() {
    return isGameStarted;
}

std::vector<Utils::directions> GameManager::getDirections(int pieceLine, int pieceColumn) {
    std::vector<Utils::directions> direction{  };

    char pieceType = board.getBoardValue(pieceLine, pieceColumn);

    if (pieceType == 'e'){
        return direction;
    }

    if (pieceLine != 0 && pieceColumn != 0) {
        if (board.getBoardValue(pieceLine - 1, pieceColumn - 1) == 'e') direction.push_back(Utils::TopLeft);
    }
    if (pieceLine != 0 && pieceColumn != 7){
        if (board.getBoardValue(pieceLine - 1, pieceColumn + 1) == 'e') direction.push_back(Utils::TopRight);
    }

    if (pieceType == 'f') {
        if (pieceLine != 7 && pieceColumn != 0) {
            if (board.getBoardValue(pieceLine + 1, pieceColumn - 1) == 'e') direction.push_back(Utils::BottomLeft);
        }
        if (pieceLine != 7 && pieceColumn != 7) {
            if (board.getBoardValue(pieceLine + 1, pieceColumn + 1) == 'e') direction.push_back(Utils::BottomRight);
        }
    }

    return direction;
}

Utils::winner GameManager::checkForWinner() {
    //If fox is on the last row => fox wins
    for (int i = 0; i < 7; ++i) {
        if (board.getBoardValue(7, i) == 'f'){
            return Utils::Fox;
        }
    }

    //If there are no available moves for the dogs && it was their turn => fox wins
    if (!isDogTurn) {
        int stuckPieces = 0;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board.getBoardValue(i, j) == 'd')
                    if (getDirections(i, j).empty())
                        stuckPieces += 1;
            }
        }
        if (stuckPieces == 4){
            return Utils::Fox;
        }
    } else {//If it is foxes turn && it has not moves => dogs win
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board.getBoardValue(i, j) == 'f')
                    if (getDirections(i, j).empty())
                        return Utils::Dogs;
            }
        }
    }

    return Utils::NoOne;
}

void GameManager::handleMenuOption(Utils::menuOptions menuOption) {
    switch (menuOption) {
        case Utils::StartPvPGame:
            startGame(Utils::PvP);
            break;
        case Utils::StartPvEGame:
            startGame(Utils::PvE);
            break;


        case Utils::Exit:
            exit(0);
            break;
    }
}


[[noreturn]] void GameManager::gameLoop() {

    while (true) {
        ui->printPlayerTurn(isDogTurn);
        ui->printBoard(board);
        ui->printMoveHistory(dogs_move, fox_move);
        if (!movePiece(ui->readMove())) {
            ui->printError("Invalid move!");
        } else {
            Utils::winner winner = checkForWinner();
            if (winner != Utils::NoOne) {
                ui->printWinner(winner);
                isGameStarted = false;
            }
        }
    }
//        if (isGameRunning()) {
//            ui->printPlayerTurn(isDogTurn);
//            ui->printBoard(board);
//            ui->printMoveHistory(dogs_move, fox_move);
//            if (!movePiece(ui->readMove())) {
//                ui->printError("Invalid move!");
//            } else {
//                Utils::winner winner = checkForWinner();
//                if (winner != Utils::NoOne) {
//                    ui->printWinner(winner);
//                    isGameStarted = false;
//                }
//            }
//        } else {
//            ui->printMainMenu();
//            handleMenuOption(ui->readMenuOption());
//        }
//    }
}

