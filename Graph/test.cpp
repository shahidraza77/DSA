#include <bits/stdc++.h>
using namespace std;

void dfs(int s,bool vis[],vector<int> adj[],int p[],int &r)
{
    vis[s]=true;
    for(int j=0;j<adj[s].size();j++)
    {
        if(!vis[adj[s][j]])
        {
            int d=abs(p[s]-p[adj[s][j]]);
            if(r>d)
              r=d;
            dfs(adj[s][j],vis,adj,p,r);
            
        }
        
    }
    
}



 int find(vector<int> adj[],int p[],int n)
 {
    // for(int i=1;i<n;i++)
	   //  {
	   //      for(int j=0;j<adj[i].size();j++)
	   //         cout<<adj[i][j]<<" ";
	   //  }
	   int r=100;
	   bool vis[n+1];
    for(int i=1;i<=n;i++)
          vis[i]=false;
          
   for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
        {
            dfs(i,vis,adj,p,r);
        }
    } 
     //cout<<vis[1]<<vis[2]<<vis[3];
    return r;
 }
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int p[n+1];
	   for(int i=1;i<=n;i++)
	        cin>>p[i];
	   vector<int>adj[n+1];
	   int u,v;
	   for(int i=1;i<n;i++)
	   {
	       cin>>u>>v;
	       adj[u].push_back(v);
	   }
	   
	   //for(int i=1;i<n;i++)
	   //  {
	   //      for(int j=0;j<adj[i].size();j++)
	   //         cout<<adj[i][j]<<" ";
	   //  }
	   
	   cout<<find(adj,p,n)<<endl;
	  
	    
	}
	return 0;
}
