//ADDS assignment6

/*a1711972
 Yongxin Hu
 PRAC6
 */

#ifndef MUTATOR_H
#define MUTATOR_H
#include<cstring>
#include<iostream>
#include"Individual.h"

class Mutator
{
    public:
    
    virtual Individual* mutate(Individual* ind,int k);
  
};
#endif


