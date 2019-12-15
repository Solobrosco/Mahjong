#include <MahjongTiles.h>

MahjongTiles::MahjongTiles(const int numTiles){
    if(numTiles == 144){
        std::cout << "Creating Tiles..." << std::endl;
        for(int i = 0; i < numTiles; i++){
            T.push_back(i+1);
            // std::cout << T[i] << " " << std::endl;
        }
    }
    else{
        std::cout << "Not the right amount of Tiles" << std::endl;
    }
}

MahjongTiles::MahjongTiles(const MahjongTiles& other){

}

void MahjongTiles::rmTile(int x){
    T.erase(T.begin() + x);
}



void MahjongTiles::setGarbage(int t){
    G.push_back(t);
}


int MahjongTiles::getGarbage(){
    return G.back();
}

std::vector<int> MahjongTiles::getTiles(){
    return T;
}

int MahjongTiles::getTile(int p){
    return T[p];
}

int MahjongTiles::getAmount(){
    return T.size();
}



MahjongTiles::~MahjongTiles(){
    std::cout << "Destroyed Tiles" << std::endl;
}