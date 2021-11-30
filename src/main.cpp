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
	cout<< "expected: Carrier, " << myShip.getName()<<endl;
	cout<< "expected: 5, " << myShip.getSize()<<endl;
	cout<< "expected: -1, " <<  myShip.getX()<<endl;
	cout<< "expected: -1, " << myShip.getY()<<endl;
	cout<< "expected: 0, " << myShip.isShipSunk()<<endl;
	cout<< "expected: 1, " << myShip.isShipHorizontal()<<endl;
	myShip.setPosition(1, 1, false);
	cout<< "expected: Carrier, " << myShip.getName()<<endl;
	cout<< "expected: 5, " << myShip.getSize()<<endl;
	cout<< "expected: 1, " << myShip.getX()<<endl;
	cout<< "expected: 1, " << myShip.getY()<<endl;
	cout<< "expected: 0, " << myShip.isShipSunk()<<endl;
	cout<< "expected: 0, " << myShip.isShipHorizontal()<<endl;
	cout<< "expected: $ $ $ $ $, ";
	myShip.printShip();
	Ship myShip2=myShip; 
	cout << "expected: $ $ $ $ $, ";
	myShip2.printShip();
	myShip2.recordHit(0,0);
	cout << "expected: $ $ $ $ $, ";
	myShip2.printShip();
	myShip2.recordHit(1, 2);
	cout << "expected: $ O $ $ $, ";
	myShip2.printShip();
	myShip2.recordHit(1, 3);
	cout << "expected: $ O O $ $, ";
	myShip2.printShip();
	myShip2.recordHit(1, 4);
	cout << "expected: $ O O O $, ";
	myShip2.printShip();
	myShip2.recordHit(1, 5);
	cout << "expected: $ O O O O, ";
 	myShip2.printShip();
	myShip2.recordHit(1, 1);
	cout << "expected: O O O O O, "; 
	myShip2.printShip();
	myShip2.recordHit(6, 1);
	cout << "expected: O O O O O, "; 
	myShip2.printShip();
	cout<< "expected: 0, " << myShip.isShipSunk()<<endl;
	cout<< "expected: 1, " << myShip2.isShipSunk()<<endl;
	myShip = myShip2; 
	cout<< "expected: 1, " << myShip.isShipSunk()<<endl;
	cout << "expected: O O O O O, ";
 	myShip.printShip();
	User p1("Christina",false, 1);
	cout<< "expected: Christina, " << p1.getName()<<endl;
	cout<< "expected: 0, " << p1.isPlayerAutomatic()<<endl;
	cout<< "expected: 1, " << p1.getPlayerNum()<<endl;
	User p2 = p1; 
	cout<< "expected: Christina, " << p2.getName()<<endl;
	cout<< "expected: 0, " << p2.isPlayerAutomatic()<<endl;
	cout<< "expected: 1, " << p2.getPlayerNum()<<endl;
	p2.setName("Bob");
	p2.setAuto(false);
	p2.setPlayerNum(3);
	cout<< "expected: Bob, " << p2.getName()<<endl;
	cout<< "expected: 0, " << p2.isPlayerAutomatic()<<endl;
	cout<< "expected: 3, " << p2.getPlayerNum()<<endl; 
	Gameboard b1;
	bool test;
	test=b1.placeShip(0, 1, 1, true);
	cout<<"expected: 1, "<< test << endl;
	test=b1.placeShip(1, 8, 1, false);
	cout<<"expected: 1, "<< test << endl;
	test=b1.placeShip(1, 1, 2, true);
	cout<<"expected: 0, "<< test << endl;
	cout << "expected: You sunk the The USS Hallie!" << endl;
	test=b1.recordHit(1, 1);
	test=b1.recordHit(2, 1);
	test=b1.recordHit(3, 1);
	test=b1.recordHit(4, 1);
	test=b1.recordHit(5, 1);
	test=b1.recordHit(6, 1);
	b1.printPublicBoard();
	b1.printPrivateBoard();
	Gameboard b2 = b1; 
	test=b2.recordHit(7, 1);
	b2.printPublicBoard();
	b1.printPublicBoard();
	b1 = b2; 
	b1.printPublicBoard();
	test=b1.recordHit(2, 2);
	b1.printPublicBoard();
	b1.printPrivateBoard();
	cout<< "expected: O, " << b1.getSpaceValue(1, 1) << endl;

	bool continueGame = true;

	while (continueGame) {
		continueGame = printMenu();
	}
	return 0;
}
