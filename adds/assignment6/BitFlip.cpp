#include<iostream>
#include<cstring>
#include<sstream>
#include"BitFlip.h"
#include"Mutator.h"
#include"Individual.h"
using namespace std;

BitFlip::BitFlip()
{
    
}
Individual* BitFlip::mutate(Individual* ind,int k)
{
    int len = ind->binaryString.length();
    if( k<=len)
    {
        ind->flipBit(k);
    }
    else
    {
        int k1 = k % (len + 1) + 1;
        ind ->flipBit(k1);
    }
    return ind;
}
