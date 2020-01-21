#ifndef PLAYER_H
#define PLAYER_H

#include <server.h>
#include <vector>

class Player{
    bool turn;
    const int numHand = 16;
    std::string player;
    std::vector<int> hand;
    std::vector<int> reveal;
    Player();   
public:
    Player(std::string);
    Player(const Player&);

    void sortHand(); //
    void throwTile(int); //
    
    int getHand(int); //
    const int getnumHand(); //
    bool getTurn(); //
    std::vector<int> getReveal(); //
    std::vector<int> getHand(); //

    void setReveal(int); //
    void setHand(int); //
    void setTurn(); //

    ~Player();
};

#endif