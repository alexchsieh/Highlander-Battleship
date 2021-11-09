# Highlander Battleship
  Authors: <[Hallie Pham](https://github.com/halliehp)>  <[Samuel Ha](https://github.com/hajitae)>  <[Angelika Bermudez](https://github.com/angelikab028)>  <[Alex Hsieh](https://github.com/Potanz)>

## Project Description
 We will be building a single player Battleship game, based on the boardgame.  The player will play against the computer in a game of guessing where each battleship is. <br/
 We plan to use C++ for this project, and for it to be text based. We will also make use of Vim, Valgrind, Github, and GoogleTest. <br/>
 <br/>
 The game will start out with a small grid printing to the console to show the player where they could place their ships.  The player will input where they wish to place their ships, then will begin guessing against the computer.  The Os will be the ship parts that the player has hit and the Xs will be the missed shots.  Before every turn, the map will be printed out again to display the guesses of the player and the computer. Inputs will be taken as coordinates on the grid, for example guessing "A6." The X axis of the grid will be letters and the Y axis of the grid will be numbers.<br/> <br/>
 We are interested in this concept because we want to see how well a computer can do in a game that is based on luck. <br/>
 This game will offer 3 modes: easy, hard, and speed.  
 * Easy mode will have the player playing against a computer algorithm that guesses blindly and does not react to a correct guess.  
 * Hard mode will be using a computer algorithm that guesses randomly until it hits a correct guess, in which then it would guess around the same area to fully eliminate a ship. 
 * Speed mode is inspired by the concept of speed chess. The player will input 5 guesses at once per turn instead of just one, and the computer will do the same. <br/>
 
 Other added features we plan to implement is being able to save and load games you have not completed. We also plan on exploring the idea of adding "power ups" to the game, similar to Chance cards in Monopoly.  The player would be able to roll a chance card every few turns and if they roll a power up, they could save it to use it on later turns.  The power ups would be things like bringing back a sunk ship, or being able to change the position of a certain ship. <br/>

  ## Phase II
  In addition to completing the "Class Diagram" section below, you will need to:
  * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
  * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
    * Create smaller actionable development tasks as issues and assign them to team members. Place these in the `TODO` column.
    * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
  Include a class diagram(s) for your project and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).
 
  ## Phase III
  You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
  * Before the meeting you should perform a sprint plan like you did in Phase II.
  * You should also update this README file by adding the following:
    * What design patterns did you use? For each design pattern you must explain in 4-5 sentences:
      * Why did you pick this pattern? And what feature did you implement with it?
      * How did the design pattern help you write better code?
    * An updated class diagram that reflects the design patterns you used. You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description).
    * Make sure your README file (and Project board) are up-to-date reflecting the current status of your project. Previous versions of the README file should still be visible through your commit history.
 
 During the meeting with your TA you will discuss: 
  * How effective your last sprint was (each member should talk about what they did)
  * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
  * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
  * What tasks you are planning for this next sprint.

 
  ## Final deliverable
  All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
  Before the demo, you should do the following:
  * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
  * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
  * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
  Screenshots of the input/output after running your application
 ## Installation/Usage
  Instructions on installing and running your application
 ## Testing
  How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
