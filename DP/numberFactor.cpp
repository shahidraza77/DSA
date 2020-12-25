/* Diivide and concoquer given sum(n) as of 1,3,4 */
// #include <iostream>
// using namespace std;
// int sum(int n)
// {
// 	if(n==0||n==1||n==2)
// 		return 1;
// 	if(n==3)
// 		return 2;
// 	int x=sum(n-1);
// 	int y=sum(n-3);
// 	int z=sum(n-4);
// 	return x+y+z;
// }
// int main()
// {
// 	int t;
// 	cin>>t;
// 	while(t--)
// 	{
// 		int n;
// 		cin>>n;
// 		cout<<sum(n)<<endl;
// 	}
// 	return 0;
// }

//                /* DP using top down given sum(n) as of 1,3,4 */

// #include <iostream>
// using namespace std;
// int sum(int dp[],int n)
// {
// 	if(n==0||n==1||n==2)
// 		return 1;
// 	if(n==3)
// 		return 2;
// 	if(dp[n]==0)
// 	{
// 	int x=sum(dp,n-1);
// 	int y=sum(dp,n-3);
// 	int z=sum(dp,n-4);
// 	dp[n]=x+y+z;
//    }
//    return dp[n];
// }
// int main()
// {
// 	int t;
// 	cout<<"Enter the number of test cases:";
// 	cin>>t;
// 	while(t--)
// 	{
// 		int n;
// 		cout<<"Enter the given sum number:";
// 		cin>>n;
// 		int dp[n+1];
// 		for(int i=0;i<n+1;i++)
// 			dp[i]=0;
// 		cout<<sum(dp,n)<<endl;
// 	}
// 	return 0;
// }




               /* DP using bottomup given sum(n) as of 1,3,4 */

#include <iostream>
using namespace std;
int sum(int dp[],int n)
{
	//if(n==0||n==1||n==2)
		//return 1;
	//if(n==3)
		//return 2;
	dp[0]=dp[1]=dp[2]=1;
	dp[3]=2;
	for(int i=4;i<=n;i++)
		dp[i]=dp[i-1]+dp[i-3]+dp[i-4];
   return dp[n];
}
int main()
{
	int t;
	cout<<"Enter the number of test cases:";
	cin>>t;
	while(t--)
	{
		int n;
		cout<<"Enter the given sum number:";
		cin>>n;
		int dp[n+1];
		for(int i=0;i<n+1;i++)
			dp[i]=0;
		cout<<sum(dp,n)<<endl;
	}
	return 0;
}