**USER MANUAL FOR CRAZY CRICKETING CHAMPS**
                                                          
This game is a 2D batting-based cricket game with music and crazy messages and sound at required instances. Use make to build the game and open the exeucatable 
**"main.exe"** to enter into the game 
_____________________________________________________________________________________________________________________________________________________________________________

_System Requirements:_ 
1) Preinstalled with SFML Library
   Download SFML Library from: https://www.sfml-dev.org/download/sfml/2.5.1/

2) RAM should be above 4GB for better game experience 
_____________________________________________________________________________________________________________________________________________________________________________

_Game Concept:_
The game begins with a welcome message which provides the main ideology behind the game and in the help window back story of game has been mentioned. 
Some kids playing cricket in their ground unfortunately gets bullied by some elder players and were kicked out from their own ground. 
You are a player with amazing cricket skills referred to as **“CHAMP”** who is going to help these kids in getting back their ground by challenging the elder players.
The elder players give you some target to hit as per the level you select. The number of wickets are decided as per overs you select for 2 overs 5 wickets
and for 5 overs 10 wickets are given to the player. 

|Levels  	|     2 Overs	         |       5 Overs       |
|---------|----------------------|---------------------|
|Easy	    |   12 – 17 Target	   |     25 – 31 Target  |
|Medium	  |   17 – 21 Target	   |     31 – 41 Target  |
|Hard	    |   21 – 25 Target	   |     41 – 51 Target  |

Chasing the opponent’s target within the given wickets, limited number of balls is the main objective of the game. 
_____________________________________________________________________________________________________________________________________________________________________________

_How to Play:_
All operations in this game are performed using keyboard.
To operate main menu and Levels Window:
1) Use UP and DOWN arrow keys to navigate
2) Press Enter to select the option as per your choice

In Help and About Window:
Press ESC to go to main menu window 

In the Game Window:
User is provided with 7-free directions, user can access those directions using the following keys

|Keyboard Key	| Player Movement                    |
|-------------|------------------------------------| 
|   A	        | Moves Left                         |
|   D	        | Moves Right                        |
|   Q	        | Moves Diagonally Left (More Angle) |
|   W	        | Moves Diagonally Left (Less Angle) |
|   E	        | Moves Straight                     |
|   R	        | Moves Diagonally Right (Less Angle)|
|   T	        | Moves Diagonally Right (More Angle)|

 Press ESC to go to main menu window in the middle of game

Use A, D and Q, W, E, R, T keys to set appropriate position for the batsman such that the bat get ball undergoes direct collision after ball pitches
on the as per the time of collision the score is given accordingly. The scores possible are 1, 2, 4, 6 runs. If ball misses the bat and directly hits the 
wicket player loses a wicket and if ball goes wide bonus score is given. 

To Close the Game:
Go to Main Menu Window and Select Close option and press ENTER to quit.
_____________________________________________________________________________________________________________________________________________________________________________

**Some of the Crazy messages used in the game:**

_Message for Six :_

<img src="https://github.com/CS20BTECH11054/cs1023-sdf-project-team-13/blob/main/Textures/Six%20message.png" width="250">

_Message for wicket:_

<img src="https://github.com/CS20BTECH11054/cs1023-sdf-project-team-13/blob/main/Textures/Wicket%20message.jpg" width="250">

_Game Conclusion:_
If the player achieves the target before runs out of wickets and balls He wins
The Elder players being amazed of Champ’s game decides to be friends with and kids and requests Champ to mentor them
If player loses, he gets encouraged by the children to play another game and try again to get their ground back
_____________________________________________________________________________________________________________________________________________________________________________

# **Developer's Manual**

## **Instructions to run the game**

To run this game, after installing all game files, the user needs to run the below lines

---

make \
./main

---

## **How the game Works?**

This game mainly uses _SFML_ library to create windows, play sounds and to create and move objects. We have four seperate folders for all types of data we use in the game. We use fonts, backgrounds, sounds and textures from their corresponding folders in the game. We  created five seperate header and cpp files for the five windows namely _menuwindow_, _helpwindow_, _aboutwindow_, _levelwindow_ and the _playwindow_ and an objects file for defining the objects we will be mainly using in the game.

### **The Main file**

The _Main file_ acts as a transition between windows, by including all the classes and objects we created for the game. We will be using goto function extensively here to switch between windows. Whenever the user selects the window he wants to enter, the call function of menuwindow returns corresponding _jumpto_(enum) values, which will be guiding main function to switch between windows.

### **The Objects file**

In this file, all the objects required for the game to run are defined and initialised, in seperate classes, which we will be using to call the objects from every window.

### **The Menu Window**

In the _Menuwindow_ file, we incorporate tile objects from objects file. We would have a call function, in which user input is recorded based on the tile selected,and it returns corresponding jumpto values which are used in the main file. In the call function, we used **state design pattern** to define the state of the tile as active or hovered or not. Based on the keys pressed, the corresponding states of the tiles are changed and the corresponding colors of tiles are changed based on their state. Whenever the user presses the Enter button, his choice would be finalised and he would be guided to the corresponding window.

### **The Help Window and About Window**

If the jumpto value refers to either _helpwindow_ or _aboutwindow_, then the control is shifted and the corresponding call functions of these windows are called.These both files mainly incorporate tile objects from objects file and display the corresponding images. Whenever the user presses the escape button, the while loop breaks and the control returns to main window.

### **The Levels Window**

In the jumpto value refers to paly tile, then the control is shifted and the call function of _Levelswindow_ is called. The _Levels window_ incorporate tiles from the objects file and it also uses state design pattern to define the states of tiles and their colors. After the user selects the two tiles, his input is recognised based on the state of the tile and a corresponding array is returned, which the playwindow would be using to initialise the game, and control is gained by the _playwindow_.

### **The Play Window**

After the control shifts to _playwindow_, call function of _playwindow_ is called.In this File, we will be incorporating many objects like bat, ball, batsman from the objects file and we would be initialising them in a function. In the call function, first we would be initialising important variables, game logic and objects properties. After that we will create a while loop, which breaks only when the user finishes the game or when he presses the escape.We will be randomly generating values and use them to position the marker, the type of the bowler and the swing/spin type. We will be using some functions specifically defined in the ball class in objects file to define the ball's movement based on the random values generated. We also record the keys pressed by the user and move the batsman accordingly and update score and overs every ball. If the user hits a 4 or 6 or lose a wicket, then a corresponding sprite is displayed while the program goes to sleep for 2 seconds along with a corresponding sound. At the end of the game, a corresponding sprite is displayed based on the result of the game.


## **Ways to develop the game**

* Some design patterns can be added to improve the game speed.
* The game can now only be played with keyboard. The game can be developed to make it playable even with mouse.
* In this game, the batsman can only play 5 types of shots. The game can be developed such that batsman can play more number of shots and run feature can be added after the batsman hits every ball.
* Settings feature can be added to the game, where user can select the keys he wishes to play and some sound settings can be added to the game.

_Technical Support:_
To contact game developers kindly mail to any of the following mails:

cs20btech11054@iith.ac.in   
cs20btech11034@iith.ac.in   
cs20btech11050@iith.ac.in   
cs20btech11025@iith.ac.in 

**Thankyou for Playing our Game hope you enjoy yourselves** 
_____________________________________________________________________________________________________________________________________________________________________________


