#include"Palindrome.h"
using namespace std;
Palindrome::Palindrome()
{
	len=0;
	newstr="";
}

string Palindrome::remove(string s)
{
	int i=0;
	len=s.length();
	while(i<len)//use a while loop to move non-alpha characters
	{
		//to check if the disinct element is alpha
		if(!isalpha(s[i])|| s[i]==' ')
		{
			s.erase(i,1);//erase in c++
			len--;
		}
		else
			i++;//i add 1
	}
	return s;
}

string Palindrome::change(string s)
{
	len=s.length();
	for(int i=0;i<len;i++)
	{
		if('A'<=s[i] && s[i]<='Z')//the domain is upper case of alpha
		{
			s[i]=s[i]+32;     //change the upper case to lower case
		}
	}
	return s;
}

string Palindrome::isPalindrome(string s)
{
	len=s.length();
	for(int i=0;i<len;i++)        //use a for loop to create a new string
	{
		newstr+=s[len-i-1];	
	}
	if(newstr==s)
	{
		return "Yes";
	}
	else
	{
		return "No";
	}

}
