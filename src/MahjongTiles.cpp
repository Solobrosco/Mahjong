#include <MahjongTiles.h>

MahjongTiles::MahjongTiles(const int numTiles){
    if(numTiles == 144){
        // std::cout << "Creating Tiles..." << std::endl;
        for(int i = 0; i < numTiles; i++){
            mahjongTiles.push_back(i+1);
            // std::cout << T[i] << " " << std::endl;
        }
    }
    else{
        std::cout << "Not the right amount of Tiles" << std::endl;
    }
}

void MahjongTiles::rmTile(int x){
    mahjongTiles.erase(mahjongTiles.begin() + x);
}

int MahjongTiles::getGarbage(){
    return thrownAway.back();
}

std::vector<int> MahjongTiles::getTiles(){
    return mahjongTiles;
}

int MahjongTiles::getTile(int p){
    return mahjongTiles[p];
}

int MahjongTiles::getAmount(){
    return mahjongTiles.size();
}

void MahjongTiles::setGarbage(int newTile){
    thrownAway.push_back(newTile);
}

MahjongTiles::~MahjongTiles(){
    // std::cout << "Destroyed Tiles" << std::endl;
}