/*prac8
 a1711972
 Yongxin HU
 */
//child sorting class-bubble sort
#include <vector>
#include <iostream>
#include "BubbleSort.h"

using namespace std;

BubbleSort::BubbleSort()
{
    
}

void BubbleSort::Sorting(vector<int> &bs)
{
    bool sp = true;//check swaped or not
    while(sp)
    {
        sp = false;
        for (int i = 0; i < bs.size()-1; i++)
            {
            if (bs.at(i)>bs.at(i+1))
            {
                bs.at(i) += bs.at(i+1);
                bs.at(i+1) = bs.at(i) - bs.at(i+1);
                bs.at(i) -=bs.at(i+1);
                sp = true;
            }
        }
    }
        
}





