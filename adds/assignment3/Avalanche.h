#ifndef Avalanche_H
#define Avalanche_H
#include "Player.h"
#include <string>

class Avalanche : public Player {
public:
    Avalanche();
    std::string getMove();
    ~Avalanche();
    
private:
    std::string Amove;
    
};

#endif
