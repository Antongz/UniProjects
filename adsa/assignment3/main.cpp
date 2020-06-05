
#include<iostream>
#include<string>
#include <vector>
#include <string.h>
#include <sstream>
#include <algorithm>
using namespace std;
#define HASHSIZE 26
#define SUCCESS 1
#define UNSUCCESS 2

int hashfunction(string s)
{
char key;
key=s[s.length()-1];
int dex;
dex = key - 'a';
return dex;
}

bool search(string s,vector<string>&ht)
{
   int current_size=0;
   int dex=hashfunction(s);
   for(dex;dex<HASHSIZE;dex++)
   {
   if(ht[dex]==s)
   {
   return false;
   }
   if(dex==25)
   {
   dex=0;
   }
   current_size++;
   if(current_size == HASHSIZE)
   {
   return true;
   }
   
   }
 
}

void insert(string s,vector<string> &ht)
{
   int current_size=0;
   int dex=hashfunction(s);
   for(dex;dex<HASHSIZE;dex++)
   {
   if(ht[dex]=="never used" || ht[dex]=="tombstone")
   {
   ht[dex]=s;
   break;
   }
   if(dex==25)
   {
     dex=-1;
   }
   current_size++;
   if(current_size==HASHSIZE);
   }
}

void Deleteing(string s,vector<string> &ht)
{
   int current_size=0;
   int dex=hashfunction(s);
   for(dex;dex<26;dex++)
   {
   if(ht[dex]==s)
   {
   ht[dex]="tombstone";
   break;
   }
   if(dex==25)
   {
   dex=0;
   }
   current_size++;
   if(current_size==HASHSIZE);
   }
}
void split(const string& src, const string& delim, vector<string>& dest)
{
    string str = src;
    string::size_type start = 0, index;
    string substr;
 
    index = str.find_first_of(delim, start);
    while(index != string::npos)
    {
        substr = str.substr(start, index-start);
        dest.push_back(substr);
        start = str.find_first_not_of(delim, index);
        if(start == string::npos) return;
 
        index = str.find_first_of(delim, start);
    }
    substr=str.substr(start,index-start); dest.push_back(substr);
}

void show(vector<string> &ht)
{
for(int i=0;i<HASHSIZE;i++)
{
if(ht[i]!="never used" && ht[i]!="tombstone")
{
cout<<ht[i]<<" ";
}
}
}
int main()
{
vector<string> ht;
for(int i=0;i<HASHSIZE;i++)
{
ht.push_back("never used");
}
      string line;
      getline(cin,line);
      string delim(" ");
      vector<string> results;
      split(line, delim, results);
     for(int i=0;i<results.size();i++)
    {
    
     string str_a="A";
     string str_d="D";
     string::size_type idx1 = results[i].find(str_a);
     string::size_type idx2 = results[i].find(str_d);
    
    
    
     if ( idx1 != string::npos )
     {
   
     results[i].erase(remove(results[i].begin(),results[i].end(),'A'),results[i].end());
     bool check=search(results[i],ht);
     if(check == true)
     {
      insert(results[i],ht);
    }
     }else if( idx2 != string::npos )
     {

     results[i].erase(remove(results[i].begin(),results[i].end(),'D'),results[i].end());
          bool check=search(results[i],ht);
      if(check==false)
      {
       Deleteing(results[i],ht);
       }
     }
    }
   show(ht);
   return 0;

}
