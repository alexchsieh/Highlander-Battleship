# Highlander Battleship
  Authors: <[Hallie Pham](https://github.com/halliehp)>  <[Samuel Ha](https://github.com/hajitae)>  <[Angelika Bermudez](https://github.com/angelikab028)>  <[Alex Hsieh](https://github.com/Potanz)>

## Installation/Usage
    1. Download the file as a zip.
    2. Run ./a.out.
    3. You are then first prompted to start a new game or quit.
    4. You are then prompted to choose which game mode to play.

## Project Description
 ### Purpose
 We will be building a single player Battleship game, based on the boardgame. The player will play against the computer in a game of guessing where each battleship is until all ships are sunk, leading to a win for either the player or the computer. We are interested in this concept because we want to see how well a computer can do in a game that is solely based on luck.
 ### Tools, Languages, and Technologies
 * **C++**
   * Using a command line main menu
   * The backend of the project
 * [**Microsoft Visual Studio Code**](https://code.visualstudio.com/)
   * IDE used by all project members
 * **Vim**
   * Text editor used by all project members
 * **CMake**
   * Compiling and building testing, packaging, and installation of the software
 * **GoogleTest**
   * Unit testing library
 * **Valgrind**
   * Memory debugging, memory leak detection, and profiling
 ### Detailed Description
 Upon running the program, the player will be welcomed and prompted to start a new game or quit. If the player quits, the program stops. If the player starts a new game, they will be asked to choose which game mode they would like to play. After the mode is chosen, the user is prompted with their name and player 2's name. Then, the user is asked to differentiate which player is human and which player is the computer. Afterwards, the user is able to choose whether they want their ships to be placed manually or automatically. If the player chooses the ship placement to be manually, the game will start out with a small grid printing to the console to show the player where they could place their ships, otherwise a small grid with ships already placed will be printed to the console. Then the player will begin guessing against the computer. The 'O's will be the ship parts that the player has hit and the 'X's will be the missed shots. Before every turn, the map will be printed out again to display the guesses of the player and the computer. Inputs will be taken as coordinates on the grid, for example guessing "A6". The x-axis of the grid will be letters and the y-axis of the grid will be numbers, identical to the traditional game of Battleship.<br/> <br/>
 This game will offer 3 modes: easy, hard, and speed.  
 * Easy mode will have the player playing against a computer algorithm that guesses blindly and does not react to a correct guess.  
 * Hard mode will be using a computer algorithm that guesses randomly until it hits a correct guess, in which then it would guess around the same area to fully eliminate a ship. 
 * Speed mode is inspired by the concept of speed chess. The player will input 5 guesses at once per turn instead of just one, and the computer will do the same. <br/>

![battleship screenshot1](https://github.com/cs100/final-project-hpham087-aberm028-ahsie014-sha030/blob/0d25a872d90a7cc9854ae1d5dbcce624f24dbafa/images/Battleship%20Screenshot1.png)

![battleship screenshot2](https://github.com/cs100/final-project-hpham087-aberm028-ahsie014-sha030/blob/0d25a872d90a7cc9854ae1d5dbcce624f24dbafa/images/Battleship%20Screenshot2.png)
 
## Class Diagram
  ![class diagram](https://github.com/cs100/final-project-hpham087-aberm028-ahsie014-sha030/blob/6dbfee32ed22ee9f345765a1d0bcd5b0155c9f9e/images/UML%20Class%20Diagram.png)
**Highlander Battleship will begin when the client class, our Main class, welcomes and prompts the user to choose whether to start a new game or to quit. The Main class consists of the following functions:**

 * *public printMenu()* - Prints the layout of the menu that the user is met with upon running the program.
 * *public chooseMode()* - Prompts the user to choose which one of three modes that they want to play.

**The client, Main class, uses the Singleton class, which instantiates one Singleton Game object at a time. The class has the following constructors and functions:**

 * *private Singleton()* - Private default constructor that forces the usage of the public getter function
 * *public static Singleton getInstance()* - Getter function which instantiates the Singleton object

**The Main class is associated with and the Singleton class is dependent on the Game class, which consists of the following constructors and functions:**

 * *private Game()* - A private default constructor to force the usage of Game(Strategy)
 * *public Game(Strategy)* - A public constructor that instantiates a single Game object
 * *public ~Game()* - Destructor of the Game object
 * *public setStrategy(Strategy)* - Changed the pointer that would dictate which algorithm the Game object would use at runtime
 * *public gameInterface(int)* - Would select which algorithm the Game object would use to run the playGame() function at runtime

**The Game class has a relationship of aggregation with the Strategy class. The three different modes for our Battleship game: Easy, Speed, and Hard classes inherit from the Strategy class and utilize the same functions through a strategy design pattern. These classes contain the following functions:**

 * *public startGame()* - Prompts the user with inputting the player names and general setup
 * *public playGame(int)* - Starts calling game moves
 * *public gameModeMove(Gameboard*, *User*, *int)* - Passes in which next move according to which Gameboard, user, and mode
 * *public printGameState(User)* - Prints both current boards
 * *public initializeBoard(Gameboard)* - Prompts the user to enter coordinates to place their ships on the boards 
 * *public initializeBoardAuto(Gameboard, bool)* - Automatically adds all the ships to the board
 * *public gameCondition()* - Checks whether the game is complete or not
 * *public getNextMove(Gameboard)* - Getter function for the next move
 * *public getNextMoveAuto(Gameboard)* - Getter function for the next move if it is automatically
 * *public getNextMoveSmartAuto(Gameboard)* - Getter function for the next move if it is a smart automatic move
 * *public getSquare()* - Getter function for a square on the board
 * *public switchPlayers(string, string)* - Function that switches between player 1 and player 2

**The Strategy class is composed of the User and Gameboard classes. The User class has the following constructors and functions:**

 * *public User()* - Default User constructor that assigns values when user does not input anything
 * *public User(string, bool, int)* - User constructor that takes in a string for the name, checks whether the user is automatic with a bool, and takes in an integer for the player number
 * *public User(const User&)* - User copy constructor
 * *public User& operator=(const User&)* - User copy assignment operator
 * *public getName()* - Getter function for player name
 * *public isPlayerAutomatic()* - Boolean checker for whether the player is automatic or not
 * *public getPlayerNum()* - Getter function for player number
 * *public setName(string)* - Setter function for player name
 * *public setAuto(bool)* - Setter function for whether the player is automatic or not
 * *public setPlayerNum(int)* - Setter function for player number

**The Gameboard class has the following constructors and functions:**

 * *public Gameboard()* - Default Gameboard constructor 
 * *public Gameboard(const Gameboard&)* - Gameboard copy constructor
 * *public Gameboard& operator=(const Gameboard&)* - Gameboard copy assignment operator
 * *public ~Gameboard()* - Destructor of the Gameboard object
 * *public getNumHits()* - Getter function for number of hits
 * *public printPrivateBoard()* - Prints out the opponent's board, only displays hits or misses
 * *public printPublicBoard()* - Prints out the player’s board
 * *public getSpaceValue(int, int)* - Getter function for the coordinate values
 * *public recordHit(int, int)* - Record a hit on the board by attempting to record a hit on every ship, if a ship is hit, change board position to hit and return true, if no ship is hit, change board positions to miss and return false
 * *public istheHitShipSunk(int, int)* - Boolean function that checks if the hit ship is sunk
 * *public whichShipSunk(int, int)* - Function that checks which of the ships sunk
 * *public saveFirstMove(int, int)* - Function that saves the first move played
 * *public getFirstX()* - Getter function for the first x value
 * *public getFirstY()* - Getter function for the first y value
 * *public saveLastMove(int, int)* - Function that saves the last move played
 * *public getLastX()* - Getter function for the last x value
 * *public getLastY()* - Getter function for the last y value
 * *public getFlagMove()* - Getter function for the flag move
 * *public placeShip(int, int, bool)* - Function that places ships on the board (checks for valid coordinates and whether it is vertical or horizontal)

**The Ship class is composed and contained by the Gameboard class, and is made up of the following constructors and functions:**

 * *public Ship(int, string)* - Ship constructor that initializes a ship if only size and name are specified
 * *public Ship(int, string, int, int, bool, bool)* - Ship constructor that can place a ship when it is initialized 
 * *public Ship(const Ship)* - Ship copy constructor
 * *public Ship& operator=(const Ship&)* - Ship copy assignment operator
 * *public ~Ship()* - Destructor of the Ship object
 * *public getSize()* - Getter function for the size of the ship
 * *public getX()* - Getter function for the x value
 * *public getY()* - Getter function for the y value
 * *public isShipSunk()* - Boolean function that checks if the ship is sunk
 * *public isShipHorizontal()* - Boolean function that checks if the ship is horizontal
 * *public getName()* - Getter function for the player name
 * *public setPosition(int, int, bool)* - Setter function for the position of a ship
 * *public printShip()* - Print ship to the console for visualization (only used for debugging purposes)
 * *public recordHit(int, int)* - Boolean function to record a hit on a ship, return false if it is a miss, true if there is a hit

## Design Patterns
1. Singleton - We chose the singleton design pattern with the Singleton class having one instantiation of a Singleton Game object at one time, because there is only a single game of battleship ongoing while the program is running. Using singleton, we implemented a private default constructor for the Singleton class to force use a getter function, getInstance(), in order to create a Singleton Game object. This pattern in particular was most useful to us because only one battleship game is being played at a time.   <br/>
2. Strategy - We chose the strategy design pattern to implement multiple versions of the game.  Depending on which gamemode difficulty that the player has chosen, we will choose that specific strategy at runtime.  The default easy gamemode has subclasses hard and speed, which allows them to take the algorithm from easy and transform it into something similar, but different. We did not want the player to have to know exactly how the code works, just that the gamemodes would be in differing difficulty.  Strategy allows for us to not have to rewrite an entirely new algorithm for each gamemode. <br/>
