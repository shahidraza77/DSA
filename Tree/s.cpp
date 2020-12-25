#include <iostream>
using namespace std;
void sort(int arr[],int n);
int main()
{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];
       sort(arr,n);
       //for(i=0;i<n;i++)
		 // cout<<arr[i]<<" ";
	return 0;

}
void sort(int arr[],int n)
  {
  	int ac[10]={0,0,0,0,0,0,0,0,0,0};
  	int a[n];
  	 for(int i=0;i<n;i++)
  	 {
 	  	int c=arr[i];
 	  	 	 	  	  //cout<<arr[i]<<" ";
  	 	  	ac[c]=ac[c]+1;
  	 }
  	 	  for(int i=0;i<10;i++)
  	 	  	   cout<<ac[i]<<" ";
  	 	  	   cout<<endl;
  	 	  for(int i=1;i<10;i++)
  	 	  	  {
                  ac[i]=ac[i]+ac[i-1];
  	 	  	  }
  	 	  	  for(int i=0;i<10;i++)
  	 	  	  	   cout<<ac[i]<<" ";
  	 	  	  	  cout<<endl;
  	 	for(int i=0;i<n;i++)
  	 	{
  	 		       int x=ac[arr[i]];	       
	  	 		           ac[arr[i]]-=1;
  	 		       a[x-1]=arr[i];

  	 	}
  	 	for(int i=0;i<n;i++)
  	 	 cout<<a[i]<<" ";
  }