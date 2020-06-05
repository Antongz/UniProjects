#include <iostream>
#include "EfficientFibonacci.h"
using namespace std;



EfficientFibonacci::EfficientFibonacci()
{
  
}
EfficientFibonacci::~EfficientFibonacci()
{

}

int EfficientFibonacci::CalEffFibonacci(int n, int a, int b)
{
    if( n == 0) return a;
    if(n == 1) return b;
    
    
    return CalEffFibonacci(n-1, b, a+b);
}


