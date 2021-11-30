#include <string>
#include <iostream>

#ifndef USER_H
#define USER_H
using namespace std;

class User {
	private:
		string name;
		bool isAutomaticPlayer;
		int playerNumber;
	public:
        //default constructor assigns values when no inputs supplied
        User() {
            name = "";
            isAutomaticPlayer = false;
            playerNumber = 1;
        };

        //constructor, takes strings for name, whether the player is automatic, number
        User(string n, bool a, int num) {
            name = n;
            isAutomaticPlayer = a;
            playerNumber = num;
        };

        // copy constructor
        User(const User &oldPlayer) {
            name = oldPlayer.name;
            isAutomaticPlayer = oldPlayer.isAutomaticPlayer;
            playerNumber = oldPlayer.playerNumber;

        };

        //copy assignment operator 
        User& operator=(const User &obj) {
            if (this != &obj) {
                name = obj.name;
                isAutomaticPlayer = obj.isAutomaticPlayer;
                playerNumber = obj.playerNumber;
            }

            return *this;
        };

        //getter functions (name, auto, number)
        string getName() {
            return name;
        };

        bool isPlayerAutomatic() {
            return isAutomaticPlayer;
        };

        int getPlayerNum() {
            return playerNumber;
        };

        //setter functions (name, auto, number)
        void setName(string n) {
            name = n;
            return;
        };

        void setAuto(bool a) {
            isAutomaticPlayer = a;
            return;
        };

        void setPlayerNum(int n) {
            playerNumber = n;
            return;
        };
};

#endif