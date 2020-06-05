//ADDS assignment5
//ADDS map base function
/*a1711972
 Yongxin Hu
 PRAC5
 */

#ifndef MAPGENERIC_H
#define MAPGENERIC_H
#include <vector>

class MapGeneric
{
    
public:
    std::vector<int> map(std::vector<int>);
    
    void recusionmap(std::vector<int>,int);
    
    std::vector<int> mapv;//store the value
    
private:
    virtual int f(int)=0;
    
};
#endif
