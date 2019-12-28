#ifndef MAHJONG_H
#define MAHJONG_H

#include <random>
#include <vector>

#include <BoardGame.h>
#include <Player.h>
#include <MahjongTiles.h>


/*
This is the first attempt to make a mahjong game thru C++
These set of objects will creates the logic of the game

**Tasks**
reveal bonus tiles
add buttons to call chow, pong, or kong
Set up chow, kong and pong
Set up Mahjong
*/

class Mahjong : public BoardGame{
    // Tileset 
    const int numTiles = 144;
    MahjongTiles* tiles;
    std::vector<std::string> state;
    // The Players
    Player* East;
    Player* South;
    Player* West;
    Player* North;
public:
    // Constructors 
    Mahjong();
    Mahjong(const Mahjong&);

    // Board game fucntions
    void reset();
    void handle(int,int, MouseButton);
    ucm::json getBoard();

    // Game fucntions
    void shuffleTiles();
    bool checkBonuses(int);
    bool checkPong();
    bool checkKong();
    bool checkChow();
    bool checkMahjong();

    // Destructors
    ~Mahjong();
};

#endif