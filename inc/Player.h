#ifndef PLAYER_H
#define PLAYER_H

#include <server.h>
#include <vector>

class Player{
    std::vector<int> hand;
    bool turn;
    const int numHand = 14;
    std::string player;
    Player();   
public:
    Player(std::string);
    Player(const Player&);

    void throwTile(int);
    int getHand(int);

    bool getTurn();
    std::vector<int> getHand();
    const int getnumHand();
    void setHand(int);
    void setTurn(bool);

    ~Player();
};

#endif