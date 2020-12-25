#include <iostream>
using namespace std;

int main() {
	//code
	int t,n;
	  cin>>t;
	  while(t--)
	  {
	  	cin>>n;
	  	int odd[n],even[n],oddNo=0,evenNo=0;
	  	int num;
	  	for(int i=0;i<n;i++)
	  	{
	  		cin>>num;
	  		if(num%2==0)
	  		{
	  			even[evenNo]=num;
	  			evenNo++;
	  		}
	  		else
	  		{
	  			odd[oddNo]=num;
	  			oddNo++;
	  		}
	  	}
	  	
	  	for(int i=0;i<oddNo-1;i++)
	  	{
	  		for(int j=i+1;j<oddNo;j++)
	  		{
	  			if(odd[i]<odd[j])
	  			{
	  				int temp=odd[i];
	  				odd[i]=odd[j];
	  				odd[j]=temp;
	  			}
	  		}
	  	}
	  	for(int i=0;i<evenNo-1;i++)
	  	{
	  		for(int j=i+1;j<evenNo;j++)
	  		{
	  			if(even[i]>even[j])
	  			{
	  				int temp=even[i];
	  				even[i]=even[j];
	  				even[j]=temp;
	  			}
	  		}
	  	}
	  	for(int i=0;i<oddNo;i++)
	  		cout<<odd[i]<<" ";
	  	for(int i=0;i<evenNo;i++)
	  		cout<<even[i]<<" ";
	  	   cout<<endl;
	  }
	return 0;
}