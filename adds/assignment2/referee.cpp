//Course: ADDS
//Weekly assignment2-Rock,Paper,Scissors
//Author:Samantha(yongxin HU)
//Student Id:1711972
//Description: Abstrace referee class

/*
 Design:
 * compare the computer and human and show result
 *
 
 */

#include "referee.h"
#include "human.h"
using namespace std;
#include <cstdlib>
#include <cstdio>


using namespace std;

Referee::Referee(int gamesNeededFor)
{
    numGames = gamesNeededFor;
}

void Referee::play(std::string moven)
{
    for (int i = 2; i < (2 * numGames + 1); i+=2)
    {
        if (moven.at(i) == 'R')
        {
            output.at(i) = 'T';
            output.at(i+1) = ' ';
        }

        if (moven.at(i) == 'P')
        {
            output.at(i) = 'W';
            output.at(i+1) = ' ';
        }

        if (moven.at(i) == 'S')
        {
            output.at(i) = 'L';
            output.at(i+1) = ' ';
        }

    }
} 

void Referee::results()
{
    for (int i = 0; i < (2 * numGames - 1); i++)
    {
        cout << output.at(i);
    }
}
