// #include <iostream>
// using namespace std;
// int lps(string s,int start,int end)
// {
// 	if(start>end)
// 		return 0;
// 	if(start==end)
// 		return 1;
// 	int x=0;
// 	if(s[start]==s[end])
// 	{
// 		int remainingL=end-start-1;
// 		if(remainingL==lps(s,start+1,end-1))
// 		   x=2+remainingL;
// 	}
//      int y=lps(s,start,end-1);
//      int z=lps(s,start+1,end);
//      return max(x,max(y,z));
// }
// int main()
// {
// 	int t;
// 	cout<<"Enter number of test cases:";
// 	cin>>t;
// 	while(t--)
// 	{
// 		string s;
// 		cout<<"Enter a string:";
// 		cin>>s;
// 		cout<<lps(s,0,s.length())<<endl;
// 	}
// 	return 0;
// }
/* ----------------Top Down----------------------*/
#include <iostream>
#define MAX 100
using namespace std;
int lps(int dp[][MAX],string s,int start,int end)
{
	if(start>end)
		return 0;
	if(start==end)
		return 1;
	int x=0;
	if(dp[start][end]==-1)
	{
	if(s[start]==s[end])
	 {
		int remainingL=end-start-1;
		if(remainingL==lps(dp,s,start+1,end-1))
		   x=2+remainingL;
	 }
     int y=lps(dp,s,start,end-1);
     int z=lps(dp,s,start+1,end);
     dp[start][end]= max(x,max(y,z));
     }
     return dp[start][end];
}
int main()
{
	int t;
	cout<<"Enter number of test cases:";
	cin>>t;
	while(t--)
	{
		string s;
		cout<<"Enter a string:";
		cin>>s;
		int dp[s.length()][MAX];
         for(int i=0;i<s.length();i++)
         	for(int j=0;j<MAX;j++)
         		dp[i][j]=-1;
		cout<<lps(dp,s,0,s.length()-1)<<endl;
	}
	return 0;
}