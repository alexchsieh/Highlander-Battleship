#include "game.h"
#include "Turn/user.h"
#include "utils.h"
#include <iostream>
#include <ctime>

using namespace std;

int chooseMode() {
    int mode = 0;

	cout << "Which mode would you like to play?" << endl;
	cout << "1. Speed" << endl;
	cout << "2. Easy" << endl;
	cout << "3. Hard" << endl;
	mode = getInt(1,3);

	return mode;
}

bool printMenu() { 
	int cont;

	cout << "Welcome to Battleship!" << endl;
    cout << "Enter 1 to start a new game" << endl;
	cout << "Enter 2 to quit" << endl;
	cont = getInt(1,2);

	if (cont == 1) { 
		int mode = chooseMode();
		Game * g = new Game(new Speed);
		if (mode == 1) { 
			g->gameinterface(mode);
		}
		if (mode == 2) {
			g->setStrategy(new Easy);
			g->gameinterface(mode);
		}
		if (mode == 3) {
			g->setStrategy(new Hard);
			g->gameinterface(mode);
		}
		return true;
	}
	else 
		return false;
}

int main() {
	srand(time(0));
	
	bool continueGame = true;

	while (continueGame) {
		continueGame = printMenu();
	}
	return 0;
}
