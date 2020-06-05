//Course: ADDS
//Weekly assignment3-Rock,Paper,Scissors
//Author:Samantha(yongxin HU)
//Student Id:1711972
//Description: Abstrace random computer player class

/*
 Design:
 * random computer player,has a constructor
 * vectors contain info about previous moves and the activity of move
 * move is the player's activity
 */
#ifndef RandomComputer_H
#define RandomComputer_H
#include <string>
#include "Player.h"
#include <vector>


class RandomComputer : public Player {
public:
    RandomComputer();
    std::string getMove();
    void getResult(std::string str);
    
    ~RandomComputer();
    
private:
    int comrandom;//Random Number for random
    std::vector<std::string> ranResult;//Result string
    
};

#endif
