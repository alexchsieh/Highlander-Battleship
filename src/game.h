#include "Gameboard/gameboard.h"
#include "Turn/user.h"
#include "constants.h"
#include "utils.h"
#include <iostream>

#ifndef GAME_H
#define GAME_H

using namespace std;

enum state {p1Win, p2Win, stillPlaying};

class Strategy {
    protected: 
		User player1;
		Gameboard p1Board;
		User player2;
		Gameboard p2Board;
	public:
        virtual void gameModeMove(Gameboard* bptr, User* pptr, int mode) = 0;
        bool playGame(int mode) {
            int firstPlayer, currentPlayer, toPlay;
            Gameboard* bptr;
            User* pptr;

            startGame();

            cout << "Which player will make the first move?" << endl;
            cout << "1. Player 1" << endl;
            cout << "2. Player 2" << endl;

            firstPlayer = getInt(1,2);

            if (firstPlayer == 1) {
                pptr = &player1; 
                bptr = &p2Board;
            }
            else {
                pptr = &player2;
                bptr = &p1Board;
            }

            gameModeMove(bptr, pptr, mode);

            if (gameCondition() == p1Win)
                cout << player1.getName() << " Wins!" << endl;
            else 
                cout << player2.getName() << " Wins!" << endl;

            cout << "That was your Battleship game!" << endl;
            return true;

        };

        void startGame() {
            string nameTemp;
            int autoTemp;

            player1.setPlayerNum(1);
            player2.setPlayerNum(2);

            cout << "What is player 1's name?" << endl;
            player1.setName(getString(32));
            cout << "Welcome, " << player1.getName() << "!" << endl;

            cout << "What is player 2's name?" << endl;
            player2.setName(getString(32));
            cout << "Welcome, " << player2.getName() << "!" << endl;

            cout << "What type of player is " << player1.getName() << "?" << endl;
            cout << "1. Human" << endl;
            cout << "2. Computer" << endl;
            player1.setAuto(getInt(1,2)-1);

            cout << "What type of player is " << player2.getName() << "?" << endl;
            cout << "1. Human" << endl;
            cout << "2. Computer" << endl;
            player2.setAuto(getInt(1,2)-1);

            if (player1.isPlayerAutomatic())
                initializeBoardAuto(p1Board, false);
            else {
                cout << player1.getName() << ", how would you like to setup your board?" << endl;
                cout << "1. Manually" << endl;
                cout << "2. Automatically" << endl;
                autoTemp = getInt(1,2)-1;
                if (autoTemp)
                    initializeBoardAuto(p1Board, true);
                else initializeBoard(p1Board);

            }

            if (!player2.isPlayerAutomatic() && !player1.isPlayerAutomatic())
                switchPlayers(player1.getName(), player2.getName());

            if (player2.isPlayerAutomatic())
                initializeBoardAuto(p2Board, false);
            else {
                cout << player2.getName() << ", how would you like to setup your board?" << endl;
                cout << "1. Manually" << endl;
                cout << "2. Automatically" << endl;
                autoTemp = getInt(1,2)-1;
                if (autoTemp)
                    initializeBoardAuto(p2Board, true);
                else initializeBoard(p2Board);

            }
            if (!player2.isPlayerAutomatic() && !player1.isPlayerAutomatic())
                cout<<string(100,'\n');

            return;
        };

        void printGameState(User p) {
            cout << p.getName() << "'s current game:" << endl;
            if (p.getPlayerNum()==1) {
                cout << "YOUR BOARD: " << endl;
                p1Board.printPublicBoard();
                cout << "YOUR OPPONENT'S BOARD: " << endl;
                p2Board.printPrivateBoard();
                cout << endl << endl;
            }
            else {
                cout << "YOUR BOARD: " << endl;
                p2Board.printPublicBoard();
                cout << "YOUR OPPONENT'S BOARD: " << endl;
                p1Board.printPrivateBoard();
                cout<<endl<<endl;
            }
            return;
        };

        void initializeBoard(Gameboard &b) {
            int xEntry, yEntry, horizEntry, attemptCount;
            string entryTemp;
            for (int i = 0; i < shipCount; i++) {
                attemptCount = 0;
                do {
                    b.printPublicBoard();
                    if (attemptCount>0) 
                        cout << "INVALID ENTRY for that ship! Please try again." << endl;

                    cout << "Please enter location [Letter][Number] for the " <<
                                "top/left of your " << shipName[i] << " which is length "
                                << shipLength[i] << ": " << endl;
                    entryTemp = getSquare();		
                    xEntry=static_cast<int>(entryTemp[0]);
                    yEntry=static_cast<int>(entryTemp[1]);

                    cout << "Which direction would you like to place your ship?" << endl;
                    cout << "1. Vertically" << endl;
                    cout << "2. Horizontally" << endl;
                    horizEntry = getInt(1,2)-1;

                    attemptCount++;
                } 
                while (!b.placeShip(i, xEntry-letterASCII, yEntry-numberASCII, horizEntry));
            }

            cout << "Your starting board: " << endl;
            b.printPublicBoard();

            return;
        };

