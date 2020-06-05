#ifndef _COMPUTER_H
#define _COMPUTER_H

#include "referee.h"

#include <string>
#include <iostream>

class Computer
{   
    friend class Referee;
    public:
        Computer(int games);

        std::string getCMove();

 
        std::string cMove;
};

#endif
