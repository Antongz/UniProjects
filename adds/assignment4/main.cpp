#include<iostream>
#include<string>
#include"Reverse.h"
#include"Fibonacci.h"
#include"EfficientFibonacci.h"

using namespace std;

int main(int argc, char* argv[])
{
    int i;
    static int n1;
    static int n2; //i is the number need to reverse ,n1, n2 is the number for fibonacci
    
    string s;// s is string varible for reverse
    
    cin >> i;

   
    //reverse digit
    int p;
    
    Reverse *r =new Reverse();
    p = r->ReverseDigit(i);
    

//error handle
    if(p == -1){
        cout<<"ERROR"<<" ";}
    else{
        cout << p<<" ";
    }
    
    //reverse string
     cin >>s;
    
    cout<< r->ReverseString(s)<<" ";
   //fibonacci
    
    cin >>n1;
    
  //  cin.clear();
   
    int w;
  

    if(cin.fail()==1)
    {   cout<<"ERROR"<<" ";
        cin.clear();
        cin.ignore();
      
    }
    
    
    
    

    Fibonacci *f = new Fibonacci();
    w = f->CalFibonacci(n1);
 

    
    if(n1 >=0){
        
        cout<< w <<" ";
       
    }
    
    else {
       
        cout<<"ERROR"<<" ";
       
        // exit(0);
      //  cin.ignore();
        
        
    }
    //efficientfiboacci
   // cin.clear();

    
     //cin >> n2;
    
  //  while(cin.get() !='\n')
    //{
      //  cin>>n2;
    //}
 
   // cin>>n2;
     EfficientFibonacci *ef = new EfficientFibonacci();
    int g;
    
    g= ef->CalEffFibonacci(n2,0,1);
    while(cin.get() !='\n')
    {
        cin>>n2;
        if(cin.fail()==1)
        {   cout<<"ERROR"<<" ";
            return -1;
        }else{return n2;}
        if (n2 >= 0) {
            
            cout<< g<< endl;
            
        }
        
    }
       
    }
   


    


