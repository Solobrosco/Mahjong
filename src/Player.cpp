#include <Player.h>

// Default Constructor
Player::Player(){
    std::cout << "Creating Player..." << std::endl;
    turn = false;
    numHand = 13;
    for(int i = 0; i < numHand; i++){
        hand.push_back(0);
        std::cout << hand[i] << " ";
    }
}

// Copy Constructor
Player::Player(const Player& other){
    this->hand = other.hand;
    this->turn = other.turn;
    this->numHand = other.numHand;
}

//================================================================================================================================

bool Player::getTurn(){
    return turn;
}

std::vector<int> Player::getHand(){
    return hand;
}



void Player::setHand(std::vector<int> h){
    
}

void Player::setTurn(bool t){

}

Player::~Player(){
    std::cout << "Destroying Player..." << std::endl;
}