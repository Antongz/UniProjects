/*prac8
 a1711972
 Yongxin HU
 */
//child sorting function-qucicksort

#include <vector>
#include <iostream>
#include"QuickSort.h"

using namespace std;

QuickSort::QuickSort()
{
    
}
//virtual function for quicksorting
void QuickSort::Sorting(std::vector<int> &qs,int first, int last)
{
    int i, j, mid, piv;
    i = first;
    j = last;
    mid = first + (last - first) / 2;//midele number
   
       piv=qs.at(mid);//pivot
    
    while (i<last || j>first) 
    {
        while (qs.at(i) < piv)
            i++;
        while (qs.at(j) > piv)
            j--;
        
        if (i <= j) 
        {
           int temp = qs.at(i);
            qs.at(i)= qs.at(j);
            qs.at(j) = temp;
            i++;
            j--;
        }
        else 
        {
            if (i < last)
                Sorting(qs, i, last);//recusion function
            if (j > first)
                Sorting(qs, first, j);
            return;
        }
    }
    
}


