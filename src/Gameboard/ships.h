#include <string>
#include <iostream>
#include "../constants.h"

#ifndef SHIP_H
#define SHIP_H

using namespace std;

class Ship {
	private: 
		char* shipSquares;
		int shipSize;
		int xPosition, yPosition; //upper left corner of ship
		bool isSunk;
		bool isHorizontal;
		string name;

	public:	
        // one constructor initializes a ship if only size and name are spcified
        Ship(int size, string n) {
            shipSize = size;
            name = n;
            shipSquares = new char[shipSize];
            for (int i = 0; i < shipSize; i++)
                shipSquares[i] = isSAFESHIP; //initialize all ship squares to '_', no hit
            xPosition = -1; //indicates that the ship has not been placed yet
            yPosition = -1; //indicates that the ship has not been placed yet
            isSunk = false; //since ship is new, it is not yet sunk
            isHorizontal = true;
        };

        // ship can also be placed when it is initialized
        Ship(int size, string n, int x, int y, bool s, bool h) {
            shipSize = size;
            name = n;
            shipSquares = new char[shipSize];
            for (int i = 0; i < shipSize; i++)
                shipSquares[i] = isSAFESHIP; //initialize all ship squares to '_', no hit
            xPosition = x; 
            yPosition = y;
            isSunk = s; 
            isHorizontal = h;
        };

        // destructor deletes dynamically allocated memory
        ~Ship() {
            //if (shipSize > 0)
                //delete [] shipSquares;
        };

        // getter methods
        int getSize() const {
            return shipSize;
        };

        int getX() const {
            return xPosition;
        };

        int getY() const {
            return yPosition;
        };

        bool isShipSunk() const {
            return isSunk;
        };

        bool isShipHorizontal() const {
            return isHorizontal;
        };

        string getName() const {
            return name;
        };

        // set position
        void setPosition(int x, int y, bool h) {
            xPosition = x;
            yPosition = y;
            isHorizontal = h;
            return;
        };

        // print ship to console for visualization (only used for debugging)
        void printShip() {
            for (int i = 0; i < shipSize; i++)
                cout << shipSquares[i] << " ";
            cout << endl;
            return;
        };


        // function to record hit on ship, return false if no hit, true if hit
        // Note: hitLocX = loc on lettered axis, hitLocY = loc on numbered axis
        bool recordHit(int hitLocX, int hitLocY) {
            //check to make sure that the hit is located on the ship, return if not
            if ((isHorizontal & (hitLocX<xPosition || hitLocX>=xPosition+shipSize 
                                                                || hitLocY!=yPosition))
                || (!isHorizontal & (hitLocY<yPosition || hitLocY>=yPosition+shipSize 
                                                                || hitLocX!=xPosition)))
                return false; //return false because it was not a hit
            else {
                if (isHorizontal) 
                    shipSquares[hitLocX-xPosition] = isHIT;
                else 
                    shipSquares[hitLocY-yPosition] = isHIT;
            }

            //determine whether the ship has been sunk
            isSunk = true;
            for (int i = 0; i < shipSize; i++)
                if (shipSquares[i] == isSAFESHIP)
                    isSunk = false;
            return true;
        };
};

#endif