#include <bits/stdc++.h>
#define MAX 100001
#define N 302
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,q;
	    cin>>n>>q;
	    vector<int> v[MAX];
      int dis[N][N];
	    int u,v1;
	    for(int i=0;i<n-1;i++)
	        {
	            cin>>u>>v1;
	            v[u].push_back(v1);
              v[v1].push_back(u);
	        }
         cout<<v[3][2]<<endl;
    
	}
	return 0;
}