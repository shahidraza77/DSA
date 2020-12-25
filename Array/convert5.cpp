#include <iostream>
using namespace std;
int convertFive(int n);
int main()
{
  int t,n;
  cin>>t;
  while(t--)
  {
    cin>>n;
    cout<<convertFive(n)<<endl;
  }
  return 0;
}
int convertFive(int n)
{
//Your code here
int count=0;
int a[6];
while(n>0)
{
    int digit=n%10;
    if(digit==0)
    {
      a[count]=5;
      count++;
    }
    else
    {
       a[count]=digit;
       count++; 
    }
    n=n/10;
}
int num=0;
count--;
for(int j=count;j>=0;j--)
     {
         num=num*10+a[j];
     }
     return num;
}