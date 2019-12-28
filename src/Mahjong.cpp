#include <Mahjong.h>

Mahjong::Mahjong(){
	// std::cout << "Setting up a game of Mahjong..." << std::endl;
    tiles = new MahjongTiles(numTiles);
    East = new Player("East");
    North = new Player("North");
    West = new Player("West");
    South = new Player("South");
    state = {"East's Turn","South's Turn","West's Turn","North's Turn","Mahjong!"};
    shuffleTiles();
}


//================================================================================================================================

void Mahjong::reset(){
    // std::cout << "Resetting Game..." << std::endl;
    delete East;
    delete South;
    delete West;
    delete North;
    delete tiles;
    tiles = new MahjongTiles(numTiles);
    East = new Player("East");
    North = new Player("North");
    West = new Player("West");
    South = new Player("South");
    shuffleTiles();
}

void Mahjong::handle(int x,int y, MouseButton click){
    if(tiles->getAmount() > 0 && click == left){    
        std::mt19937 rng (std::random_device{}());
        std::uniform_int_distribution<> tileSet (0, tiles->getAmount() - 1);
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

void Mahjong::shuffleTiles(){
    // Random # generator
    std::mt19937 rng (std::random_device{}());
    int r,h;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 14; j++){
            // std::cout << tiles->getAmount() << std::endl;
            if(i == 0){
                std::uniform_int_distribution<> tileSet (0, tiles->getAmount() - 1);
                r = tileSet(rng);
                h = tiles->getTile(r);
                tiles->rmTile(r);
                East->setHand(h);
            }else if(i == 1){
                std::uniform_int_distribution<> tileSet (0, tiles->getAmount() - 1);
                r = tileSet(rng);
                h = tiles->getTile(r);
                tiles->rmTile(r);
                North->setHand(h);
            }else if(i == 2){
                std::uniform_int_distribution<> tileSet (0, tiles->getAmount() - 1);
                r = tileSet(rng);
                h = tiles->getTile(r);
                tiles->rmTile(r);
                West->setHand(h);
            }else if(i == 3){
                std::uniform_int_distribution<> tileSet (0, tiles->getAmount() - 1);
                r = tileSet(rng);
                h = tiles->getTile(r);
                tiles->rmTile(r);
                South->setHand(h);
            }
        }
    }
    // each player should have 13 tiles with starting player with 14 to throw away 1
    std::uniform_int_distribution<> tileSet (0, tiles->getAmount() - 1);
    r = tileSet(rng);
    h = tiles->getTile(r);
    tiles->rmTile(r);
    tiles->setGarbage(h);
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
    delete East;
    delete South;
    delete West;
    delete North;
    delete tiles;
    // std::cout << "Stopping Mahjong..." << std::endl;
}