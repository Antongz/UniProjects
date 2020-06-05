#ifndef _HUMAN_H
#define _HUMAN_H

#include "referee.h"

#include <string>
#include <iostream>
#include <cstdlib>

class Human
{   
    friend class Referee;
    public:
        Human();
        
        void setHMove();
        std::string getHMove();

        void setNumGames();
        int getNumGames();

  
        std::string hMove;
        int numGames;
};

#endif
