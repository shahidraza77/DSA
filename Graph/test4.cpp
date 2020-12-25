#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
ll sum(vector<long long int>v)
{
    // if(i>=v.size())
    //   return 0;
    // ll s1=v[i]+sum(v,i+1);
    // ll s2=sum(v,i+1);
    // return max(s1,s2);  
    int mini=INT_MIN;
     ll s=0;
    for(ll i=0;i<v.size();i++)
    {
       for(ll j=i;j<v.size();j++)
       {
           s+=v[j];
           if(s>mini)
              mini=s;
       }
       s=0;
    }
    return mini;
}
ll find(ll a[],ll c[],ll x,ll y,ll n)
     {
         vector<long long int>v;
         for(ll i=0;i<n;i++)
            {
                 if(c[i]==x||c[i]==y)
                   v.push_back(a[i]);
            }
            if(v.empty())
               return 0;
               else
               {
                   /* code */
                   ll r=sum(v);
                   v.clear();
                   return r;
               }
               
            
     }
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    ll n,q;
        cin>>n>>q;
	    ll A[300000],C[300000];
	    for(ll i=0;i<n;i++)
            cin>>A[i];
        for(ll i=0;i<n;i++)
            cin>>C[i];
      //ll x,y;
      ll input[q][2];
          for(ll i=0;i<q;i++)
          {
              //for(ll j=0;j<2;j++)
              cin>>input[i][0]>>input[i][1];
             
          }
          for(ll i=0;i<q;i++)
          {
              //for(ll j=0;j<2;j++)
              //cin>>input[i][0]>>input[i][1];
              cout<<find(A,C,input[i][0],input[i][1],n)<<endl;
          }


	}
	
	return 0;
}