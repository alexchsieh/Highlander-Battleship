#ifndef _BOARD_H_
#define _BOARD_H_

#include <iostream>
#include <vector>
#include "ships.h"

using namespace std;

const int row = 10;
const int column = 10;
class Gameboard {
    private:
        char board[row][column];
        vector<Ship> shipList;
    public:
        Gameboard();
        ~Gameboard();
        //void clearBoard();
        //void copyBoard();
        void outputBoard();

};



#endif
