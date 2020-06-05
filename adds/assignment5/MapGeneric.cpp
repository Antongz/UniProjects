//ADDS assignment5
//ADDS main function
/*a1711972
 Yongxin Hu
 PRAC5
 */

#include <iostream>
#include <vector>

#include "MapGeneric.h"

using namespace std;


vector<int> MapGeneric::map(vector<int> v)
{

    recusionmap(v,v.size()-1);
    return mapv;
}

// recusion map function to return the result after map
void MapGeneric::recusionmap(vector<int> v, int i)
{
    if(i == 0)
    {
        mapv.push_back(f(v[i]));
        return;
    }
    mapv.push_back(f(v[i]));
    return recusionmap(v,i-1);
}
