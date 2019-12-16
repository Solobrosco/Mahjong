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
set dynamic tile movement for players
*/

class Mahjong : public BoardGame{
    // Tileset 
    const int numTiles = 144;
    MahjongTiles* tiles;
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
    bool checkPong();
    bool checkKong();
    bool checkChow();
    bool checkWin();

    // Destructors
    ~Mahjong();
};

#endif