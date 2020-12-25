#include <bits/stdc++.h>
#define N 200002
using namespace std;
int a[N+1];
int b[N+1][2];
int c[N+1][3];
vector<int>G[N];

void createGraph(int b[][2],int n)
{
	int u,v;
        for(int i=0;i<n-1;i++)
        	{ 
        		u=b[i][0];
        		v=b[i][1];
        		G[u].push_back(v);
        		G[v].push_back(u);
        	}
}

void DFS(int s,int d,bool vis[],vector<int>&p)
{
      p.push_back(s);
      if(s==d)
      {
      	//cout<<p.size() <<"Hello"<<endl;
          return;
      }
      vis[s]=true;
      if(!G[s].empty())
      { 
      	for(int j=0;j<G[s].size();j++)
      		{ 
      			if(!vis[G[s][j]])
      				DFS(G[s][j],d,vis,p);
      		}
      }
      p.pop_back();     
}



int calPath(int s,int d,int w,int n)
{ 
	vector<int>path;
	bool vis[n+1];
	for(int i=1;i<=n;i++)
		  vis[i]=false;
	// for(int i=1;i<=n;i++)
	// 	  cout<<vis[i]<<" ";
	// 	  cout<<endl;	
	DFS(s,d,vis,path);
	int c=0;
	for(int i=0;i<path.size();i++)
		{ 
			cout<<path[i]<<" ";
			 if(a[path[i]]<=w)
			 	c++;
		}
		cout<<endl;
		//cout<<"Count:"<<c;
		path.clear();
		return c;

}
vector<int> find(int c[][3],int q,int n)
{ 
	vector<int>result;
    for(int i=0;i<q;i++)
       { 
       	//for(int j=0;j<3;j++)
       		//{
       		    int r=calPath(c[i][0],c[i][1],c[i][2],n); 
       		   //cout<<r<<" ";
       			//cout<<c[i][j]<<" ";
       		//}
       		//cout<<endl;
       } 
       return result; 
}
int main()
{ 
	int t;
	cin>>t;
	while(t--)
		{ 
			int n,q;
			cin>>n>>q;
			
			for(int i=1;i<=n;i++)
				 cin>>a[i];
			  
			for(int i=0;i<n-1;i++)
			     for(int j=0;j<2;j++)
			         cin>>b[i][j];
			
			 for(int i=0;i<q;i++)
			      for(int j=0;j<3;j++)
			         cin>>c[i][j];
			         vector<int>ans;
			         createGraph(b,n);
			         //cout<<G[2][0];
			          ans=find(c,q,n);
			         // for(int i=0;i<ans.size();i++)
			         // 	  cout<<ans[i]<<" ";
			         	cout<<endl;


		}

	return 0;
}
/*
1
5 5
4 7 8 6 4
1 5
5 2
2 3
2 4
4 2 1
2 3 7
2 4 8
5 3 1
3 4 8
*/
