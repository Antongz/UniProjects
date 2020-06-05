//Course: ADDS
//Weekly assignment3-Rock,Paper,Scissors
//Author:Samantha(yongxin HU)
//Student Id:1711972
//Description: Abstrace human player class

/*
 Design:
 * child class from player
 * HMove is variable to move by inputting by user
 * getmove is the player's activity
 */
#include <string>
#include <iostream>
#include "Player.h"
#include "Human.h"

using namespace std;

Human::Human() : Player() {}

Human::~Human() {}

string Human::getMove()
{
    string HMove;
    cin >> HMove;
    return HMove;
}
