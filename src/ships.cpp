#include <iostream>
using namespace std;

class Ship {
    public:
        virtual void placement() = 0;
};

class FiveShip : public Ship {
    public:
        template <typename T>
        void placement(T &matrix, int x, int y, int x1, int x2) { 
            for(int i = 0; i < 12; i++) {
                for (int j = 0; j < 12; j++) {
                    matrix[x+1][y+1] = 5;
                    if(x == x1) {
                        matrix[x+1][y+1] = 5;
                    }
                }
            }
        }
};

class FourShip : public Ship {
    public:
        void movement() {

        }
};

class ThreeShip : public Ship {
    public:
        void movement() {

        }
};

class TwoShip : public Ship {
    public:
        void movement() {

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
