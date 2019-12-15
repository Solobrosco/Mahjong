#ifndef MAHJONGTILES_H
#define MAHJONGTILES_H

#include <server.h>
#include <vector>

class MahjongTiles{
    MahjongTiles();
    std::vector<int> T;
public:
    MahjongTiles(int);
    MahjongTiles(const MahjongTiles&);

    std::vector<int> getTiles();

    ~MahjongTiles();
};

#endif