#include <bits/stdc++.h>
//long long s=0;
using namespace std;

void find(long long n,long long k,long long x,long long level,long long par ,long long ele,long long & r)
{ 
	if(n==1)
		return;
	if(level>1 && level==n && ele==x)
	{ 
		r=(r+1)%10000000007;
		return ;
	}
	if(level>n)
		return;
	//cout<<"ss"<<" ";
      for(long long i=1;i<=k;i++)
      	{ 
      		if(par!=i)
      		     find(n,k,x,level+1,i,i,r);
 
      		
      	}
      	
}
long long constructArray(long long n,long long k,long long x)
{ 
	long long r=0;
	find(n,k,x,1,1,1,r);
	return r;
}
int main()
{ 
	long long n,k,x;
	cin>>n>>k>>x;
	long long r=constructArray(n,k,x);
	cout<<r<<endl;
	return 0;
}

