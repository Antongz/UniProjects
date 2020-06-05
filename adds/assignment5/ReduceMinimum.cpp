//ADDS assignment5
//ADDS reduce minimum function
/*a1711972
 Yongxin Hu
 PRAC5
 */

#include <iostream>
#include <vector>
using namespace std;

#include "ReduceGeneric.h"
#include "ReduceMinimum.h"


int ReduceMinimum::binaryOperator(int i, int j)
{
    if(i<j)
    {
    return i;//i is min
    }
    else{
        return j;//j is min
    }
}
