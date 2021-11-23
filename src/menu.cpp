#include <iostream>
#include "menu.h"

using namespace std;

void Menu::start_game() {
//user selects the Start Game option

}

void Menu::select_easy() {
//user selects the Easy game mode

}

void Menu::select_hard() {
//user selects the Hard game mode

}

void Menu::select_speed() {
//user selects the Speed game mode

}
 
bool Menu::toggle_powerups() {
//return true if powerups are being used, return false if powerups are not being used 
    cin >> userInput;
	if (userInput == "Y" || userInput == "y") {
		return true;
	}
	else if (userInput == "N" || userInput == "n") {
		return false;
	}
}

void Menu::load_game() {
//user selects the Load Game option

}


void Menu::menu() {
//print out layout of the menu
	string start = "Start Game";
	string load = "Load Game";
	string easy = "easy";
	string hard = "hard";
	string speed = "speed";
	string powerups = "Play the game with powerups? (Y/N)";
	cout << "Highlander Battleship" << endl;
	cout << start << endl;
	cout << load << endl;
	
	if (userInput == start) {
		start_game();
		if (userInput == easy) {
			select_easy();
			cout << powerups << endl;
			if (toggle_powerups() == true) {
			//function from Gameboard that randomly distributes powerups across the board

			}
			else if (toggle_powerups() == false) {
			//function from Gameboard that creates a default Gameboard with no powerups

			}
		}
		else if (userInput == hard) {
			select_hard();
		}
		else if (userInput == speed) {
			select_speed();
		}
		else {
			cout << "That is not a valid option! Please enter another choice." << endl;
			cin >> userInput;
		}
	}
	else {
		cout << "That is not a valid option! Please enter another choice." << endl;
		cin >> userInput;
	}

	if (userInput == load) {
		load_game();
	}


}


