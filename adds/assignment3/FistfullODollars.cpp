
#include <string>
#include <iostream>
#include "Player.h"
#include "FistfullODollars.h"

using namespace std;

FistfullODollars::FistfullODollars() : Player("FistfullODollars") {
    Times = 0;
}

FistfullODollars::~FistfullODollars() {}

void FistfullODollars::getTimes(int newTimes)
{
    Times = newTimes;
}


string FistfullODollars::getMove()
{
    if (Times == 0)
    {
        return "Rock";
    }
    else if (Times == 1)
    {
        return "Paper";
    }
    else if (Times == 2)
    {
        return "Paper";
    }
    return 0; 
}

