#include<iostream>
#define MAX 1000
int dp[MAX];
using namespace std;
int fib(int n)
{
    if(n==1)
      return 0;
      else if(n==2)
        return 1;
        if(dp[n]==0)
           dp[n]=fib(n-1)+fib(n-2); /* code */
           return dp[n];
        
        
}
int main()
{
    int n;
    cin>>n;
    dp[n]={0};
    cout<<fib(n)<<endl;
    return 0;
}