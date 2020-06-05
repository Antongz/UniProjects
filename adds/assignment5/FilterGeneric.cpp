//ADDS assignment5
//ADDS filter base function
/*a1711972
 Yongxin Hu
 PRAC5
 */
#include <iostream>
#include <vector>
#include "FilterGeneric.h"

using namespace std;


vector<int> FilterGeneric::filter(vector<int> v)
{
    
    recusionfilter(v,v.size()-1);
    return filterv;
}


void FilterGeneric::recusionfilter(vector<int> v, int i)
{
    if(i == 0)
    {
        if(g(v[i]))
            filterv.push_back(v[i]);
        return;
    }
    
    if(g(v[i]))
        filterv.push_back(v[i]);
    
    return recusionfilter(v,i-1);
}
