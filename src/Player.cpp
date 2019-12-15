#include <Player.h>

Player::Player(){
    std::cout << "Creating Player..." << std::endl;
    turn = false;
    numHand = 13;
    for(int i = 0; i < numHand; i++){
        hand.push_back(0);
        std::cout << hand[i] << " ";
    }
}
void Player::setHand(std::vector<int> h){
    
}

Player::~Player(){
    std::cout << "Destroying Player..." << std::endl;
}