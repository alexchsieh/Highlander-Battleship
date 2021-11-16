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
        void placement(int, int, int, int) {}
};

class FourShip : public Ship {
    public:
        void placement(int, int, int, int) {}
};

class ThreeShip : public Ship {
    public:
        void placement(int, int, int, int) {}        
};

class TwoShip : public Ship {
    public:
        void placement(int, int, int, int) {}
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