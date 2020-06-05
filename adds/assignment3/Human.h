//Course: ADDS
//Weekly assignment3-Rock,Paper,Scissors
//Author:Samantha(yongxin HU)
//Student Id:1711972
//Description: Abstrace human player class

/*
 Design:
 * child class from player
 * getmove() is the player's activity
 */
#ifndef Human_H
#define Human_H
#include <string>
#include "Player.h"
#include <vector>


class Human : public Player {
public:
    Human();
    std::string getMove();
    ~Human();
   
};

#endif
