#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
struct Graph{
    int v,e;
    int **adj;

};
struct Graph* adjMatrix()
{
    int u1,v1;
    struct Graph *G=(struct Graph*)malloc(sizeof(struct Graph));
    if(!G)
      {
          cout<<"Error";
          return NULL;
      }
      cout<<"Enter the number of vertices and edges: ";
      cin>>G->v>>G->e;
      G->adj=(int**)malloc(((G->v) * sizeof(int *)));
      for(int i=0;i<G->v;i++)
           G->adj[i]=(int*)malloc(((G->v) * sizeof(int )));
      printf("after malloc");
      for(int i=0;i<G->v;i++)
        for(int j=0;j<G->v;j++)
           G->adj[i][j]=0;
           for(int i=0;i<G->e;i++)
           {
               cout<<"Enter edges:";
               cin>>u1>>v1;
               G->adj[u1][v1]=1;
               G->adj[v1][u1]=1;

           }
           return G;
       
}
void display(struct Graph *g)
{
    
    for(int i=0;i<g->v;i++)
    {
        for(int j=0;j<g->v;j++)
        {
          cout<<g->adj[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    struct Graph* t;
    t=adjMatrix();
    if(t==NULL)
      return 1;
      else
       display(t);
    return 0;
}