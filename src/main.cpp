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

	Ship myShip(5, "Carrier");
	cout<<myShip.getName()<<endl;
	cout<<myShip.getSize()<<endl;
	cout<<myShip.getX()<<endl;
	cout<<myShip.getY()<<endl;
	cout<<myShip.isShipSunk()<<endl;
	cout<<myShip.isShipHorizontal()<<endl;
	myShip.setPosition(1, 1, false);
	cout<<myShip.getName()<<endl;
	cout<<myShip.getSize()<<endl;
	cout<<myShip.getX()<<endl;
	cout<<myShip.getY()<<endl;
	cout<<myShip.isShipSunk()<<endl;
	cout<<myShip.isShipHorizontal()<<endl;
	myShip.printShip();
	cout<<myShip.isShipSunk()<<endl;
	cout<<myShip.isShipSunk()<<endl;
	myShip.printShip();
	//TEST ALL METHODS FOR PLAYER CLASS
	User p1("Christina",false, 1);
	cout<<p1.getName()<<endl;
	cout<<p1.isPlayerAutomatic()<<endl;
	cout<<p1.getPlayerNum()<<endl;
	//TEST ALL METHODS FOR BOARD CLASS 
	Gameboard b1;
	bool test;
	test=b1.placeShip(0, 1, 1, true);
	cout<<"Ok placement: "<<test<<"\n";
	test=b1.placeShip(1, 8, 1, false);
	cout<<"Ok placement: "<<test<<"\n";
	test=b1.placeShip(1, 1, 2, true);
	cout<<"Ok placement: "<<test<<"\n";
	test=b1.recordHit(1, 1);
	test=b1.recordHit(2, 1);
	test=b1.recordHit(3, 1);
	test=b1.recordHit(4, 1);
	test=b1.recordHit(5, 1);
	test=b1.recordHit(6, 1);
	b1.printPublicBoard();
	b1.printPrivateBoard();
	b1.printPublicBoard();
	b1.printPublicBoard();
	test=b1.recordHit(2, 2);
	b1.printPublicBoard();
	b1.printPrivateBoard();
	cout<<b1.getSpaceValue(1, 1)<<"\n";

	bool continueGame = true;

	while (continueGame) {
		continueGame = printMenu();
	}
	return 0;
}