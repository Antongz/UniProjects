#include<iostream>
#include<string.h>
#include<cctype>


class Palindrome{
public:
    int len;
    std::string newstr; 
    Palindrome();

    std::string remove(std::string s);
    std::string change(std::string s);
    std::string isPalindrome(std::string s);
};
