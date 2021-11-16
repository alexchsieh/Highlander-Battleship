#ifndef SHIPS_H
#define SHIPS_H
#include <iostream>
using namespace std;

const int row = 12;
const int column = 12;

string matrix[row][column];

class Ship {
    public:
        virtual void placement(int, int, int, int) = 0;
};

class FiveShip : public Ship {
    public:
        void placement(int x, int y, int x1, int y1) { 
            for(int i = 0; i < 12; i++) {
                for (int j = 0; j < 12; j++) {
                    matrix[x+1][y+1] = 5;
                    if(x == x1) {
                        matrix[x+1][y+2] = 5;
                        matrix[x+1][y+3] = 5;
                        matrix[x+1][y+4] = 5;
                        matrix[x+1][y+5] = 5;
                    }
                    if(y == y1) {
                        matrix[x+2][y+1] = 5;
                        matrix[x+3][y+1] = 5;
                        matrix[x+4][y+1] = 5;
                        matrix[x+5][y+1] = 5;
                    }
                }
            }
        }

};

class FourShip : public Ship {
    public:
        void placement(int x, int y, int x1, int y1) { 
            for(int i = 0; i < 12; i++) {
                for (int j = 0; j < 12; j++) {
                    matrix[x+1][y+1] = 4;
                    if(x == x1) {
                        matrix[x+1][y+2] = 4;
                        matrix[x+1][y+3] = 4;
                        matrix[x+1][y+4] = 4;
                    }
                    if(y == y1) {
                        matrix[x+2][y+1] = 4;
                        matrix[x+3][y+1] = 4;
                        matrix[x+4][y+1] = 4;
                    }
                }
            }
        }
};

class ThreeShip : public Ship {
    public:
        void placement(int x, int y, int x1, int y1) { 
            for(int i = 0; i < 12; i++) {
                for (int j = 0; j < 12; j++) {
                    matrix[x+1][y+1] = 3;
                    if(x == x1) {
                        matrix[x+1][y+2] = 3;
                        matrix[x+1][y+3] = 3;
                    }
                    if(y == y1) {
                        matrix[x+2][y+1] = 3;
                        matrix[x+3][y+1] = 3;
                    }
                }
            }
        }     
};

class TwoShip : public Ship {
    public:
        void placement(int x, int y, int x1, int y1) { 
            for(int i = 0; i < 12; i++) {
                for (int j = 0; j < 12; j++) {
                    matrix[x+1][y+1] = 2;
                    if(x == x1) {
                        matrix[x+1][y+2] = 2;
                    }
                    if(y == y1) {
                        matrix[x+2][y+1] = 2;
                    }
                }
            }
        }
};

// keep in mind that the there is a grid that surrounds our actual board 
// our grid makes the board 12x12 so we have to factor that in when placing ships
// by adding and subtracting values from X and Y to make them fit where user planned
// first initial point (testing harness will be when its called)
//check if the end point is on the plot
//check if the end point is actually 5 away from the initial
//replace the grid slots actually with this ship
 // there are 2 three ships
#endif