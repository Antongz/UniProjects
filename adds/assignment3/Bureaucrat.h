
#ifndef Bureaucrat_H
#define Bureaucrat_H
#include <string>
#include "Player.h"

class Bureaucrat : public Player {
public:
    Bureaucrat();
    std::string getMove();
    ~Bureaucrat();
    
private:
    std::string BMove;
    
};

#endif
