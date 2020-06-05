//ADDS assignment6

/*a1711972
 Yongxin Hu
 PRAC6
 */

#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include<cstring>
#include<iostream>

class Individual
{
public:
    std::string binaryString;//store the value of genes
    
    std::string getString();//output the bnary string with bitstring list
    int getBit(int pos);//return the bit value at the pos
    void flipBit(int pos);//take the position and flip the value
    int getMaxOnes();//return the longest of '1' in consecutie in the list
    int getLength();//return the length of the list
    Individual(int len);//take the length and create a binary string
    Individual(std::string str);//copy for the new list
    Individual();
};
#endif

