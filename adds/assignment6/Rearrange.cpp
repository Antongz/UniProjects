#include<iostream>
#include<cstring>
#include<sstream>
#include"Rearrange.h"
using namespace std;

Rearrange::Rearrange()
{
    
}

Individual* Rearrange::mutate(Individual* ind,int k)
{
    //get the length
    int len = ind->binaryString.length();
   
    string s1 ="";//store the string
    string s2 ="";//store the string
    if(k >len+1)//if overflow
    {
        k= k%(len+1)+1; //solve the overflow
    }
    for(int i=0;i<len;i++)
    {
        if(i<k-1)
        {
            s1 +=ind->binaryString[i];
        }else if(i<len)
        {
            s2 +=ind->binaryString[i];
        }
    }
    ind->binaryString =s2+s1;
    return ind;
}
