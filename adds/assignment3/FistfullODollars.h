
#ifndef FistfullODollars_H
#define FistfullODollars_H
#include <string>
#include "Player.h"

class FistfullODollars : public Player {
public:
    FistfullODollars();
    std::string getMove();
    void getTimes(int);
    ~FistfullODollars();
    
private:
    std::string FMove;
    int Times;
};

#endif
