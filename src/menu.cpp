#include <iostream>

using namespace std;

void start_game() {
//user selects the Start Game option

}

void select_easy() {
//user selects the Easy game mode

}

void select_hard() {
//user selects the Hard game mode

}

void select_speed() {
//user selects the Speed game mode

}
 
bool powerups_on() {
//return true if powerups are being used, return false if powerups are not being used 
	cin << userInput;
	if (userInput == ("Y" || "y")) {
		return true;
	}
	else if (userInput == ("N" || "n")) {
		return false;
	}
}

void load_game() {
//user selects the Load Game option

}


int main() {
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
	
	if (userInput.toLowerCase() == start.toLowerCase()) {
		start_game();
		if (userInput.toLowerCase() == easy) {
			select_easy();
			cout << powerups << endl;
			if (powerups_on() == true) {
			//function from Gameboard that randomly distributes powerups across the board

			}
			else if (powerups_on() == false) {
			//function from Gameboard that creates a default Gameboard with no powerups

			}
		}
		else if (userInput.toLowerCase() == hard) {
			select_hard();
		}
		else if (userInput.toLowerCase() == speed) {
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

	if (userInput.toLowerCase() == load.toLowerCase()) {
		load_game();
	}


}



