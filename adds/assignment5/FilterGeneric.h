//ADDS assignment5
//ADDS filter base function
/*a1711972
 Yongxin Hu
 PRAC5
 */

#ifndef FILTERGENERIC_H
#define FILTERGENERIC_H
#include <vector>

class FilterGeneric
{
    
public:
    
    std::vector<int> filter(std::vector<int>);
    
    void recusionfilter(std::vector<int>,int);
    

    std::vector<int> filterv;
    
private:
    
    virtual bool g(int)=0;
    
};
#endif
