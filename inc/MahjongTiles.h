#ifndef MAHJONGTILES_H
#define MAHJONGTILES_H

#include <server.h>
#include <vector>

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