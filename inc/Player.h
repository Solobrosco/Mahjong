#ifndef PLAYER_H
#define PLAYER_H

#include <server.h>
#include <vector>
#include <Mahjong.h>

class Player{
    std::vector<int> hand;
    bool turn;
    int numHand;
public:
    Player();
    Player(const Player&);

    bool getTurn();
    int getHand();
    void setHand(std::vector<int>);
    void setTurn(bool);

    ~Player();
};

#endif