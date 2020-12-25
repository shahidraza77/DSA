#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int src;
    int dest;
    int weight;

};
int find(Edge* input,int* weight,bool* visited,int N)
{
    int min=INT_MAX,minVertes;
    for(int i=0;i<N;i++)
    {
        if(!visited[i] && weight[i]<min)
           {
              minVertes=i;
              min=weight[i];
           }
    }
    return minVertes;

}
void primsAlgo(Edge* input,int N,int E)
{
    Edge* output = new Edge[N-1];
    int *parent= new int[N];
    bool *visited=new bool[N];
    int *weight=new int[N];


    for(int i=0;i<N;i++)
        weight[i] = INT_MAX, visited[i]=false;
    weight[0]=0;
     parent[0]=-1;
     for(int i=0;i<N-1;i++)
     {
         int minVertex=find(input,weight,visited,N);
         visited[minVertex]=true;
         //Edge current=input[minVertex];
         for(int j=0;j<E;j++)
         {
             if(input[j].weight!= 0 && input[j].src==minVertex && !visited[input[j].dest])
             {
                 if(input[j].weight<weight[input[j].dest])
                   {
                       weight[input[j].dest]=input[j].weight;
                       parent[input[j].dest]=minVertex;
                   }
             }
         }

         
     }
   cout<<"-------output-------"<<endl;
    for(int i=1;i<N;i++)
    {
        if(parent[i]<i)
        cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        else
        {
            /* code */
             cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
        
    }




    // cout<<"-------output-------"<<endl;
    // for(int i=0;i<N-1;i++)
    //     {
    //         if(output[i].src<output[i].dest)
    //          cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
    //          else
    //          {
    //             cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight<<endl;
    //          }
             
    //     }

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
       primsAlgo(input,n,e);
    return 0;
}