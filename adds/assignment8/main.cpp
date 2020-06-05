#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <string>

/*prac8
 a1711972
 Yongxin HU
 */
//main function

#include "Sort.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"
using namespace std;

int main()
{

    vector<int> vs;
    string line;
    getline(cin, line);
    istringstream iss(line);
    int i;
    
    while(iss >> i)
    {
    vs.push_back(i);
    }
   
   
    QuickSort qs;

    qs.Sorting(vs, 0, vs.size()-1);
   
    RecursiveBinarySearch bins;
    
   

    bins.binary_search(vs, 0, vs.size()-1, 0);
    
    bool check =false;

     for(int i = 0; i < vs.size(); i++)
    {
        if(vs.at(i)==1)
        {
         check=true;
        }
    }
    
if(check)
{cout<<"true"<<" ";}
else
{cout<<"false"<<" ";}
    
 

    for(int i = 0; i < vs.size(); i++)
    {
        cout << vs.at(i)<<" ";
    }

}
