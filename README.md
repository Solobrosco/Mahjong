# Mahjong Repository

  

This is a repository for the Chinese tile-based game played through a progressive web appliction.

## Setup
1. Clone repository using **HTTPS**
	```sh

	git clone https://github.com/Solobrosco/Mahjong.git

	```
2. Navigate to the Mahjong folder
	```sh

	cd Mahjong

	```
3.  Type make
	 ```sh

	make

	```
4. Run locally on PORT 18080
 	 ```sh

	./bin/server -t templates/ -s static/ 

	```
5.  Open [http://localhost:18080](http://localhost:18080/) to view the app.

## MAKEFILE


- **make** Compiles the application.

-  **make clean** Removes all object files compiled.

-  **make scratch** Compiles the scratchpad.cpp file.

-  **make test** Compiles test cases.

  

## Folder structure
- **bin/** 
- **chart/** 
- **dep/** 
- **inc/** 
- **obj/** 
- **scratchpad/** 
- **src/** 
- **static/** 
- **templates/** 
- **test/** 

  

## How to play

  

There are various styles of playing Mahjong. This is attempt to adapt a rudimentary way of playing with the help of Wiki. (Note: does not follow exactly)

The game is played with four people on a table with 144 mahjong tiles, that all players shuffle around at the start of the game.

Each player is responsible for building a section of a four sided wall (2x18) placed in the middle of the table.

One player rolls a pair of dice to find who's wall the game deals tiles from, counting counter clockwise.

Then the player rolls again, the tile number from right to left of their wall is then divided for the front and back of the tile set.

Then counterclockwise, each player takes 8 tiles from the front of the tile set until 16 tiles are in the hand.

Any Bonus tiles are taken out of the hand and revealed on the table, replacing it with a title taken from the back of the tile set.

Then the process of discarding a tile from your hand, replacing with a new tile from the wall repeats counterclockwise, with the goal of getting a Mahjong.

The discarded pieces are thrown in the center of the board faced up were Players can call Kong, Pong, or Chow.

A winning hand(Mahjong) consist of four melds (Pongs, Kongs, or Chows) and a pair (eyes).