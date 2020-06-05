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
#include "RandomComputer.h"
#include "Player.h"
#include <string>
#include <cstdlib>
using namespace std;


RandomComputer::RandomComputer() : Player("RandomComputer"){
    
}

RandomComputer::~RandomComputer(){
}


void RandomComputer::getResult(string str)
{
   ranResult.push_back(str);
}

string RandomComputer::getMove()
{
    if(ranResult.size() > 0)
    {
        if(ranResult.back() == "Rock")
        {
            return "Rock";
        }
        else if(ranResult.back() == "Paper")
        {
            return "Paper";
        }
        else if(ranResult.back() == "Scissors")
        {
            return "Scissors";
        }
        
    }
    else
    {
        int comrandom = rand() % 3;
        
        if (comrandom == 0)
        {
            return "Rock";
        }
        else if(comrandom == 1)
        {
            return "Paper";
        }
        else if(comrandom == 2)
        {
            return "Scissors";
        }
    }
    
    return 0;
}


