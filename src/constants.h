#include <string>
#include <iostream>

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

using namespace std;

// game play constants (standard game of battleship)
const int shipCount = 5;
const int boardDim = 10;
const int shipLength[shipCount] = {5, 4, 3, 3, 2};
const string shipName[shipCount] = { "The USS Hallie", "The USS Angie", "The USS Alex Squared", "The USS Samarth", "The USS Ryan" };

// board value constants
const char isHIT = 'O';
const char isMISS = 'X';
const char isWATER = '*';
const char isSAFESHIP = '$';

// to convert char to board position
const int letterASCII = 65;
const int numberASCII = 48;




#endif