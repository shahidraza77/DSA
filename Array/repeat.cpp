#include <iostream> 
#include <unordered_map> 
using namespace std; 
  
int main() 
{ 
    // Declaring umap to be of <string, int> type 
    // key will be of string type and mapped value will 
    // be of double type 
    unordered_map<int, int> umap; 
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        {
        cin>>a[i];
        umap[a[i]]=i;
        }
    // inserting values by using [] operator 
   /* umap[2] = 10; 
    umap[1] = 20; 
    umap[3] = 30;
    umap[5] = 50; 
    umap[7] = 70; 
    umap[4] = 40;
    */
  
    // Traversing an unordered map 
   unordered_map<int, int>::iterator x;
     for( x=umap.begin();x!=umap.end();x++)
      cout << x->first << " " << x->second << endl; 
  
} 