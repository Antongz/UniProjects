/*prac8
 a1711972
 Yongxin HU
 */
//recusive binary search function
#include <vector>
#include <iostream>
#include "RecursiveBinarySearch.h"

using namespace std;

RecursiveBinarySearch::RecursiveBinarySearch()
{
    
}

int   RecursiveBinarySearch::binary_search(vector<int> &bins, int start, int end, int key)
{
    if (start > end)//base 
        return -1;
    
    int mid = start + (end - start) / 2;
    
    if (bins.at(mid) > key)
        
        return binary_search(bins, start, mid - 1, key);
  
    else if (bins.at(mid) < key)
        
        return binary_search(bins, mid + 1, end, key);
    
    else
        
        return mid;
}

