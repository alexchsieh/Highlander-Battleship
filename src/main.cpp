#include <iostream>
#include <sstream>
#include "board.h"
#include "validity.h"
#include "ships.h"
using namespace std;

int main() {
    string matrix[row][column];
    string userName = "";
    char confirmation = '\0';
    string shipSize = "";
    int shipValue = 0;
    int xCoord = 0;
    int yCoord = 0;
    int attackCoordx = 0; 
    int attackCoordy = 0; 

    clearMatrix(matrix);
    grid(matrix);
    outputMatrix(matrix);
    cout << "What is your game name?" << endl;
    cin >> userName;

    cout << "Which ship size would you like to pick first?" << endl;
    cin >> shipSize; // maybe this should be an array so we can erase a value?
    stringstream convert(shipSize);
    convert >> shipValue;

    while(!(shipValue > 1 && shipValue < 6)) { // we can for loop to iterate an array to check deleted value
        cout << "That is not a valid ship size. Try again!" << endl;
        cin >> shipValue;
        stringstream convert(shipValue);
        convert >> shipSize;
    }
    cout << "What coordinates do you want to start your ship at? (type the X and Y value of the first position)" << endl;
    // we will have to factor the coordinates with respect to the grid
    cout << "x: ";
    cin >> xCoord;
    checkCoord(xCoord, "x");
    cout << "y: ";
    cin >> yCoord;
    checkCoord(yCoord, "y");
    cout << "Which direction do you want to ship to end at? (type the X and Y value of the last position)" << endl;
    // need first test case here based on ship size to see if end location is valid
    cout << "x: ";
    cin >> xCoord;
    checkCoord(xCoord, "x");
    cout << "y: ";
    cin >> yCoord;
    checkCoord(yCoord, "y");

    cout << "Are you sure that is your final board placement? (y/n)" << endl;
    cin >> confirmation;
    while(confirmation != 'y' || confirmation != 'n') {
        cout << "That is not a valid response. Try again!" << endl;
        cin >> confirmation;
    }


    cout << "Which coordinate would you like to attack?" << endl;
    cin >> attackCoordx;
    cin >> attackCoordy;

    return 0;
}