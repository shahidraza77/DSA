         /* ----------------D & C----------------------*/
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
// 		x=2+lps(s,start+1,end-1);
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
// /* ----------------Top Down----------------------*/
// #include <iostream>
// #define MAX 100
// using namespace std;
// int lps(int dp[][MAX],string s,int start,int end)
// {
// 	if(start>end)
// 		return 0;
// 	if(start==end)
// 		return 1;
// 	int x=0;
// 	if(dp[start][end]==-1)
// 	{
// 	if(s[start]==s[end])
// 		x=2+lps(dp,s,start+1,end-1);
//      int y=lps(dp,s,start,end-1);
//      int z=lps(dp,s,start+1,end);
//      dp[start][end]= max(x,max(y,z));
//      }
//      return dp[start][end];
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
// 		int dp[s.length()][MAX];
//          for(int i=0;i<s.length();i++)
//          	for(int j=0;j<MAX;j++)
//          		dp[i][j]=-1;
// 		cout<<lps(dp,s,0,s.length())<<endl;
// 	}
// 	return 0;
// }
/* ----------------Bottom up----------------------*/
#include <iostream>
using namespace std;
int lps(string s)
{
	int dp[s.length()][s.length()];
	for(int col=0;col<s.length();col++)
	{
		for(int row=s.length()-1;row>=0;row--)
		{
			if(row>col)
				dp[row][col]=0;
			else if(row==col)
		     dp[row][col]=1; 
		 else {
		 	if(s[row]==s[col])
		 	{
		 		dp[row][col]=2+dp[row+1][col-1];
		 	}
		 	else
		 	{
		 		dp[row][col]=max(dp[row][col-1],dp[row+1][col]);
		 	}

		 }
		

		}
	}
     return dp[0][s.length()-1];
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
		// int dp[s.length()][MAX];
  //        for(int i=0;i<s.length();i++)
  //        	for(int j=0;j<MAX;j++)
  //        		dp[i][j]=-1;
		cout<<lps(s)<<endl;
	}
	return 0;
}