#include "board.h"
#include "coordinate.h"
#include <iostream>

using namespace std;

Gameboard::Gameboard(){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            board[i][j] = '*';
        }
    }
}

Gameboard::~Gameboard(){}


//outputs public board
void Gameboard::outputBoard(){
    cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
    for(int i = 0; i < row; i++){
        cout << i << " ";
        for(int j = 0; j < column; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


//outputs user's current board with hits and misses