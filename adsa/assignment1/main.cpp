#include<iostream>
#include<vector>
#include<math.h>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;

string  I1;// input Integer 1 as string
string I2;//Input  Integer 2 as string
vector<int> V1; // Integer 1 vector
vector<int> V2;//Integer 2 vector
vector<int> V3;//the copy of V1
vector<int> V4;//the copy of V2

//input the integer
void input_string(string &in)
{
    string s;
    cin>>s;

}
//to store the old vector
void copyvector(vector<int> &v1,vector<int> &v2)
{
    int v1_size = v1.size();
    for(int i =0;i<v1_size;i++)
    {
        v2.push_back(v1[i]);
    }
}
//integer to vector
void stringtoint(string &in,vector<int> &out)
{
    int i = in.size();
   
    char v[i-1];
    
    strcpy(v,in.c_str());
    for(int n=0;n<i;n++)
    {
        int intNum = (int)v[n] - 48;
        out.push_back(intNum);
        
    }

   

}

//school method add function
vector<int> School_Add(vector<int> &v1,vector<int> &v2,int B)
{

    int v1_size = v1.size();
    int v2_size = v2.size();
   //for the max sie 
    if(v1_size<v2_size) return School_Add(v2,v1,B);

    int carry,sum,len;
    
    vector<int> result;
    //carry for +1 / +0 
    carry = 0;
    //the length of v1 and v2 int string 
    len = v1_size - v2_size;

    for(int i=v1_size-1;i>=0;i--)
    {
        if(i-len >= 0)sum = v1[i]+v2[i-len]+carry;
        else sum=v1[i]+carry;
         result.push_back(sum%B);
         carry = sum/B;  
    }
    // for the last carry 
    if(carry > 0){
        result.push_back(carry);
    }
    //to reverse it for the right order
    reverse(result.begin(),result.end());
    //return result vector
    return result;
    
}

//school method sub function
vector<int> School_Sub(vector<int> &I1,vector<int> &I2,int B){
    int i1_size = I1.size();
    int i2_size = I2.size();
    if(i1_size<i2_size) 
    {
        return School_Sub(I2,I1,B);
    }
    int carry,sub,d;
    carry = 0;
// the length of the vector 
    d = i1_size - i2_size;
    for(int i=i1_size-1;i>=0;i--)
    {
      
        if(i-d >= 0) 
            sub= I1[i]-I2[i-d]+carry;
        else
            sub=I1[i]+carry;

        if(sub < 0 && i-d >=0)
        {
            carry = -1;
            I1[i] = B+sub;

        }

        else if(sub < 0 && i-d <0)
        {
  
           carry = -1;
           I1[i] = B+sub;          
        }
        else if (sub>=0 && i-d >=0)
        {
            carry =0;
            
            I1[i]=sub;

        }else if(sub>=0 && i-d < 0)
        {
             carry =0;
            
            I1[i]=sub;
        }
      
        
    }
 
    //to remove the highest '0'
    int rest0 = 0;
    for(int i=0;i<i1_size;i++)
    {
        if(I1[i] == 0) rest0++;
        else break;
    }
    for(int i=0;i<I1.size();i++)
    I1[i] = I1[i+rest0];

    for(int i=0;i<rest0;i++)
    I1.pop_back();
    

    //return the vector 
    return I1;
}

//school method mul function
vector<int> School_Multi(vector<int> &I1,vector<int> &I2,int B)
{

    if(I1.size()>I2.size()) 
        {
            return School_Multi(I2,I1,B);
        }
    
    vector<int> v(I1.size() + I2.size() +1);
    
    for(int i=0;i<I2.size();i++){
        for(int j=0;j<I1.size();j++){
            v[i+j] += I2[I2.size()-1-i] * I1[I1.size()-1-j];
        }
        
    }
    
    for(int i=0;i<v.size();i++){
        if(v[i]<0)
        {
            int b= (abs(v[i]) + B-1) /B;
            v[i+1] -= b;
            v[i] +=b*B;
        }else{
         v[i+1] += v[i] /B;
            v[i] %= B;
        }
    }
   // remove the 0 
   while(v.size() > 1&&v.back() == 0) v.pop_back();
    vector<int> mul_resultv(v.size());
    
    for(int i=0;i<v.size();i++){
        mul_resultv[i] = v[v.size()-1 - i];

    }
       return mul_resultv;
 
}

//karatsuba 
vector<int> Karatsuba(vector<int> &V3,vector<int> &V4,int B){
    int i1_size=V3.size();
    int i2_size =V4.size();
    int half = i1_size/2;
  if(i1_size <=2 ||i2_size <=2) 
    {
        return School_Multi(V3,V4,B);
    }
  if(i1_size < i2_size) 
    {
        return Karatsuba(V4,V3,B);
    }
    if(i1_size == 0 || i2_size == 0) 
   {
            return vector<int>();
    }
// spilt v1 to a and b
vector<int> a(V3.begin(),V3.end()-half);
vector<int> b(V3.end()-half,V3.end());
    
//spilt v2 to c and d 
vector<int> c(V4.begin(),V4.end()-min(half,i2_size));
vector<int> d(V4.end()-min(half,i2_size),V4.end());
  

//step 1 a*c
    vector<int> step1 = Karatsuba(a,c,B);

//step2 b*d
    vector<int> step2 = Karatsuba(b,d,B);
//step3.1 (a+b)
    
    vector<int> step3_1 = School_Add(a,b,B);
//step 3.2 (c+d)
    vector<int> step3_2=  School_Add(c,d,B);
//step 3(a+b)*(c+d)
    vector<int> step3 = Karatsuba(step3_1,step3_2,B);

 //step4.1 (step3-step2)
    vector<int> step4_1 = School_Sub(step3,step2,B);
  //step4 step4_1-step1
    vector<int> step4 = School_Sub(step4_1,step1,B);
   
//+0
        for(int i =0;i<half*2;i++)
        {
            step1.push_back(0);
    
        }
//step5 step1+step2
    vector<int> step5_1 = School_Add(step1,step2,B);
    //+0
    for(int i =0;i<half;i++)
    {
        step4.push_back(0);
        
    }
    //step5 step5.1+step4
        vector<int> step5 = School_Add(step5_1,step4,B);
    

    return step5;
}


int main(){

  
    int B; //base number
    cin>>I1>>I2>>B;
    stringtoint(I1,V1);
    stringtoint(I2,V2);
    //copy the vector
    copyvector(V1,V3);
    copyvector(V2,V4);


    vector<int> v ;
    int n=I1.size();
    int half = n/2;

   

//add result
    vector<int> add_result = School_Add(V1,V2,B);
    int num0= add_result.size();

    for(int i =0;i<=num0-1;i++)
    {
        cout<<add_result[i];
    }
    cout<<" ";
    

    vector<int> kara_result = Karatsuba(V3,V4,B);
    int num1 = kara_result.size();

      for(int i =0; i<=num1-1;i++)
    {
        cout<<kara_result[i];
    }
   
    cout<<" ";
    cout<<"0";
    return 0;
}
