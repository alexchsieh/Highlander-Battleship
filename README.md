# Highlander Battleship
  Authors: <[Hallie Pham](https://github.com/halliehp)>  <[Samuel Ha](https://github.com/hajitae)>  <[Angelika Bermudez](https://github.com/angelikab028)>  <[Alex Hsieh](https://github.com/Potanz)>

## Project Description
 We will be building a single player Battleship game, based on the boardgame.  The player will play against the computer in a game of guessing where each battleship is. <br/>
 We plan to use C++ for this project, and for it to be text based. We will also make use of Vim, Valgrind, Github, and GoogleTest. <br/>
 <br/>
 The game will start out with a small grid printing to the console to show the player where they could place their ships.  The player will input where they wish to place their ships, then will begin guessing against the computer.  The Os will be the ship parts that the player has hit and the Xs will be the missed shots.  Before every turn, the map will be printed out again to display the guesses of the player and the computer. Inputs will be taken as coordinates on the grid, for example guessing "A6." The X axis of the grid will be letters and the Y axis of the grid will be numbers.<br/> <br/>
 We are interested in this concept because we want to see how well a computer can do in a game that is based on luck. <br/>
 This game will offer 3 modes: easy, hard, and speed.  
 * Easy mode will have the player playing against a computer algorithm that guesses blindly and does not react to a correct guess.  
 * Hard mode will be using a computer algorithm that guesses randomly until it hits a correct guess, in which then it would guess around the same area to fully eliminate a ship. 
 * Speed mode is inspired by the concept of speed chess. The player will input 5 guesses at once per turn instead of just one, and the computer will do the same. <br/>
 
 Other added features we plan to implement is being able to save and load games you have not completed. We also plan on exploring the idea of adding "power ups" to the game, similar to Chance cards in Monopoly.  The player would be able to roll a chance card every few turns and if they roll a power up, they could save it to use it on later turns.  The power ups would be things like bringing back a sunk ship, or being able to change the position of a certain ship. <br/>

## Class Diagram
  ![class diagram](https://github.com/cs100/final-project-hpham087-aberm028-ahsie014-sha030/blob/759e7ce609767450b4eaa20c01b42139395450dc/UML%20Class%20Diagram.png)
Highlander Battleship will start at the Menu and will prompt whether to start a new game or load a previously started game. <br/>
Gameboard will have the following public functions:<br/>
* print_gameboard() - prints the current gameboard and the statuses of the hidden, found, and destroyed battleships.
* clear_gameboard() - clears the current gameboard so that there are no ships on either side.
* create_gameboard() - makes a new gameboard with the user’s and computer’s ships<br/>

The Gameboard class will inherit three classes: 
* TurnOptions
* PowerUps
* Modes<br/>

TurnOptions are features that progress or end the game. This class will have the following public functions:<br/>
* save() - saves the current game state
* use_powerup() - use one of three power ups
* Surrender() - forfeits the game
* game_over() - calculates whether the game is over <br/>

PowerUps will have the following public functions:<br/>
* revive() - revives a fully sunken battleship and is placed at a random location
* fully_destroy() - destroys an enemy battleship regardless of the size
* reveal() - reveals the location of a single enemy battleship<br/>

Modes is a base class and will have the following public functions:<br/>
* user_turn() - will denote how long the user's turn based on the mode
* computer_turn() - will denote how long the computer's turn based on the mode<br/>
There are three classes that will inherit the Modes base class, which are EasyMode, HardMode, and SpeedMode. The Modes class will essentially designate the difficulty and facilitate the turns between the user and the computer<br/>

## Design Patterns
1. Singleton - We chose the singleton design pattern with the Game class having one instantiation at one time, because there is only a single game of battleship ongoing while the program is running. Using singleton, we implemented a private default constructor for the Game class to force use a parametrized constructor of the Game class, which is Game(Strategy*), in order to create a singleton, Game, object. This pattern in particular was most useful to us because only one battleship game is being played at a time.   <br/>
2. Strategy - We chose the strategy design pattern to implement multiple versions of the game.  Depending on which gamemode difficulty that the player has chosen, we will choose that specific strategy at runtime.  The default easy gamemode has subclasses hard and speed, which allows them to take the algorithm from easy and transform it into something similar, but different. We did not want the player to have to know exactly how the code works, just that the gamemodes would be in differing difficulty.  Strategy allows for us to not have to rewrite an entirely new algorithm for each gamemode. <br/>

