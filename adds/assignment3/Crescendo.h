#ifndef Crescendo_H
#define Crescendo_H
#include <string>
#include "Player.h"

class Crescendo : public Player {
public:
    Crescendo();
    
    std::string getMove();
    void getTimes(int);
    ~Crescendo();
    
private:
    std::string CMove;
    int Times;
};

#endif
