#include<iostream>
#include<cstring>
#include<sstream>
#include"BitFlipProb.h"
#include"Mutator.h"
#include"Individual.h"
using namespace std;

BitFlipProb::BitFlipProb()
{
    p = rand()/( RAND_MAX +1.0);//random the (0,1)
    
}

Individual* BitFlipProb::mutate(Individual* ind,int k)
{
    int len = ind->binaryString.length();
    for(int i =0;i< len; i++)
    {
        double j=p;
        if(j<=p)
        {
            ind->flipBit(i+1);
        }
    }
    return ind;
}
