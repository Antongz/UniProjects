#include "LinkList.h"
#include<iostream>


using namespace std;

int main()
{
    LinkList l;
    string s;
    int num;
    int pos;
    while(1)
    {
        cin>>s;
        //inout is number
        if(s[0] >='0'&&s[0]<='9')
        {
            l.addEnd(atoi(s.c_str()));
        }
                     else//input is the string
                     {
                         int n1,n2;
                         cin>>n1>>n2;
                         
                         if(s=="AF")
                         {
                             l.addFront(n1);
                         }else if(s=="AP")
                         {
                             l.addEnd(n1);
                         }else if(s=="S")
                         {
                             l.search(n1);
                         }else if(s=="DF")
                         {
                             l.deleteFront();
                         }else if(s=="DE")
                         {
                             l.deleteEnd();
                         }else if(s=="DP")
                         {
                             l.deletePosition(n1);
                         }else if(s=="GI")
                         {
                             l.getItem(n1);
                         }
                     }
       }
 }
