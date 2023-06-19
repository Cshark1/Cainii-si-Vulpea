//
// Created by stefa on 6/18/2023.
//

#ifndef UNTITLED4_UTILS_H
#define UNTITLED4_UTILS_H

#include <string>

class Utils {
public:
    enum mode{
        CLI,
        GUI
    };

    enum gameMode{
        PvP,
        PvE
    };

    enum winner{
        NoOne,
        Fox,
        Dogs
    };

    enum directions{
        TopLeft,
        TopRight,
        BottomLeft,
        BottomRight
    };

    enum menuOptions{
        StartPvPGame = 1,
        StartPvEGame = 2,

        Exit = 0
    };



    struct Move{
        int pieceLine;
        int pieceColumn;
        int moveLine;
        int moveColumn;
    };

    static short abs(short nr);
    static int abs(int nr);
    static long abs(long nr);
    static long long abs(long long nr);

    static float abs(float nr);
    static double abs(double nr);

    static bool isInRange(int nr, int rangeStart, int rangeEnd, bool includeBoundaries = false);
    static bool isInRange(float nr, float rangeStart, float rangeEnd, bool includeBoundaries = false);
    static bool isInRange(double nr, double rangeStart, double rangeEnd, bool includeBoundaries = false);

    static int charToDigit(char ch);

    static int moveToLine(std::string move);
    static int moveToColumn(std::string move);
};

 // Utils

#endif //UNTITLED4_UTILS_H
