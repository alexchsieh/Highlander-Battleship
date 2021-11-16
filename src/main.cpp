#include <iostream>
#include <vector>
#include "board.h"
#include "ships.h"
#include "validity.h"
using namespace std;

int main() {
    string userName = "";
    int sizeInput = 0;
    char confirmation = '\0';
    int shipValue = 0;
    int x = 0;
    int y = 0; 

    vector<int> shipSizes;
    shipSizes.push_back(5);
    shipSizes.push_back(4);
    shipSizes.push_back(3);
    shipSizes.push_back(3);
    shipSizes.push_back(2);

    Gameboard board;

    board.clearMatrix();
    board.grid();
    board.outputMatrix();
    cout << "What is your game name?" << endl;
    cin >> userName;

    cout << "Which ship size would you like to place first?" << endl;
    cin >> sizeInput;
    while(shipSizes.size() != 0) {
        for(int i = 0; i < shipSizes.size(); i++) {
            if(shipSizes.at(i) == sizeInput) {
                if(shipSizes.at(i) == 5) {
                    FiveShip five;
                    
                    five.placement(1, 1, 5, 1);
                    board.outputMatrix();
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
            cin >> sizeInput;
        } // maybe this should be an array so we can erase a value?
    }
    return 0;
}
	
