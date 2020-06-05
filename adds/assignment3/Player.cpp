//Course: ADDS
//Weekly assignment3-Rock,Paper,Scissors
//Author:Samantha(yongxin HU)
//Student Id:1711972
//Description: Abstrace base player class

/*
 Design:
 * base player class
 * player name is variable
 * move is the player's activity
 *special activity for c,p,f player
 */
#include <string>
#include <iostream>
#include "Player.h"

using namespace std;

Player::Player()
{
}

Player::Player(string name2)
{
    name = name2;
}

Player::~Player(){
}

string Player::getName()//for player against each others
{
    return name;
}

void Player::getTimes(int Times)//for crescendo,paperdoll,fistfullodollars players
{
    
}

void Player::getResult(string res)//for random computer player
{
    
}

string Player::getMove()// for player
{
    return "";
}