        // initializes a board with random placement of ships on a board 
        void initializeBoardAuto(Gameboard &b, bool print) {
            int xEntry, yEntry, horizEntry;

            for (int i = 0; i < shipCount; i++) {
                do {
                    xEntry = rand() % 10;
                    yEntry = rand() % 10;
                    horizEntry = rand() % 2;
                } 
                while (!b.placeShip(i, xEntry, yEntry, horizEntry));
            }

            if (print) {
                cout << "Your starting board:" << endl;
                b.printPublicBoard();
            }
            return;
        };

        // returns enum determining state of game
        state gameCondition() {
            if (p1Board.getNumHits() == 17)
                return p2Win;
            else if (p2Board.getNumHits() == 17)
                return p1Win;
            else
                return stillPlaying;
        };


        // function to prompt a player to actively choose which move to make 
        void getNextMove(Gameboard &b) {
            int attemptCount = 0;
            int xEntry, yEntry;
            bool goodMove = false;
            string entryTemp;

            while (!goodMove) {
                if (attemptCount > 0) 
                    cout << "That move has already been attempted. Try again." << endl;
                cout << "Please enter location [Letter][Number] of desired move:" << endl;
                entryTemp = getSquare();		
                xEntry = static_cast<int>(entryTemp[0]);
                yEntry = static_cast<int>(entryTemp[1]);

                if (b.getSpaceValue(xEntry-letterASCII, 
                                yEntry-numberASCII)!=isHIT
                    && b.getSpaceValue(xEntry-letterASCII, 
                                    yEntry-numberASCII)!=isMISS) {
                    b.recordHit(xEntry-letterASCII, yEntry-numberASCII);
                    goodMove = true;
                }
                attemptCount++;
            } 
            return;
        };

        void getNextMoveAuto(Gameboard &b) {
            bool goodMove = false;
            int xEntry, yEntry;

            while (!goodMove) {
                xEntry = rand() % 10;
                yEntry = rand() % 10;

                if (b.getSpaceValue(xEntry, yEntry)!=isHIT && b.getSpaceValue(xEntry, yEntry)!=isMISS) {
                    b.recordHit(xEntry, yEntry);
                    goodMove = true;
                }
            } 
            return;
        };

        void getNextMoveSmartAuto(Gameboard &b) {
            bool goodMove = false;
            int xEntry, yEntry;
            int xval = b.getLastX();
            int yval = b.getLastY();

            while (!goodMove) {
              if(b.getMoveFlag() == false) {
                if(b.getSpaceValue(xval, yval) == isHIT) {
                    b.saveFirstMove(xval, yval);
                    b.saveLastMove(xval, yval);
                    b.setMoveFlag(true);
                }
              }
              if(b.isthehitShipSunk(xEntry, yEntry)) {
                    b.setMoveFlag(false);
              }
              if(b.getMoveFlag() == true) {
                if (yval > 0 && b.getSpaceValue(xval, yval-1)!=isHIT && b.getSpaceValue(xval, yval-1)!=isMISS) {
                    if(b.recordHit(xval, yval-1))
                      b.saveLastMove(xval, yval-1);
                    if(b.isthehitShipSunk(xval, yval-1)) 
                      goto end;
                    goodMove = true;
                    if(b.whichShipStruck(xval, yval) != b.whichShipStruck(xval, yval-1)) {
                      xval = b.getFirstX();
                      yval = b.getFirstY();
                    }
                }
                else if (xval < 9 && b.getSpaceValue(xval+1, yval)!=isHIT && b.getSpaceValue(xval+1, yval)!=isMISS) {
                  if(b.recordHit(xval+1, yval))
                    b.saveLastMove(xval+1, yval);
                  if(b.isthehitShipSunk(xval+1, yval))
                      goto end;
                  goodMove = true;
                  if(b.whichShipStruck(xval, yval) != b.whichShipStruck(xval+1, yval)) {
                      xval = b.getFirstX();
                      yval = b.getFirstY();
                    }
                }
                else if (yval < 9 && b.getSpaceValue(xval, yval+1)!=isHIT && b.getSpaceValue(xval, yval+1)!=isMISS) {
                  if(b.recordHit(xval, yval+1))
                    b.saveLastMove(xval, yval+1);
                  if(b.isthehitShipSunk(xval, yval+1)) 
                      goto end;
                  goodMove = true;
                  if(b.whichShipStruck(xval, yval) != b.whichShipStruck(xval, yval+1)) {
                      xval = b.getFirstX();
                      yval = b.getFirstY();
                    }
                }
                else if (xval > 0 && b.getSpaceValue(xval-1, yval)!=isHIT && b.getSpaceValue(xval-1, yval)!=isMISS) {
                  if(b.recordHit(xval-1, yval))
                    b.saveLastMove(xval-1, yval);
                  if(b.isthehitShipSunk(xval-1, yval))
                      goto end;
                  goodMove = true;
                  if(b.whichShipStruck(xval, yval) != b.whichShipStruck(xval-1, yval)) {
                      xval = b.getFirstX();
                      yval = b.getFirstY();
                    }
                }
                else {
                  xval = b.getFirstX();
                  yval = b.getFirstY();
                  if(b.isthehitShipSunk(xval, yval)) 
                      goto end;
                }
              }
              else {
                end:
                xEntry = rand()%10;
                yEntry = rand()%10;

                if (b.getSpaceValue(xEntry, yEntry)!=isHIT && b.getSpaceValue(xEntry, yEntry)!=isMISS) {
                  b.recordHit(xEntry, yEntry);
                  b.saveLastMove(xEntry, yEntry);
                  goodMove = true;
                }
              }
            }
            return;
          };

