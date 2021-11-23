#include "gameboard.h"
#include <iostream>

Gameboard::Gameboard() {
    for(int i = 0; i < boardDimen; i++) {
        for (int j = 0; j < boardDimen; j++) {
            gameBoard[i][j] = isWATER;
        }
    }    
}

void Gameboard::clear_gameboard() {
    for(int i = 0; i < boardDimen; i++) {
        for (int j = 0; j < boardDimen; j++) {
            gameBoard[i][j] = isWATER;
        }
    }    
}

void Gameboard::print_gameboard() {
    for(int i = 0; i < boardDimen; i++) {
        for (int j = 0; j < boardDimen; j++) {
            std::cout << gameBoard[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
