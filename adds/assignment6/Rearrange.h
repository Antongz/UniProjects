//ADDS assignment6
//rearrange class inheit form mutator
/*a1711972
 Yongxin Hu
 PRAC6
 */

#ifndef REARRANGE_H
#define REARRANGE_H
#include<cstring>
#include<sstream>
#include<iostream>
#include"Individual.h"
#include"Mutator.h"

class Rearrange: public Mutator
{
public:
    Rearrange();
    Individual* mutate(Individual* ind,int k);
    
};
#endif

