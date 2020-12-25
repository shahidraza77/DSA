#include <iostream>
using namespace std;
void buildHeap(int arr[],int i)
    {
    	int k=arr[i];
    	int par=i/2;
    	while(arr[par]<k)
    	{
    		arr[i]=arr[par];
    		i=par;
    		par=i/2;
    	}
    	arr[i]=k;
    }
int main()
 {
 	int a[100];
 	int i,j,n;
 	cin>>n;
 	for(i=1;i<=n;i++)
 		 scanf("%d",&a[i]);
 		for(i=2;i<=n;i++)
 			 buildHeap(a,i);//cout<<a[i]<<" ";
 			   for(i=1;i<=n;i++)
 			   	  cout<<a[i]<<" ";
 			return 0;
 }