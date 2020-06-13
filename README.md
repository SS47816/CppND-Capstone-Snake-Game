# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.



## Code Structure

<img src="file_structure.png"/>

#### 1. `main.cpp`

This file remains unchanged, still contains some constant variables related to the window settings and creates instances of `Game`, `Renderer`, `Controller` and calls function `Game::Run()` to start up the game.

#### 2. `snake.h` and `snake.cpp`

Implements class `Snake`, including the important attributes of the snake `head` and snake `body`. It is in charge of controlling the behaviors of the snake such as `GrowBody()`, `UpdateHead()`, `UpdateBody()`, etc. 

The modifications made was that the random number generator was moved to new classes `Food` and `Obstacle` and let them deal with that themselves. New function `CheckIfAlive()` was added to check if the snake is still alive based on the position of the head and the walls and obstacles. The speed control of the snake was modified slightly into increase by percentage.

#### 3. `game.h` and `game.cpp`

These two files manages the main logics of the game, which at its core is the Input-Update-Render loop. The modifications made to this file was mainly to accommodate the introduced new features of the game.

#### 4. `renderer.h` and `renderer.cpp`

These two files contains the `rederer` object which is in charge of rendering the visuals to the screen. These files were slightly modified to include `obstacles` object for rendering as well and changed the colors of each types of object.

#### 5. `controller.h` and `controller.cpp`

These two files implemented the `Controller` class which deals with user inputs from the keyboard to control the motion of the snake. 

### Newly Added Files

#### 6. `Food.h` and `Food.cpp` 

Implements class `Food` which represents three different types of foods the snake likes (with different colors of course). The class `Food` is in charge of generating a food on the map randomly of a certain type, as well as store the unique effects of each type of food. The probabilities, scores, colors, and special effects of each type of food are also stored in this class as private members. 

#### 7. `Obstacle.h` and `Obstacle.cpp`

Implements class `Obstacle` which mainly consists of a `vector` of `rocks`, with each rock being a `SDL+Point` , a grid on the map represented by Grey color. The class also provides function `RockCell()` to check if the snake head hits any of the rocks. 



## New Game Features

### Increased Difficulties
Besides biting himself, two more ways of dying are introduced to the game to increase the difficulty in control and timing: 

* The snake will die if he hits the wall. 

* Rocks will be randomly generated at the game start. If the snake hits the rock, it will die as well.

### More Fun
* Magic Fruits: 

  Now we have more types of foods and each of them provides unique effects on the snake. The foods will still appear one at a time however the type as well as its effect will be totally unpredictable! 

  Hope by introducing this slight amount of randomness will be more fun! Also the mechanism of rewarding the player by reducing the snake's speed could reduced the difficulty and increase the game length and final score.

| Food Type         | Color  | Score | Speed           | Effect                               |
| ----------------- | :----- | :---- | --------------- | ------------------------------------ |
| Worm              | Yellow | 1     | Speed +10%      | Snake's normal daily food            |
| Poisoned Mushroom | Green  | 0     | Speed -50%      | "I feel dizzy~"                      |
| Berry             | Pink   | 1~10  | Speed -50%~+50% | "You won't know until you tasted it" |

### Additional Features
* The snake's speed will increase in a proportional manner (ie. speed +10% after eating a normal food). This aims to lower down the difficulty slightly and hope that together with the other new game mechanisms,  this can prolong the length of one game.

* The window title will now display the current speed of the snake (with 1.0x as the initial speed). The player now could better visualize the effect of different foods.

### Original Game Bugs Fixed
* Fix: The food might be generated outside the game window.




## Rubric Points Addressed

#### Loops, Functions, I/O

| Criteria                                                     | Applied to       |
| ------------------------------------------------------------ | ---------------- |
| The project demonstrates an understanding of C++ functions and control structures. | Everywhere       |
| The project accepts user input and processes the input.      | `controller.cpp` |

#### Object Oriented Programming
| Criteria                                                     | Applied to                  |
| ------------------------------------------------------------ | --------------------------- |
| The project uses Object Oriented Programming techniques.     | Everywhere                  |
| Classes use appropriate access specifiers for class members. | Class  `Food`, `Obstacles`, |
| Class constructors utilize member initialization lists.      | Class  `Food`, `Obstacles`, |
| Classes encapsulate behavior.                                | Class  `Food`, `Obstacles`, |

#### Memory Management

| Criteria                                                     | Applied to                                        |
| ------------------------------------------------------------ | ------------------------------------------------- |
| The project makes use of references in function declarations. | Everywhere                                        |
| The project uses move semantics to move data, instead of copying it, where possible. | `obstacle.cpp`                                    |
| The project uses smart pointers instead of raw pointers.     | `snake`, `food`, `obstacles` instances everywhere |

