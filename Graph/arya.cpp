#include <bits/stdc++.h>
#define MAX 1001
int maxi=0;
using namespace std;
void backToOrigin(char mat[][MAX],bool vis[][MAX],int i,int j,int k,int x,int &c,int m,int n)
{
  if(i==0 && j==0)
  {
    if(c>=maxi)
    {
       maxi=c;
    }
      //c=0;
     for(int r=0;r<m;r++)
     {
         for(int t=0;t<n;t++)
         {
            
            vis[r][t]=false;
         }
     }
     return;
  }
  if(i<=-1 || j>=n)
     return;
    if(mat[i][j]=='*' && vis[i][j]==false)
        {
              c++;
              vis[i][j]=true;
        }
        if(mat[i][j-1]!='#' && vis[i][j-1] && abs(k-j+1)<=x)
          backToOrigin(mat,vis,i,j-1,k,x,c,m,n);
        if(mat[i-1][j]!='#')
          backToOrigin(mat,vis,i-1,j,j,x,c,m,n);
}
void find(char mat[][MAX],bool vis[][MAX],int i,int j,int k,int x,int &c,int m,int n)
{
       if(i==m && j==n)
          {
            backToOrigin(mat,vis,m-1,n-1,n-1,x,c,m,n);
            return;
          }
        if(i>=m || j>=n)
          return;  
        if(mat[i][j]=='*' && vis[i][j]==false)
        {
              c++;
              vis[i][j]=true;
        }
        if(mat[i][j]!='#' && abs(k-j)<=x)
          find(mat,vis,i,j+1,k,x,c,m,n);
        if(mat[i][j]!='#')
          find(mat,vis,i+1,j,j,x,c,m,n);



}

int main()
{
    int m,n,x;
    cin>>m>>n>>x;
    char mat[MAX][MAX];
    bool vis[MAX][MAX];
    for(int i=0;i<m;i++)
     {
         for(int j=0;j<n;j++)
         {
            cin>>mat[i][j];
            vis[i][j]=false;
         }
     }
     if(x==0)
        cout<<-1;
        else
        {
            int c=0;
            find(mat,vis,0,0,0,x,c,m,n);
            cout<<maxi;
        }
        
     
    return 0;
}