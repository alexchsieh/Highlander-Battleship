#ifndef VALIDITY_H
#define VALIDITY_H

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
};

#endif