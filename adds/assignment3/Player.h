//Course: ADDS
//Weekly assignment3-Rock,Paper,Scissors
//Author:Samantha(yongxin HU)
//Student Id:1711972
//Description: Abstrace base player class

/*
 Design:
 * base class
 * player name
 * move is the player's activity
 */
#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player {
public:
    Player();
    Player(std::string);
    std::string getName();
    virtual void getResult(std::string);
    virtual std::string getMove();
    virtual void getTimes(int);
    ~Player();
    
private:
    std::string name;
    
};

#endif
