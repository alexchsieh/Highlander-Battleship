#include "ships.h"
#include "../constants.h"
#include <vector>
#include <iostream>

#ifndef GAMEBOARD_H
#define GAMEBOARD_H
using namespace std;

class Gameboard {
    private:
        char gameBoard[boardDim][boardDim];
        vector<Ship> shipVec;

        int saveX, saveY, savefX, savefY = 0;
        bool moveFlag = false;

    public:
        Gameboard() {
            for (int i = 0; i < boardDim; i++)
                for (int j = 0; j < boardDim; j++)
                    gameBoard[i][j] = isWATER;

            for (int i = 0; i < shipCount; i++)
                shipVec.push_back(Ship(shipLength[i], shipName[i]));
        };
        ~Gameboard() {};

        Gameboard(const Gameboard &oldBoard) {
            for (int i = 0; i < boardDim; i++)
                for (int j = 0; j < boardDim; j++)
                    gameBoard[i][j] = oldBoard.gameBoard[i][j];
            shipVec = oldBoard.shipVec;
        };

        Gameboard& operator=(const Gameboard &right) {
            if (this!=&right) {
                for (int i=0; i<boardDim; i++)
                    for (int j=0; j<boardDim; j++)
                        gameBoard[i][j]=right.gameBoard[i][j];
                shipVec = right.shipVec;
            }
            return *this;
        };

        int getNumHits() {
            int count = 0;

            for (int i = 0; i < boardDim; i++)
                for (int j = 0; j < boardDim; j++)
                    if (gameBoard[i][j] == isHIT)
                        count++;

            return count;
        };

        void printPrivateBoard() {
            cout << "  A B C D E F G H I J\n";
            for (int i=0; i<boardDim; i++)
            {
                cout<<i<<" ";
                for (int j = 0; j < boardDim; j++)
                {
                    if (gameBoard[i][j] == isHIT || gameBoard[i][j] == isMISS)
                        cout << gameBoard[i][j] << " ";
                    else // obfuscate non-hit/miss entries
                        cout << isWATER << " ";
                }   
                cout << endl;
            }
        };

        void printPublicBoard() {
            cout<<"  A B C D E F G H I J\n";
            for (int i = 0; i < boardDim; i++)
            {
                cout << i << " ";
                for (int j = 0; j < boardDim; j++)
                {
                    cout << gameBoard[i][j] << " ";
                }   
                cout << endl;
            }

        };

        //return the value of a space
        char getSpaceValue(int x, int y) {
            return gameBoard[y][x];
        };

        // record a hit on the board by attempting to record a hit on every ship
        // if a ship is hit, change board position to hit and return true
        // if no ship is hit, change board position to miss and return false
        bool recordHit(int x, int y) {
            for (int i = 0; i < shipCount; i++) {
                if (shipVec[i].recordHit(x, y)) {
                    gameBoard[y][x]=isHIT;
                    if (shipVec[i].isShipSunk()) 
                        cout << "You sunk the " << shipVec[i].getName() << "!" << endl;
                    return true;
                }
            }
            gameBoard[y][x]=isMISS;
            return false;
        };

        bool isthehitShipSunk(int x, int y) {
            for (int i = 0; i < shipCount; i++) {
                if (shipVec[i].recordHit(x, y)) {
                    gameBoard[y][x]=isHIT; 
                    if (shipVec[i].isShipSunk()) 
                        return true;
                }
            }
            return false;
        };

        int whichShipStruck(int x, int y) {
            for (int i = 0; i < shipCount; i++) {
                if (shipVec[i].recordHit(x, y)) {
                    return i;
                }
            }
            return 0;
        };

        void saveLastMove(int x, int y) {
            saveX = x;
            saveY = y;
        };

        int getLastX() {
            return saveX;
        };

        int getLastY() {
            return saveY;
        };

        void saveFirstMove(int x, int y) {
            savefX = x;
            savefY = y;
        };

        int getFirstX() {
            return savefX;
        };

        int getFirstY() {
            return savefY;
        };

        void setMoveFlag(bool flag) {
          moveFlag = flag;
        }

        bool getMoveFlag() {
            return moveFlag;
        };

        // function to place ship on board
        bool placeShip(int shipNum, int x, int y, bool isHorizontal) {
            //if x or y is out of bounds, return false
            if (x >= boardDim || y >= boardDim)
                return false;

            //if ship has already been placed, return false
            if (shipVec[shipNum].getX() >= 0 && shipVec[shipNum].getY()>=0)
                return false;

            //loop through the positions required for the ship
            for (int i=0; i<shipVec[shipNum].getSize(); i++) {
                //if any of the desired spaces are filled, return false
                if ((isHorizontal && gameBoard[y][x+i]!=isWATER) || 
                                    (!isHorizontal && gameBoard[y+i][x]!=isWATER))
                    return false;
                //if any of the desired spaces are out of bounds, return false
                if ((isHorizontal && (x+i)>=boardDim) || 
                                    (!isHorizontal && (y+i)>=boardDim))
                    return false;
            }

            //if the for loop finishes, and all the positions are empty, 
            //1. place the Ship in the desired position on the board
            for (int i=0; i<shipVec[shipNum].getSize(); i++) {
                if (isHorizontal)
                    gameBoard[y][x+i]=isSAFESHIP;
                else 
                    gameBoard[y+i][x]=isSAFESHIP;
            }

            //2. set the x/y parameters for the Ship object 
            shipVec[shipNum].setPosition(x, y, isHorizontal);

            //... and return true
            return true;
        };

};

#endif
