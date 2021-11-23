#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "../constants.h"
#include "ships.h"
#include <vector>

class Gameboard {
 private:
   char gameBoard[boardDimen][boardDimen];
   std::vector<Ship> shipVec;

 public:
   Gameboard();
   void print_gameboard();
   void clear_gameboard();
};

#endif
