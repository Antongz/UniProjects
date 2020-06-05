#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include "Player.h"
#include "Referee.h"
#include "RandomComputer.h"
using namespace std;
Referee::Referee() {
}

Referee::~Referee() {
}

string Referee::playGame(Player *p1, Player *p2)
{
    string p1move, p2move, winner;
    bool is_val;
    
    p1move = p1->getMove();
    p2move = p2->getMove();
    
    
    if(p1->getName() == "RandomComputer")
    {
        p1->getResult(p2move);
    }
    
    if(p2->getName() == "RandomComputer")
    {
        p2->getResult(p1move);
    }
    
    is_val = is_Valid(p1move);
    if(!is_val)
    {
        return "stop";
    }
    
    is_val = is_Valid(p2move);
    if(!is_val)
    {
        return "stop";
    }
    
    winner = is_Win(p1move, p2move);
    return winner;
    
}


bool Referee::is_Valid(string Moves)
{
    if ((Moves=="Scissors") or (Moves=="Rock") or (Moves=="Paper"))
    {
        return 1;
    }
    return 0;
}

string Referee::is_Win(string p1move, string p2move)
{
    
    
    if(p1move == "Rock")
    {
        if( p2move == "Paper" )
        {
            return "p2";
        }
        else if(p2move == "Rock")
        {
            return "change";
        }
        else if(p2move == "Scissors")
        {
            return "p1";
        }
    }
    else if(p1move == "Paper")
    {
        if( p2move == "Paper" )
        {
            return "change";
        }
        else if(p2move == "Rock")
        {
            return "p1";
        }
        else if(p2move == "Scissors")
        {
            return "p2";
        }
    }
    else if(p1move == "Scissors")
    {
        if( p2move == "Paper" )
        {
            return "p1";
        }
        else if(p2move == "Rock")
        {
            return "p2";
        }
        else if(p2move == "Scissors")
        {
            return "change";
        }
    }
    return 0;
    
}

