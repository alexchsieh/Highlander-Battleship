#ifndef USER_H
#define USER_H

#include <iostream>


class User {
private:
    int userChoiceX;
    int userChoiceY;
    std::string userOptionChoice;
public:
    void userTurn();
    void save();
    void user_powerup();
    void surrender();

};

#endif