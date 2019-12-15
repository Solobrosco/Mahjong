#include <Mahjong.h>

std::mt19937 rng (std::random_device{}());
std::uniform_int_distribution<> tile (0, 144 - 1);

Mahjong::Mahjong(){
	std::cout << "Setting up Mahjong game" << std::endl;
    numTiles = 144;
    for(int i = 0; i < numTiles; i++){
        Tiles.push_back(i+1);
        // std::cout << Tiles[i] << " " << std::endl;
    }

    East = new Player();
    North = new Player();
    West = new Player();
    South = new Player();
}


//================================================================================================================================

void Mahjong::reset(){
    // for(int i = 0; i < numTiles; i++){
    //     Tiles.push_back(i+1);
    //     std::cout << Tiles[i] << " ";
    // }
    // std::random_shuffle(std::begin(Tiles), std::end(Tiles));
}

void Mahjong::handle(int x,int y, MouseButton click){

}

ucm::json Mahjong::getBoard(){
    std::cout << "Getting Mahjong game state" << std::endl;
    ucm::json result;
    int r = tile(rng);
    result["tiles"].push_back(Tiles);
    result["eastHand"].push_back(East->getHand());
    result["northHand"].push_back(North->getHand());
    result["westHand"].push_back(West->getHand());
    result["southHand"].push_back(South->getHand());
    result["garbage"].push_back(Tiles[r]);
    return result;
}

Mahjong::~Mahjong(){
    delete East;
    delete South;
    delete West;
    delete North;
    std::cout << "Destroying Mahjong" << std::endl;
}