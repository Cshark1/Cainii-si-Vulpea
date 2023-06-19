//
// Created by stefa on 6/18/2023.
//

#include "CLI.h"

#include <iostream>
#include <string>

void CLI::printBoard(Board board) {
    for(int i = 0; i < 8; ++i){
        std::cout << 8 - i << " ";
        for(int j = 0; j < 8; ++j){
            std::cout << board.getBoardValue(i, j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "  ";
    for (int i = 0; i < 8; ++i) {
        std::cout << (char)(65 + i) << " ";
    }
    std::cout << std::endl;
}

//void CLI::CLIMainLoop() {
//    while (true) {
//        if (gameManager->isGameRunning()){
//            printBoard();
//            std::cout << std::endl;
//
//            handleGamePlayOption(readGamePlayOption());
//        } else {
//            printMainMenu();
//            char option = readMenuOption();
//            if (option == '0'){
//                return;
//            }
//            handleMenuOption(option);
//        }
//    }
//}

void CLI::printMainMenu() {
    std::cout << " ##    ##   ###   #  #  ###   ###          ##   ###         #  #  #  #  #     ###   ####   ##   \n"
                 "#  #  #  #   #    ## #   #     #          #  #   #          #  #  #  #  #     #  #  #     #  #  \n"
                 "#     #  #   #    ## #   #     #           #     #          #  #  #  #  #     #  #  ###   #  #  \n"
                 "#     ####   #    # ##   #     #            #    #          #  #  #  #  #     ###   #     ####  \n"
                 "#  #  #  #   #    # ##   #     #          #  #   #           ##   #  #  #     #     #     #  #  \n"
                 " ##   #  #  ###   #  #  ###   ###          ##   ###          ##    ##   ####  #     ####  #  #  ";
    std::cout << std::endl << std::endl;
    std::cout << "1 - Start PvP Game" << std::endl;
    std::cout << "2 - Start PvE Game" << std::endl;

    std::cout << std::endl;
    std::cout << "0 - Exit game" << std::endl;
    std::cout << std::endl;
}

Utils::menuOptions CLI::readMenuOption() {
    char option;
    std::cout << "What do you want to do?: ";
    std::cin >> option;
    std::cout << std::endl << std::endl;
    return (Utils::menuOptions) Utils::charToDigit(option);
}


Utils::Move CLI::readMove() {
    Utils::Move currentMove{};
    std::string input;

    std::cout << "Which piece do you want to move? (Enter int the format A1): ";
    std::cin >> input;
    std::cout << std::endl;

    currentMove.pieceColumn = Utils::moveToColumn(input);
    currentMove.pieceLine = Utils::moveToLine(input);

    std::cout << "Where do you want to move the piece? (Enter int the format A1): ";
    std::cin >> input;
    std::cout << std::endl << std::endl;

    currentMove.moveColumn = Utils::moveToColumn(input);
    currentMove.moveLine = Utils::moveToLine(input);

    return currentMove;
}

void CLI::printPlayerTurn(bool isDogTurn) {
    if (isDogTurn){
        std::cout << "Dogs turn." << std::endl << std::endl;
    } else {
        std::cout << "Foxes turn." << std::endl << std::endl;
    }
}

void CLI::printError(std::string error) {
    std::cout << error << std::endl << std::endl;
}

void CLI::printWinner(Utils::winner winner) {
    if (winner == Utils::Fox){
        std::cout << "*************************************************" << std::endl;
        std::cout << "*                                               *" << std::endl;
        std::cout << "*                  Winner: Fox                  *" << std::endl;
        std::cout << "*                                               *" << std::endl;
        std::cout << "*************************************************" << std::endl << std::endl;
    } else if (winner == Utils::Dogs){
        std::cout << "*************************************************" << std::endl;
        std::cout << "*                                               *" << std::endl;
        std::cout << "*                 Winner: Dogs                  *" << std::endl;
        std::cout << "*                                               *" << std::endl;
        std::cout << "*************************************************" << std::endl << std::endl;
    }

}





