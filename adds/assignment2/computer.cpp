//Course: ADDS
//Weekly assignment2-Rock,Paper,Scissors
//Author:Samantha(yongxin HU)
//Student Id:1711972
//Description: Abstrace computer player class

/*
 Design:
 * computer player just show R
 *
 
 */
#include "computer.h"
using namespace std;

Computer::Computer(int games)
{
    string move;
    move[0]='R';

    for (int i = 2; i < (2 * games); i+=2)
    {
        cMove.at(i) = 'R';
        cMove.at(i+1) = 'R';
    }

    cMove.at(0) = games;
    cout << games << endl;
}

string Computer::getCMove()
{
    cout << cMove << endl;
    return cMove;
}
