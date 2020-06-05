
#ifndef PaperDoll_H
#define PaperDoll_H
#include <string>
#include "Player.h"

class PaperDoll : public Player {
public:
    PaperDoll();
    std::string getMove();
    void getTimes(int);
    ~PaperDoll();
    
private:
    std::string PMove;
    int times;
};

#endif

