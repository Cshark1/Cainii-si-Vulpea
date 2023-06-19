#include <iostream>
#include <graphics.h>
#include <winbgim.h>

#include "UI.h"
#include "CLI.h"
#include "GameManager.h"
#include "Board.h"
#include "Utils.h"


using namespace std;

void drawBoard(){

}

int main(int argc, char *argv[])
{
    Utils::mode mode = Utils::GUI;

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--cli") == 0){
            mode = Utils::CLI;
        } else if (strcmp(argv[i], "--help") == 0) {
            cout << "Available arguments: ";
            cout << "     --help - Prints this menu" << endl;
            cout << "     --cli - Starts the game in CLI mode" << endl;
        }
        else{
            cerr << "Invalid argument: '" << argv[i] << "'" << endl;
            cout << "Available arguments: ";
            cout << "     --cli - Starts the game in CLI mode" << endl;
            break;
        }
    }

    GameManager gameManager{ mode };

    //initwindow(gameManager.getWidth(), gameManager.getHeight(), "TEST");

    //getch(); closegraph();
    return 0;
    }
