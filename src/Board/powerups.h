#ifndef POWERUPS_H
#define POWERUPS_H
#include "gameboard.h"

class Powerups : public Gameboard {
private: 
    bool powerupsEnabled;
    int powerupLocationX;
    int powerupLocationY;
public:
    void randomPowerups();
    void revive(); // is it void?
    void fully_destroy();
    void reveal();
};


#endif