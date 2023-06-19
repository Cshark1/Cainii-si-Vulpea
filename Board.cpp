//
// Created by stefa on 6/18/2023.
//

#include "Board.h"


char Board::getBoardValue(int row, int column) {
    return board[row][column];
}

void Board::swap(int row1, int column1, int row2, int column2) {
    char c = board[row1][column1];
    board[row1][column1] = board[row2][column2];
    board[row2][column2] = c;
}
