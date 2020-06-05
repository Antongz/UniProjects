//ADDS assignment5
//ADDS reduce base function
/*a1711972
 Yongxin Hu
 PRAC5
 */
#include <iostream>
#include <vector>

#include "ReduceGeneric.h"

using namespace std;


int ReduceGeneric::reduce(vector<int> v)
{
    
    
    recusionreduce(v,v.size()-1);
    return reducev;
}


void ReduceGeneric::recusionreduce(vector<int> v, int i)
{
    if(i == 0)
    {
       
        reducev = binaryOperator(v[1],v[0]);
        return;
    }
    
    v[i-1] = binaryOperator(v[i],v[i-1]);
    return recusionreduce(v,i-1);
}
