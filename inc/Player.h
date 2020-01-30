#ifndef PLAYER_H
#define PLAYER_H

#include <server.h>
#include <vector>

class Player{
    int numHand;
    bool turn;
    std::string player;
    std::vector<int> hand;
    std::vector<int> reveal;
    Player();   
public:
    Player(std::string);

    void resetPlayer();
    void sortHand(); //
    void throwTile(int); //
    
    std::string getPlayer();
    int getHand(int); //
    int getNumHand(); //
    bool getTurn(); //
    std::vector<int> getReveal(); //
    std::vector<int> getHand(); //

    void setReveal(int); //
    void setHand(int); //
    void setTurn(); //

    ~Player();
};

#endif