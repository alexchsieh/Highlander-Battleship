#include <string>

#ifndef CONSTANTS_H
#define CONSTANTS_H

// game play constants (standard game of battleship)
const int shipCount = 5;
const int boardDimen = 10;
const int boardSpace = 100;
const int shipLength[shipCount] = {5, 4, 3, 3, 2};
const int shipTotalSpace = 17;
const std::string SHIP_NAMES[shipCount] = 
			{"Carrier","Battleship","Cruiser","Submarine","Destroyer"};

// board value constants
const char isMISS = 'X';
const char isWATER = 'O';

#endif