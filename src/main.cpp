#include <iostream>
#include <vector>
#include <sstream>
#include "board.cpp"
#include "validity.cpp"
using namespace std;

int main() {
    vector<int> shipSizes = { 5, 4, 3, 3, 2 };
    string matrix[row][column];
    string userName = "";
    int sizeInput = 0;
    char confirmation = '\0';
    int shipValue = 0;
    int x = 0;
    int y = 0; 

    clearMatrix(matrix);
    grid(matrix);
    outputMatrix(matrix);
    cout << "What is your game name?" << endl;
    cin >> userName;

    cout << "Which ship size would you like to place first?" << endl;
    cin >> sizeInput;
    for(int i = 0; i < shipSizes.size(); i++) {
        if(shipSizes.at(i) == sizeInput) {
            if(shipSizes.at(i) == 5) {
                //fiveShip();
            }
            else if (shipSizes.at(i) == 4) {
                //fourShip();
            }
            else if (shipSizes.at(i) == 3) {
                //threeShip();
            }
            else if (shipSizes.at(i) == 2) {
                //twoShip();
            }
            shipSizes.erase(shipSizes.begin() + i);
        }
        else {
            cout << "That is not a valid ship size. Try again!" << endl;
            cin >> sizeInput;
        }
    } // maybe this should be an array so we can erase a value?
    cout << "What coordinates do you want to start your ship at? (type the X and Y value of the first position)" << endl;
    // we will have to factor the coordinates with respect to the grid
    cout << "x: ";
    cin >> x;
    checkCoord(x, "x");
    cout << "y: ";
    cin >> y;
    checkCoord(y, "y");
    cout << "Which direction do you want to ship to end at? (type the X and Y value of the last position)" << endl;
    // need first test case here based on ship size to see if end location is valid
    cout << "x: ";
    cin >> x;
    checkCoord(x, "x");
    cout << "y: ";
    cin >> y;
    checkCoord(y, "y");

    cout << "Are you sure that is your final board placement? (y/n)" << endl;
    cin >> confirmation;
    while(confirmation != 'y' || confirmation != 'n') {
        cout << "That is not a valid response. Try again!" << endl;
        cin >> confirmation;
    }


    cout << "Which coordinate would you like to attack?" << endl;
    cin >> x;
    cin >> y;

    return 0;
}