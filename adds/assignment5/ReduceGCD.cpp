//ADDS assignment5
//ADDS reduce GCD function
/*a1711972
 Yongxin Hu
 PRAC5
 */
#include <iostream>
#include <vector>
using namespace std;

#include "ReduceGeneric.h"
#include "ReduceGCD.h"


int ReduceGCD::binaryOperator(int i, int j)
{
    int r = i%j;
    if(r == 0)
    {
        return j;
    }
    return binaryOperator(j,r);
}

