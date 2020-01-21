#ifndef MAHJONGTILES_H
#define MAHJONGTILES_H

#include <server.h>
#include <vector>

/*
Tiles are numbered accordingly
Bamboo      Characters      Dots        Honors          Dragons         Bonus
    1-36        37-72         72-108        109-124         125-136         137-144
*/

class MahjongTiles{
    MahjongTiles();
    std::vector<int> mahjongTiles;
    std::vector<int> thrownAway;
public:
    MahjongTiles(int);
    MahjongTiles(const MahjongTiles&);

    void rmTile(int); //

    int getGarbage(); // 
    std::vector<int> getTiles(); //
    int getTile(int); //
    int getAmount(); //

    void setGarbage(int); //

    ~MahjongTiles();
};

#endif