#include<iostream>
#include "Fibonacci.h"

using namespace std;

Fibonacci::Fibonacci()
{
  
}
Fibonacci::~Fibonacci()
{
    
}

int Fibonacci::CalFibonacci(int n)
{
 if(n == 0)
 {
     return 0;
 }
 if(n == 1 || n == 2)
 {
     return 1;
 }
 else{
    return (CalFibonacci(n-1) + CalFibonacci(n-2));
 }
}

