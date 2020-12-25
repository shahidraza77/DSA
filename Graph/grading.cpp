#include <bits/stdc++.h>
using namespace std;
int max(int i,int j)
{ 
	if(i>j)
		return i;
	else
		return j;
}
int find(int a[],int n)
{ 
	if(n==1)
		return 1;
	if(n==2)
		return 3;
	vector<int>ans(n,1);
	for(int i=n-2;i>=1;i--)
		{ 
			if(a[i]>a[i+1]&&a[i]>a[i-1])
				ans[i]=1+max(ans[i+1],ans[i-1]);
			else if( a[i]>a[i-1]&& a[i]<a[i+1] && ans[i]<=ans[i-1])
				  { 
				  	ans[i]=1+a[i-1];
				  	if(ans[i]==ans[i+1])
				  		ans[i+1]=1+ans[i];
				  }
			else if(a[i]<a[i-1]&& a[i]>a[i+1] && ans[i]<=ans[i+1])
			{ 
				ans[i]=1+a[i+1];
				  	if(ans[i]==ans[i-1])
				  		ans[i-1]=1+ans[i];
			}
			else{ 

			}	  
		}
		if(a[0]>a[1] && ans[0]<=ans[1])
			ans[0]=1+ans[1];
		int s=0;
		for(int i=0;i<n;i++)
			  s+=ans[i];
			return s;

}

int main()
{ 
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		   cin>>a[i];
		cout<<find(a,n)<<endl;
	return 0;
}
