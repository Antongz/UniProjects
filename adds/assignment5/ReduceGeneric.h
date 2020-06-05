//ADDS assignment5
//ADDS reduce base function
/*a1711972
 Yongxin Hu
 PRAC5
 */
#ifndef REDUCEGENERIC_H
#define REDUCEGENERIC_H
#include <vector>

class ReduceGeneric
{
    
public:
    int reduce(std::vector<int>);
    void recusionreduce(std::vector<int>,int);
    int reducev;
    
private:
    virtual int binaryOperator(int,int)=0;
    
};
#endif
