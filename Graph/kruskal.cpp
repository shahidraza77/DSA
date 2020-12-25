#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int src;
    int dest;
    int weight;

};
bool myComp(Edge e1,Edge e2)
{
    return e1.weight< e2.weight;
}
int find(int v,int *parent)
{
    if(v==parent[v])
      return v;
    return find(parent[v],parent);  
}
void kruskalAlgo(Edge* input,int N,int E)
{
    sort(input,input+E,myComp);
    Edge* output = new Edge[N-1];
    int *parent= new int[N];
    for(int i=0;i<N;i++)
         parent[i]=i;
    int count=0;
    int i=0;
    while(count!=N-1)
    {
        Edge current=input[i];
        int source=find(current.src,parent);
        int destination=find(current.dest,parent);
        if(source!=destination)
        {
            output[count]=current;
            count++;
            parent[source]=destination;
        }
        i++;
    }
    cout<<"-------output-------"<<endl;
    for(int i=0;i<N-1;i++)
        {
            if(output[i].src<output[i].dest)
             cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
             else
             {
                cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight<<endl;
             }
             
        }

}

int main()
{
    int n,e;
    cout<<"input vertex and edges"<<endl;
    cin>>n>>e;
    Edge *input = new Edge[e];
    cout<<"input graph value"<<endl;
    for(int i=0;i<e;i++)
       {
           int s,d,w;
           cin>>s>>d>>w;
           input[i].src=s;
           input[i].dest=d;
           input[i].weight=w;
       }
       kruskalAlgo(input,n,e);
    return 0;
}