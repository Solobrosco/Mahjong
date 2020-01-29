#ifndef MAHJONGTILES_H
#define MAHJONGTILES_H

#include <server.h>
#include <vector>
#include <random>

/*
Tiles are numbered accordingly
Bamboo      Characters      Dots        Honors          Dragons         Bonus
    1-36        37-72         72-108        109-124         125-136         137-144
*/

class MahjongTiles{
    int numTiles;
    std::vector<int> mahjongTiles;
    std::vector<int> thrownAway;
    MahjongTiles();
public:
    MahjongTiles(int);

    void resetTiles();
    void shuffleTiles();

    int getThrown(); // 
    std::vector<int> getTiles(); //
    int getTileFront();
    int getTileBack();
    int getTileSetAmount(); //

    void setGarbage(int); //

    ~MahjongTiles();
};

#endif