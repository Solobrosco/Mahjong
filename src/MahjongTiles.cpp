#include <MahjongTiles.h>

MahjongTiles::MahjongTiles(int numTiles){
    if(numTiles == 144){
        std::cout << "Creating Tiles..." << std::endl;
        this->numTiles = numTiles;
    }
    else{
        std::cout << "Not the right amount of Tiles" << std::endl;
    }
}

void MahjongTiles::resetTiles(){
    mahjongTiles.clear();
    thrownAway.clear();
    for(int i = 0; i < numTiles; i++){
        mahjongTiles.push_back(i+1);
    }
    thrownAway.push_back(-1);
}

void MahjongTiles::shuffleTiles(){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(std::begin(mahjongTiles),std::end(mahjongTiles), std::default_random_engine(seed));
}

int MahjongTiles::getThrown(){
    return thrownAway.back();
}

std::vector<int> MahjongTiles::getTiles(){
    return mahjongTiles;
}

int MahjongTiles::getTileFront(){
    int rtn = mahjongTiles[0];
    mahjongTiles.erase(mahjongTiles.begin());
    return rtn;
}

int MahjongTiles::getTileBack(){
    int rtn = mahjongTiles.back();
    mahjongTiles.erase(mahjongTiles.end());
    return rtn;
}

int MahjongTiles::getTileSetAmount(){
    return mahjongTiles.size();
}

void MahjongTiles::setGarbage(int newTile){
    thrownAway.push_back(newTile);
}

MahjongTiles::~MahjongTiles(){
    // std::cout << "Destroyed Tiles" << std::endl;
}