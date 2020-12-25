#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    if(n<=10)
	      {
	          for(int i=0;i<=n;i++)
	            cout<<i<<" ";
	           cout<<endl; 
	      }
	      else if(n>10)
	      {
	          for(int i=0;i<=10;i++)
	            cout<<i<<" ";
	            for(int i=11;i<=n;i++)
	            {
	                bool flag=false;
	                int temp=i;
	                while(temp>=11)
	                {
	                    int d1=temp%10;
	                    temp=temp/10;
	                    int d2=temp%10;
	                    if(abs(d1-d2)!=1)
	                    {
	                      flag=true;
	                      break;
	                    }
	                      
	                }
	                if(flag==false)
	                   cout<<i<<" ";
	            }
	      }
	      cout<<endl;
	}
	return 0;
}