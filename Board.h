//
// Created by stefa on 6/18/2023.
//

#ifndef UNTITLED4_BOARD_H
#define UNTITLED4_BOARD_H


class Board {
private:
    char board[8][8]={'e', 'e', 'e', 'e', 'f', 'e', 'e', 'e',
                      'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
                      'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
                      'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
                      'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
                      'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
                      'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
                      'd', 'e', 'd', 'e', 'd', 'e', 'd', 'e' };

public:
    char getBoardValue(int row, int column);
    void swap(int row1, int column1, int row2, int column2);
};


#endif //UNTITLED4_BOARD_H
