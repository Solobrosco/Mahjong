#ifndef MAHJONG_H
#define MAHJONG_H

#include <random>
// #include <boost/algorithm/algorithm.hpp>
#include <vector>

#include <BoardGame.h>
#include <Player.h>


/*
This is the first attempt to make a mahjong game thru C++
The logic will follow the use of magic numbers

**Tasks**
set dynamic tile movement for players

*/

class Mahjong : public BoardGame{
    // The tileset of mahjong
    std::vector<int> Tiles;
    int numTiles;
    // The Players
    Player* East;
    Player* South;
    Player* West;
    Player* North;
public:
    // Constructors 
    Mahjong();
    Mahjong(const Mahjong&);

    // Game fucntions
    void reset();
    void handle(int,int, MouseButton);
    ucm::json getBoard();

    int getTiles();
    bool checkPong();
    bool checkKong();
    bool checkChow();
    bool checkwin();

    // Destructors
    ~Mahjong();
};

#endif