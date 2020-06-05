//ADDS assignment6
//main function
/*a1711972
 Yongxin Hu
 PRAC6
 */

#include"Individual.h"
#include"Mutator.h"
#include"BitFlip.h"
#include"BitFlipProb.h"
#include"Rearrange.h"

#include<cstring>
#include<iostream>
#include<sstream>

using namespace std;

Individual* execute(Individual* indPtr, Mutator* mPtr, int k)
{
    return mPtr->mutate(indPtr,k);
    
}

int main()

{
    
    string binarystr1,binarystr2;//individual
    int k1,k2;//position
    cin >> binarystr1 >> k1 >> binarystr2 >> k2;
    Individual* p1=new Individual(binarystr1);
    Individual* p2=new Individual(binarystr2);
    
    BitFlip* b1 = new BitFlip();
    
  //  Rearrange* r1 = new Rearrange();
    
    execute(p1,b1,k1);
    //execute(p2,r1,k2);
    
    cout<<p1->binaryString<<" ";
    cout<<p2->binaryString<<" ";
    cout<<p2->getMaxOnes()<<endl;
    
    
    
}
