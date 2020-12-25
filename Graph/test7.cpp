#include <iostream>
using namespace std;
bool find(int a[],int i,int n,int m)
{
    if(m==0)
     return true;
    if(i>=n)
       return false;
     
    if(a[i]<=m)
      return find(a,i+1,n,m-a[i]) || find(a,i+1,n,m);
     else
       return find(a,i+1,n,m);
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    int a[n];
	    for(int i=0;i<n;i++)
	       cin>>a[i];
	   
	  bool r= find(a,0,n,m);
	  if(r==true)
	    cout<<"Yes"<<endl;
	    else
	    cout<<"No"<<endl;
	}
	return 0;
}
