#include "Palindrome.h"
#include<iostream>
using namespace std;

int main()
{
    Palindrome p;
    string s;
    getline(cin,s);
    s=p.remove(s);//remove
    s=p.change(s);//change
    cout<<p.isPalindrome(s)<<endl;
}
