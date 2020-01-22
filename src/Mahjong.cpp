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
    if(tiles->getTileSetAmount() > 0 && click == left){    
        std::mt19937 rng (std::random_device{}());
        std::uniform_int_distribution<> tileSet (0, tiles->getTileSetAmount() - 1);
        int randNum = tileSet(rng);
        int h = tiles->getTile(randNum);
        if(East->getTurn() && x == 0){
            std::cout << "EAST CLICKED" << std::endl;
            tiles->rmTile(randNum);
            tiles->setGarbage(East->getHand(y));
            East->throwTile(y);
            East->setHand(randNum);
            East->setTurn();
            South->setTurn();
        }else if(South->getTurn() && x == 1){
            std::cout << "SOUTH CLICKED" << std::endl;
            tiles->rmTile(randNum);
            tiles->setGarbage(South->getHand(y));
            South->throwTile(y);
            South->setHand(randNum);
            South->setTurn();
            West->setTurn();
        }else if(West->getTurn() && x == 2){
            std::cout << "WEST CLICKED" << std::endl;
            tiles->rmTile(randNum);
            tiles->setGarbage(West->getHand(y));
            West->throwTile(y);
            West->setHand(randNum);
            West->setTurn();
            North->setTurn();
        }else if(North->getTurn() && x == 3){
            std::cout << "NORTH CLICKED" << std::endl;
            tiles->rmTile(randNum);
            tiles->setGarbage(North->getHand(y));
            North->throwTile(y);
            North->setHand(randNum);
            North->setTurn();
            East->setTurn();
        }
    }else if(click ==  left && x == -1){
        std::cout << "TRASH CLICKED" << std::endl;
    }
}

ucm::json Mahjong::getBoard(){
    // std::cout << "Getting Mahjong game state" << std::endl;
    std::vector<int> bend = {1,2,3,4,5};
    ucm::json result;
    if(East->getTurn()){
        result["state"].push_back(state[0]);
    }else if(South->getTurn()){
        result["state"].push_back(state[1]);
    }else if(West->getTurn()){
        result["state"].push_back(state[2]);
    }else if(North->getTurn()){
        result["state"].push_back(state[3]);
    }
    result["tiles"].push_back(tiles->getTiles());
    result["eastHand"].push_back(East->getHand());
    result["northHand"].push_back(North->getHand());
    result["westHand"].push_back(West->getHand());
    result["southHand"].push_back(South->getHand());
    result["garbage"].push_back(tiles->getGarbage());
    result["eReveal"].push_back(bend);
    result["sReveal"].push_back(South->getReveal());
    result["wReveal"].push_back(West->getReveal());
    result["nReveal"].push_back(North->getReveal());
    return result;
}

void Mahjong::dealHands(){
    // do{
    //     for(int i = 0; i < playerSet->size(); i++){
    //         while(playerSet[i]->getTurn() == true){ // on turn
    //             // draw 8 from front of tileset
    //             if(i < playerSet->size() - 1){
    //                 playerSet[i]->setTurn();
    //                 playerSet[i+1]->setTurn();
    //             }else{
    //                 playerSet[i]->setTurn();
    //                 playerSet[0]->setTurn();
    //             }
    //         }
    //     }
    // }while(East->getNumHand() != 16 && South->getNumHand() != 16 && West->getNumHand() != 16 && North->getNumHand() != 16);
    // // Random # generator
    // std::mt19937 rng (std::random_device{}());
    // int r,h;
    // // each player should have 13 tiles with starting player with 14 to throw away 1
    // std::uniform_int_distribution<> tileSet (0, tiles->getTileSetAmount() - 1);
    // r = tileSet(rng);
    // h = tiles->getTile(r);
    // tiles->rmTile(r);
    // tiles->setGarbage(h);
    // for(int i = 0; i < 4; i++){
    //     for(int j = 0; j < 14; j++){
    //         // std::cout << tiles->getAmount() << std::endl;
    //         if(i == 0){
    //             std::uniform_int_distribution<> tileSet (0, tiles->getTileSetAmount() - 1);
    //             r = tileSet(rng);
    //             h = tiles->getTile(r);
    //             tiles->rmTile(r);
    //             East->setHand(h);
    //         }else if(i == 1){
    //             std::uniform_int_distribution<> tileSet (0, tiles->getTileSetAmount() - 1);
    //             r = tileSet(rng);
    //             h = tiles->getTile(r);
    //             tiles->rmTile(r);
    //             North->setHand(h);
    //         }else if(i == 2){
    //             std::uniform_int_distribution<> tileSet (0, tiles->getTileSetAmount() - 1);
    //             r = tileSet(rng);
    //             h = tiles->getTile(r);
    //             tiles->rmTile(r);
    //             West->setHand(h);
    //         }else if(i == 3){
    //             std::uniform_int_distribution<> tileSet (0, tiles->getTileSetAmount() - 1);
    //             r = tileSet(rng);
    //             h = tiles->getTile(r);
    //             tiles->rmTile(r);
    //             South->setHand(h);
    //         }
    //     }
    // }
}

bool Mahjong::checkBonuses(int t){
    // checks if the tile is a bonus
    if(t >= 137 && t < 145){
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