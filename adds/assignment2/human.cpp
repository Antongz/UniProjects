//Course: ADDS
//Weekly assignment2-Rock,Paper,Scissors
//Author:Samantha(yongxin HU)
//Student Id:1711972
//Description: Abstrace human  player class

/*
 Design:
 * computer player identify the user's input with game times and moves
 *
 
 */
#include "human.h"
using namespace std;

Human::Human()
{
}

void Human::setHMove()
{
    string str;
    getline(cin, str);
    hMove = str;
}

string Human::getHMove()
{
    cout << hMove << endl;
    return hMove;
}

void Human::setNumGames()
{
  int tempNumGames;
    numGames = tempNumGames;
}

int Human::getNumGames()
{  if(hMove.at(0)=='1'){
    numGames=1;
  }
    cout << numGames << endl;
    return numGames;
}
