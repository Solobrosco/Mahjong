#include <Player.h>

Player::Player(std::string player){
    std::cout << "Creating Player of the " << player << std::endl;
    this->player = player;
    if(player == "East"){
        turn = true;
    }
    else{
        turn = false;
    }
    // for(int i = 0; i < numHand; i++){
    //     hand.push_back(0);
    //     // std::cout << hand[i] << " ";
    // }
}

// Copy Constructor
// Player::Player(const Player& other){
//     this->hand = other.hand;
//     this->turn = other.turn;
//     this->numHand = other.numHand;
// }

//================================================================================================================================

bool Player::getTurn(){
    return turn;
}

std::vector<int> Player::getHand(){
    return hand;
}

const int Player::getnumHand(){
    return numHand;
}

// Takes a vector of 13 ints and sets it to hand
void Player::setHand(int h){
    hand.push_back(h);
}

void Player::setTurn(bool t){
    this->turn = t; 
}

Player::~Player(){
    std::cout << "Destroyed Player of the " << player << std::endl;
}