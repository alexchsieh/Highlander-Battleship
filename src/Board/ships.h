#ifndef SHIPS_H
#define SHIPS_H
#include <iostream>
using namespace std;

class Ship {
    private:
        int size;
        int numberOfHits;
        bool status;
        //coordinates
        //ownerSHIP

    public:
        int get_size();
        int get_hits();
        bool get_status();
        //
        //
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