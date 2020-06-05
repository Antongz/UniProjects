#ifndef TOOLBOX_H
#define TOOLBOX_H
#include <string>
#include "Player.h"

class Toolbox : public Player {
public:
    Toolbox();
    std::string getMove();
    ~Toolbox();
    
private:
    std::string TMove;
    
};

#endif
