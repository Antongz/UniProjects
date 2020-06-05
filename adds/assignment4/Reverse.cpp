#include<iostream>
#include<string>
#include "Reverse.h"

using namespace std;

Reverse::Reverse()
{

}
Reverse::~Reverse()
{
    
}

int Reverse::ReverseDigit(int v)
{
    static int mul=1;//multiple
    static int newDigit=0;//ReverseDigit
    if(v < 0){
        return -1;
    }
    if(v > 0){
        ReverseDigit(v/10);
        newDigit = (v%10)* mul + newDigit;
        mul = mul * 10;
    }
    return newDigit;
}

std::string Reverse::ReverseString(std::string s)
{
    int num = s.size();
    if(num == 1)
        return s;
    else
        cout<<s[num -1];
        return ReverseString(s.substr(0,num -1));
    
    
}

