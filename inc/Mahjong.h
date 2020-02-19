#ifndef MAHJONG_H
#define MAHJONG_H

#include <random>
#include <vector>

#include <BoardGame.h>
#include <Player.h>
#include <MahjongTiles.h>


/*
This is the first attempt to make a mahjong game in C++
These set of objects will create the logic of the game

**Tasks**
Set up chow, kong and pong
Set up Mahjong
*/

class Mahjong : public BoardGame{
    // key variables to start game
    // const int numTiles = 144;
    // const int players = 4;
    // The Players
    Player* East;
    Player* South;
    Player* West;
    Player* North;
    std::vector<Player*> playerSet;
    // Tileset 
    MahjongTiles* tiles;
    std::vector<std::string> state;

public:
    // Constructors
    Mahjong();

    // Board game functions
    void reset();
    void handle(int,int, MouseButton);
    ucm::json getBoard();

    // Game functions
    void dealHands();
    void revealBonusTiles();
    bool checkBonuses(int);
    bool checkPong();
    bool checkKong();
    bool checkChow();
    bool checkMahjong();

    // Destructors
    ~Mahjong();
};

#endif