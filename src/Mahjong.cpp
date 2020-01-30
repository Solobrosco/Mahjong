#include <Mahjong.h>

Mahjong::Mahjong(){
	std::cout << "Setting up a game of Mahjong..." << std::endl;
    std::cout << "Getting players..." << std::endl;
    East = new Player("East");
    South = new Player("South");
    West = new Player("West");
    North = new Player("North");
    playerSet = {East, South, West, North};
    std::cout << "Setting up tiles..." << std::endl;
    tiles = new MahjongTiles(144);
    state = {"East's Turn","South's Turn","West's Turn","North's Turn","Mahjong!"};
}

//================================================================================================================================

void Mahjong::reset(){
    std::cout << "Resetting Game..." << std::endl;
    tiles->resetTiles();
    East->resetPlayer();
    South->resetPlayer();
    West->resetPlayer();
    North->resetPlayer();
    tiles->shuffleTiles();
    dealHands();
}

void Mahjong::handle(int x,int y, MouseButton click){
    // Magic numbers for Handle
    // x: {(0:0,trash)(1,east)(2,south)(3,west)(4,north)}
    // y: {(0-13,hand)(14,Chow)(15,Pong)(16,Kong)
    // Ex: (2,5,left) = left click on South hand position 6
    // Ex: (3,14) = West calls Chow
    
    // if(tiles->getTileSetAmount() > 0 && click == left){    
    //     std::mt19937 rng (std::random_device{}());
    //     std::uniform_int_distribution<> tileSet (0, tiles->getTileSetAmount() - 1);
    //     int randNum = tileSet(rng);
    //     int h = tiles->getTile(randNum);
    //     if(East->getTurn() && x == 0){
    //         std::cout << "EAST CLICKED" << std::endl;
    //         tiles->rmTile(randNum);
    //         tiles->setGarbage(East->getHand(y));
    //         East->throwTile(y);
    //         East->setHand(randNum);
    //         East->setTurn();
    //         South->setTurn();
    //     }else if(South->getTurn() && x == 1){
    //         std::cout << "SOUTH CLICKED" << std::endl;
    //         tiles->rmTile(randNum);
    //         tiles->setGarbage(South->getHand(y));
    //         South->throwTile(y);
    //         South->setHand(randNum);
    //         South->setTurn();
    //         West->setTurn();
    //     }else if(West->getTurn() && x == 2){
    //         std::cout << "WEST CLICKED" << std::endl;
    //         tiles->rmTile(randNum);
    //         tiles->setGarbage(West->getHand(y));
    //         West->throwTile(y);
    //         West->setHand(randNum);
    //         West->setTurn();
    //         North->setTurn();
    //     }else if(North->getTurn() && x == 3){
    //         std::cout << "NORTH CLICKED" << std::endl;
    //         tiles->rmTile(randNum);
    //         tiles->setGarbage(North->getHand(y));
    //         North->throwTile(y);
    //         North->setHand(randNum);
    //         North->setTurn();
    //         East->setTurn();
    //     }
    // }else if(click ==  left && x == -1){
    //     std::cout << "TRASH CLICKED" << std::endl;
    // }
}

ucm::json Mahjong::getBoard(){
    std::cout << "Getting game state..." << std::endl;
    ucm::json result;
    for(int i = 0; i < playerSet.size(); i++){
        if(playerSet[i]->getTurn()){
            result["State"].push_back(state[i]);    
        }
    }
    result["Tiles"].push_back(tiles->getTiles());
    result["Thrown"].push_back(tiles->getThrown());
    result["EastHand"].push_back(East->getHand());
    result["SouthHand"].push_back(South->getHand());
    result["WestHand"].push_back(West->getHand());
    result["NorthHand"].push_back(North->getHand());
    result["EastReveal"].push_back(East->getReveal());
    result["SouthReveal"].push_back(South->getReveal());
    result["WestReveal"].push_back(West->getReveal());
    result["NorthReveal"].push_back(North->getReveal());
    return result;
}

void Mahjong::dealHands(){
    do{
        for(int i = 0; i < playerSet.size(); i++){
            if(playerSet[i]->getTurn()){ // on turn
                // draw 8 from front of tileset
                if(i < playerSet.size() - 1){
                    for(int j = 0; j < 4; j++){
                        playerSet[i]->setHand(tiles->getTileFront());
                    }
                    playerSet[i]->setTurn();
                    playerSet[i+1]->setTurn();
                }else{
                    for(int j = 0; j < 4; j++){
                        playerSet[i]->setHand(tiles->getTileFront());
                    }
                    playerSet[i]->setTurn();
                    playerSet[0]->setTurn();
                }
            }
        }
    }while(East->getNumHand() != 16 && South->getNumHand() != 16 && West->getNumHand() != 16 && North->getNumHand() != 16);
    for(int i = 0; i < playerSet.size(); i++){
        if(playerSet[i]->getTurn()){
           playerSet[i]->setHand(tiles->getTileFront());
        }
        // for(int j = 0; j < playerSet[i]->getNumHand(); j++){
        //     if(checkBonuses(playerSet[i]->getHand(j))){
        //         playerSet[i]->setReveal(tiles->getTileBack()); 
        //     }
        // }
        // test
    }
}

bool Mahjong::checkBonuses(int tile){
    // checks if the tile is a bonus
    if(tile >= 137 && tile < 145){
        return true;
    }else{
        return false;
    }
}

Mahjong::~Mahjong(){
    delete tiles;
    delete East;
    delete South;
    delete West;
    delete North;
    // std::cout << "Stopping Mahjong..." << std::endl;
}