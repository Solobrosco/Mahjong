#ifndef MAHJONGTILES_H
#define MAHJONGTILES_H

#include <server.h>
#include <vector>

/*
Tiles are numbered accordingly
Bamboo
    1-36
Characters
    37-72
Dots
    72-108
Honors
    109-124
Dragons
    125-136
Bonus
    137-144
*/

class MahjongTiles{
    MahjongTiles();
    std::vector<int> T;
    std::vector<int> G;
public:
    MahjongTiles(int);
    MahjongTiles(const MahjongTiles&);

    void rmTile(int);  

    void setGarbage(int);

    int getGarbage();
    std::vector<int> getTiles();
    int getTile(int);
    int getAmount();

    ~MahjongTiles();
};

#endif