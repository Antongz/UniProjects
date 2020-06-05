//ADDS assignment6
//bitflip class inheit form mutator
/*a1711972
 Yongxin Hu
 PRAC6
 */

#ifndef BITFLIPS_H
#define BITFLIPS_H
#include<cstring>
#include<iostream>
#include<sstream>
#include"Individual.h"
#include"Mutator.h"

class BitFlip: public Mutator
{
    
public:
    BitFlip();
     Individual* mutate(Individual* ind,int k);
    
    
};
#endif




