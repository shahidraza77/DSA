#include<iostream>
#define MAX 1000
int dp[MAX];
using namespace std;
int fib(int n)
{
     dp[n];
    dp[0]=0;
    dp[1]=1;
        for(int i=2;i<=n;i++)
             dp[i]=dp[i-1]+dp[i-2];
           
           return dp[n];
        
        
}
int main()
{
    int n;
    cin>>n;
    //dp[n]={0};
    cout<<fib(n)<<endl;
    return 0;
}