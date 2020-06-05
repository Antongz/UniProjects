//ADDS assignment5
//ADDS filter Odd function
/*a1711972
 Yongxin Hu
 PRAC5
 */
#include <iostream>
#include <vector>

#include "FilterGeneric.h"
#include "FilterOdd.h"

using namespace std;

bool FilterOdd::g(int i)
{
    return (i%2 != 0);//i%2 not =0 is ture
}
