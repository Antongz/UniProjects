//ADDS assignment6

/*a1711972
 Yongxin Hu
 PRAC6
 */

#include "Individual.h"
#include<cstring>
#include<iostream>
using namespace std;


//new string with every digit is 0
Individual::Individual(int len)
{
    binaryString = "";
    for(int i=0; i<len; i++)
    {
        binaryString +='0';
    }
}
//copy for string
Individual::Individual(string binaryString2)
{
    binaryString = binaryString2;
}

//return the string
string Individual::getString()
{
    return binaryString;
    
}
//return bit with position
int Individual::getBit(int pos)
{
     if(pos<binaryString.length() || pos>0 )
     {
         return int(binaryString[pos -1]);
     }
      return -1;
}
//flip
void Individual::flipBit(int pos)
{
    if(int(binaryString[pos -1])== 48)
    {
        binaryString[pos -1] ='0';
    }else if(int(binaryString[pos -1])== 49){
        binaryString[pos -1] ='1';
    }
}
//returns the longest consecutive sequence of ‘1’
int Individual::getMaxOnes()
{
    int maxcount=0;
    int count=0;
    for(int i=0;i<binaryString.length(); i++)
    {
        if(binaryString[i] =='1')
        {
            for(int j=i;j<binaryString.length(); j++)
            {
                if(binaryString[j]== '1')
                {
                    count++;
                }else
        {
            break;
        }
    }
            if(count >maxcount)
            {
               maxcount=count;
            }
   }
}
return maxcount;
}
int Individual::getLength()
{
    return binaryString.length();
}
