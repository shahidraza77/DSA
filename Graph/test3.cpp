#include<bits/stdc++.h>
int r=0;
using namespace std;
void solve(int a[],int n)
{
    bool f=false;
    for(int i=1;i<=n;i++)
        {
            if((a[i-1]+a[i])%3==0)
               f=true;
              // cout<<a[i-1]<<" ";
        }
        //cout<<endl;
        if(f==false)
            r=1;
            //cout<<r<<" ";
        
}
void  permute(int a[],int l,int r)
{
    if(l==r)
      {
          solve(a,r);
            
      }
      for(int i=l;i<=r;i++)
      {
          swap(a[l],a[i]);
          permute(a,l+1,r);
          swap(a[l],a[i]);
      }
}
string find(int a[],int n)
{
    //bool flag=false;
    
    permute(a,0,n-1);
    if(r)
     return "Yes";
     else
     {
         
         return "No";
     }
     
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout<<find(a,n)<<endl;
    }
    return 0;
}