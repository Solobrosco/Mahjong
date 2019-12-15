#include <MahjongTiles.h>

MahjongTiles::MahjongTiles(int numTiles){
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

std::vector<int> MahjongTiles::getTiles(){
    return T;
}


MahjongTiles::~MahjongTiles(){
    std::cout << "Destroying Tiles..." << std::endl;
}