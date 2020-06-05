
#ifndef _REFEREE_H
#define _REFEREE_H

#include <string>
#include <iostream>

class Referee
{   
    public:
        Referee(int gamesNeededFor);
        std::string moven;
        int getNumGames();
        void setNumGames();

        void play(std::string moven);
        void results();

    //private:
        int numGames;
          
        std::string winner;
        std::string output;

};

#endif
