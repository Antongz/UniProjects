
#include <string>
#include <iostream>
#include "Player.h"
#include "Bureaucrat.h"

using namespace std;

Bureaucrat::Bureaucrat() : Player("Bureaucrat") {}

Bureaucrat::~Bureaucrat() {}

string Bureaucrat::getMove()
{
    BMove = "Paper";
    return BMove;
}

