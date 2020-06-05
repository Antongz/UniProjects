#include <string>
#include <iostream>
#include "Player.h"
#include "Avalanche.h"

/*
 Design:
 * child player class
 * only move Rock
 * move is the player's activity
 */
 
using namespace std;

Avalanche::Avalanche() : Player("Avalanche") {}

Avalanche::~Avalanche() {}

string Avalanche::getMove()
{
    Amove = "Rock"; 
    return Amove;
}
