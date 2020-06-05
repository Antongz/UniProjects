
#include <string>
#include <iostream>
#include "Player.h"
#include "Crescendo.h"

using namespace std;

Crescendo::Crescendo() : Player("Crescendo") {
    Times = 0;
}

Crescendo::~Crescendo() {}

void Crescendo::getTimes(int newtimes)
{
    Times= newtimes;
}

string Crescendo::getMove()
{
    if (Times == 0)
    {
        return "Paper";
    }
    else if (Times == 1)
    {
        return "Scissors";
    }
    else if (Times == 2)
    {
        return "Rock";
    }
    return 0; 
}

