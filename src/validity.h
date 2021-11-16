#ifndef VALIDITY_H
#define VALIDITY_H

#include <iostream>
using namespace std;

 bool available(int x, int y) {
     if(matrix[x][y] != "0") {
         return false;
     }
     return true;
 }

void checkCoord(int& coord, std::string val) {
    while(coord < 1 || coord > 10) {
            cout << "That is not a valid coordinate. Try again!" << endl;
            if(val == "x") {
                cout << "x: ";
                cin >> coord;
            }
            else {
                cout << "y: ";
                cin >> coord;
            }
        }
};

#endif