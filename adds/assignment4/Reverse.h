//Course:ADDS
//Weekly:assignment4-recursion
//Author:sam(yongxin hu)
//student :1711972
//description:abstract reverse base class

/*
 reverseDigit is the function for reverse numbers , v is integer variable for the input of number
 reverseString is the function for reverse string , 
 */
#ifndef REVERSE_H
#define REVERSE_H
#include <iostream>
#include <string>

class Reverse {
public:
    Reverse();
    int ReverseDigit(int v);
    std::string ReverseString(std::string s);
    ~Reverse();
    
};

#endif
