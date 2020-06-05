//ADDS assignment5
//ADDS filter non positive function
/*a1711972
 Yongxin Hu
 PRAC5
 */
#include <iostream>
#include <vector>

#include "FilterGeneric.h"
#include "FilterNonPositive.h"
using namespace std;

bool FilterNonPositive::g(int i)
{
    return (i < 0);
}
