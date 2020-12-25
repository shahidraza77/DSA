#include <bits/stdc++.h>
#define MAX 1000007
#define N 20
int dis[MAX][N];
using namespace std;
void calDistance(int dis[][N],int k,vector<int>v[],int n)
{ 
      queue<int>q;
      q.push(k);
      int l=0;
      bool vis[n+1]={false};
      vis[k]=true;
      while(!q.empty())
     {
      int s=q.size();
      for(int i=0;i<s;i++)
      {
          int f=q.front();
          vis[f]=true;
          dis[k][f]=l;
          q.pop();
          for(int j=0;j<v[f].size();j++)
          {
              if(!vis[v[f][j]])
                q.push(v[f][j]);
          }
      }
      
      l++;
     }
     
     //cout<<dis[k][1];

 }
 int find(int dis[][N],int a,int da,int b,int db,int n)
 {
     
     
        

      for(int i=1;i<=n;i++)
          { 
            if(dis[a][i]== da && dis[b][i]==db)
                return i;
          }
         return -1;
         
         
}
int main() {
  int t;
  cin>>t;
  while(t--)
  {
      int n,q;
      cin>>n>>q;
      vector<int> v[MAX];
      
      int u,v1;
      for(int i=0;i<n-1;i++)
          {
              cin>>u>>v1;
              v[u].push_back(v1);
              v[v1].push_back(u);
          }
        // cout<<v[3][2]<<endl;
      for(int i=1;i<=n;i++)
        { 
              calDistance(dis,i,v,n);
         }
          int a,da,b,db;
          for(int i=0;i<q;i++)
          {
              cin>>a>>da>>b>>db;
              cout<<find(dis,a,da,b,db,n)<<endl;
              
          }
  }
  
  
  
  return 0;
}
