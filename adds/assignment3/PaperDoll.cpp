#include <string>
#include <iostream>
#include "Player.h"
#include "PaperDoll.h"

using namespace std;

PaperDoll::PaperDoll() : Player("PaperDoll") {
    times = 0;
}

PaperDoll::~PaperDoll() {}

void PaperDoll::getTimes(int newtimes)
{
    times = newtimes;
}


string PaperDoll::getMove()
{
    if (times == 0)
    {
        return "Paper";
    }
    else if (times == 1)
    {
        return "Scissors";
    }
    else if (times == 2)
    {
        return "Scissors";
    }
    return 0; 
}

