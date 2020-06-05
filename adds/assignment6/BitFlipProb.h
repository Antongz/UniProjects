//ADDS assignment6
//bitflipprob class inheit form mutator
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

class BitFlipProb: public Mutator
{
public:
BitFlipProb();
   Individual* mutate(Individual* ind,int k);
    double p;
};
#endif