        string getSquare() {
            string retString;
            getline(cin, retString);
            bool isGoodInput = false;

            while (!isGoodInput) {
                if (retString.length() == 2 && (retString[0] >= 65 && retString[0] <= 74) && (retString[1] >= 48 && retString[1] <= 57))
                    isGoodInput=true;
                else {
                    cout << "Bad input! Please enter location [Letter][Number] of your desired move, with capital letters only:" << endl;
                    getline(cin, retString);
                }
            }
            return retString;
        };
        void switchPlayers(string playerFrom, string playerTo) {
            cout << playerFrom << ", press ENTER to finish your turn!";
            cin.get();
            cout << flush;
            cout << string(100,'\n');
            cout << playerTo << ", press ENTER to start your turn!";
            cin.get();
            cout << flush;
            cout << string(100,'\n');
        };
};

class Speed : public Strategy {
    public:
        ~Speed();
        void gameModeMove(Gameboard* bptr, User* pptr, int mode) {
            while(gameCondition() == stillPlaying) {
                if (pptr->isPlayerAutomatic()) {
                    for(int i = 0 ; i < 5; i++) {
                        getNextMoveAuto(*(bptr));
                        if(gameCondition() == p1Win || gameCondition() == p2Win) 
                            break;
                    }
                }
                else {
                    printGameState(*(pptr));
                    for(int i = 0 ; i < 5; i++) {
                        getNextMove(*(bptr));
                        if(gameCondition() == p1Win || gameCondition() == p2Win) 
                            break;
                    }
                    printGameState(*(pptr));
                }
                if (pptr->getPlayerNum() == 1) {
                    if (!player1.isPlayerAutomatic() && !player2.isPlayerAutomatic()) 
                        switchPlayers(player1.getName(), player2.getName());
                    pptr = &player2; 
                    bptr = &p1Board;
                }
                else {
                    if (!player1.isPlayerAutomatic() && !player2.isPlayerAutomatic())
                        switchPlayers(player2.getName(), player1.getName());
                    pptr = &player1;
                    bptr = &p2Board;
                }
            }
        };       
};

class Easy : public Strategy {
    public:
        ~Easy();
        void gameModeMove(Gameboard* bptr, User* pptr, int mode){
            while(gameCondition() == stillPlaying) {
                if (pptr->isPlayerAutomatic()) {
                    getNextMoveAuto(*(bptr));
                }
                else {
                    printGameState(*(pptr));
                    getNextMove(*(bptr));
                    printGameState(*(pptr));
                }
                if (pptr->getPlayerNum()==1) {
                    if (!player1.isPlayerAutomatic() && !player2.isPlayerAutomatic())
                        switchPlayers(player1.getName(), player2.getName());
                    pptr = &player2; 
                    bptr = &p1Board;
                }
                else {
                    if (!player1.isPlayerAutomatic() && !player2.isPlayerAutomatic())
                        switchPlayers(player2.getName(), player1.getName());
                    pptr = &player1;
                    bptr = &p2Board;
                }
            }
        };
};

class Hard : public Strategy {
    public:
        ~Hard();
        void gameModeMove(Gameboard* bptr, User* pptr, int mode) {
            while(gameCondition() == stillPlaying) {
                if (pptr->isPlayerAutomatic())
                    getNextMoveSmartAuto(*(bptr));
                else {
                    printGameState(*(pptr));
                    getNextMove(*(bptr));
                    printGameState(*(pptr));
                }
                if (pptr->getPlayerNum()==1) {
                    if (!player1.isPlayerAutomatic() && !player2.isPlayerAutomatic()) 
                        switchPlayers(player1.getName(), player2.getName());
                    pptr = &player2; 
                    bptr = &p1Board;
                }
                else {
                    if (!player1.isPlayerAutomatic() && !player2.isPlayerAutomatic())
                        switchPlayers(player2.getName(), player1.getName());
                    pptr = &player1;
                    bptr = &p2Board;
                }
            }
        };
};

class Game {
    private: 
        Strategy *strat;
	public:	
        Game(Strategy * s) : strat(s) {};
        virtual ~Game() = default;
        virtual void setStrategy(Strategy * s) {
            strat = s;
        };
        void gameinterface(int mode) {
            strat->playGame(mode);
        };

};


#endif
