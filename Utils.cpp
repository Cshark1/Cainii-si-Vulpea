//
// Created by stefa on 6/18/2023.
//

#include "Utils.h"


short Utils::abs(short nr) {
    if (nr < 0){
        return nr * -1;
    }
    return nr;
}

int Utils::abs(int nr) {
    if (nr < 0){
        return nr * -1;
    }
    return nr;
}

long Utils::abs(long nr) {
    if (nr < 0){
        return nr * -1;
    }
    return nr;
}

long long Utils::abs(long long int nr) {
    if (nr < 0){
        return nr * -1;
    }
    return nr;
}

float Utils::abs(float nr) {
    if (nr < 0){
        return nr * -1.0f;
    }
    return nr;
}

double Utils::abs(double nr) {
    if (nr < 0){
        return nr * -1.0f;
    }
    return nr;
}

bool Utils::isInRange(int nr, int rangeStart, int rangeEnd, bool includeBoundaries) {
    if (includeBoundaries){
        if (nr >= rangeStart && nr <= rangeEnd)
            return true;
    } else {
        if (nr > rangeStart && nr < rangeEnd)
            return true;
    }
    return false;
}

bool Utils::isInRange(float nr, float rangeStart, float rangeEnd, bool includeBoundaries) {
    if (includeBoundaries){
        if (nr >= rangeStart && nr <= rangeEnd)
            return true;
    } else {
        if (nr > rangeStart && nr < rangeEnd)
            return true;
    }
    return false;
}

bool Utils::isInRange(double nr, double rangeStart, double rangeEnd, bool includeBoundaries) {
    if (includeBoundaries){
        if (nr >= rangeStart && nr <= rangeEnd)
            return true;
    } else {
        if (nr > rangeStart && nr < rangeEnd)
            return true;
    }
    return false;
}

int Utils::charToDigit(char ch) {
    return int(ch) - 48;
}

int Utils::moveToLine(std::string move) {
    if (!isdigit(move[1])){
        return -1;
    }
    return 8 - charToDigit(move[1]);
}

int Utils::moveToColumn(std::string move) {
    move[0] = tolower(move[0]);
    switch (move[0]) {
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;
        default:
            return -1;
    }
}


// Utils