#ifndef REFEREE_H
#define REFEREE_H
#include <string>

#include "Player.h"

class Referee {
public:
    Referee();
    ~Referee();
    std::string getMove(std::string);
    std::string playGame(Player *p1, Player *p2);
    std::string is_Win(std::string, std::string);
    bool is_Valid(std::string);
    
};

#endif
