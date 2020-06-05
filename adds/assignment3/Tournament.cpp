//Course: ADDS
//Weekly assignment3-Rock,Paper,Scissors
//Author:Samantha(yongxin HU)
//Student Id:1711972
//Description: Abstrace tournament class

/*
 Design:
 * creat tournament 
 * against is the activity for play game
 */
#include <string>
#include <vector>
#include <iostream>
#include "Player.h"
#include "Tournament.h"

#include "Referee.h"

using namespace std;

Tournament::Tournament() {
}

Tournament::~Tournament() {
}

string Tournament::against() {
    
    
    int i =0;//variable for round player
    int j;//game times
    unsigned int k;//half member times
    string fight_winner;//store winner
    int p1wins = 0;//p1 player win time
    int p2wins = 0;//p2 player win time
    Referee newRef;//create ref for new game
    
    for(k=0; k<Round1.size()/2; k++)//half member =the amount of play game
    {
        for(j = 0; j < 5; j++)
        {
	  fight_winner = newRef.playGame(Round1.at(i), Round1.at(i+1));//creat game to play
            if(fight_winner == "p1")
            {
                p1wins++;
            }
            else if(fight_winner == "p2")
            {
                p2wins++;
            }
        }
        
        //round2
        if(p1wins > p2wins)
        {
            Round2.push_back(Round1.at(i));
        }
        else if(p2wins > p1wins)
        {
            Round2.push_back(Round1.at(i+1));
        }
        else if(p2wins == p1wins)
        {
            Round2.push_back(Round1.at(i));
        }
        
        p1wins = 0;
        p2wins = 0;
        i+=2;
        
    }
    
    i = 0;
    
   
    for(k=0; k<Round2.size(); k++)
    {
        Round2.at(k)->getTimes(0);
    }
    //
    
    for(k=0;k<Round2.size()/2;k++)
    {
        for(j = 0; j < 5; j++)
        {
            fight_winner = newRef.playGame(Round2.at(i), Round2.at(i+1));
            if(fight_winner == "p1")
            {
                p1wins++;
            }
            else if(fight_winner == "p2")
            {
                p2wins++;
            }
        }
        
	//round3
        if(p1wins > p2wins)
        {
            Round3.push_back(Round2.at(i));
        }
        else if(p2wins > p1wins)
        {
            Round3.push_back(Round2.at(i+1));
        }
        else if(p2wins == p1wins)
        {
            Round3.push_back(Round2.at(i));
            
        }
        
       
        i+=2;
        p1wins = 0;
        p2wins = 0;
        
    }
    
   
    for(k=0; k<Round3.size(); k++)
    {
        Round3.at(k)->getTimes(0);
    }
    
    for(j = 0; j < 5; j++)
    {
        fight_winner = newRef.playGame(Round3.at(0), Round3.at(1));
        if(fight_winner == "p1")
        {
            p1wins++;
        }
        else if(fight_winner == "p2")
        {
            p2wins++;
        }
    }
    
    
    if(p1wins > p2wins)
    {
        return Round3.at(0)->getName();
        
    }
    else if(p2wins > p1wins)
    {
        return Round3.at(1)->getName();
    }
    else if(p2wins == p1wins)
    {
        return Round3.at(0)->getName();
    }
    
    return "NO WINNER";
    
}

void Tournament::addPlayers(Player* newPlayer)
{
  Round1.push_back(newPlayer);//push back the new player to round1
}


