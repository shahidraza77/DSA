#include <iostream>
#include <string.h>
using namespace std;

int str_to_num(string str);
int main()
{
	string s;
	cin>>s;
	cout<<str_to_num(s);
	//s+='a';
	//int l=s.length();

	//cout<<s<<l;
	return 0;
}
int str_to_num(string str)
  {
  	int i=0,num=0;
  	 if(str[i]=='-')
  	 	i=1;
  	  while(str[i]!='\0')
  	  	   {
  	  	   	num=num*10+(str[i]-'0');
  	  	   	i++;
  	  	   }
  	  	   if(str[0]=='-')
  	  	   	return -num;
  	  	   else
  	  	   	return num;
  }