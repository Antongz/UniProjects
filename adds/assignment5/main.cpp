//ADDS assignment5
//ADDS main function
/*a1711972
  Yongxin Hu
 PRAC5
 */

//maps
#include "MapGeneric.h"
#include "MapTriple.h"
#include "MapAbsoluteValue.h"
#include "MapSquare.h"
#include <algorithm>
//filters
#include "FilterGeneric.h"
#include "FilterOdd.h"
#include "FilterNonPositive.h"
#include "FilterForTwoDigitPositive.h"
//reduce
#include "ReduceGeneric.h"
#include "ReduceMinimum.h"
#include "ReduceGCD.h"

#include <iostream>
#include <vector>
#include <sstream>


using namespace std;


int main()
{
    vector<int> L,L1,L2;
    int i;//vector list number
    string line;
    string input;
    getline(cin,input);//input 20 int
    line.reserve(input.size()); // optional, avoids buffer reallocations in the loop
    for(size_t i = 0; i < input.size(); ++i)
    if(input[i] != ',') line += input[i];//delete the ,
    istringstream l(line);//Input operations for performing C++ style string streams
    
   
    while(l>>i)
    {
        L.push_back(i);
    }
   //if the input or the vector is not 20 ,it will be 0
    if(L.size() != 20||input.size() == 0)
        return 0;
    
    //triple and absolute
    MapTriple triple;   MapAbsoluteValue abs;
    L1 = triple.map(abs.map(L));
    
   //positive to Odd
    FilterOdd Odd; FilterForTwoDigitPositive p2;
    
    L2 = p2.filter(L1);
    if(L2.size() <2)
        return 0;
    
    L2 = Odd.filter(L2);
    if(L2.size() <2)
        return 0;
    
   //Gcd min value
    ReduceMinimum min; ReduceGCD gcd;

    cout<<min.reduce(L2)<<" "<<gcd.reduce(L2)<<endl;
}
