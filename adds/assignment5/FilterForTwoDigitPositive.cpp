//ADDS assignment5
//ADDS filter for 2 digit  function
/*a1711972
 Yongxin Hu
 PRAC5
 */
#include <iostream>
#include <vector>

#include "FilterGeneric.h"
#include "FilterForTwoDigitPositive.h"
using namespace std;

bool FilterForTwoDigitPositive::g(int i)
{//choose 2 digit
    if(i > 0)
    {
        if((i/10)!=0)
        {
            if(((i/10)/10)== 0)
                return true;
        }
    }
    return false;
}
