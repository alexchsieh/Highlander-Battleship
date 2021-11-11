#include <iostream>
using namespace std;

void checkCoord(int& coord, string val) {
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
}

