#include <iostream>
using namespace std;

int main() {
	//code
	int a1[]={1,2,3,4,5,6,7,8,9};
	int a2[200];
	int n1,n2,digit,t,n;
	cin>>t;
	while(t>0)
	{
	    cin>>n;
	    if(n<100)
	    {
	     cout<<"Please enter 3 didgit number or more: ";
	     continue;
	    }
	    else
	    {
	    n1=n*2;
	    n2=n*3;
	    int i=0;
	    while(n>0)
	    {
	      digit=n1%10;
	      a2[i]=digit;
	      i++;
	      n=n/10;
	    }
	    while(n1>0)
	    {
	      digit=n1%10;
	      a2[i]=digit;
	      i++;
	      n1=n1/10;
	    }
	    while(n2>0)
	    {
	      digit=n2%10;
	      a2[i]=digit;
	      i++;
	      n2=n2/10;
	    }
	   for(int j=0;j<i-1;j++)
	   {
	       for(int k=0;k<i-1-j;k++)
	       {
	           if(a2[j]>a2[j+1])
	           {
	               int temp=a2[j];
	                   a2[j]=a2[j+1];
	                   a2[j+1]=temp;
	           }
	       }
	   }
	    }
	   int count=0;
	   for(int i=0;i<10;i++)
	   {
	       //if(a2[i]==a1[i])
	   	    cout<<a2[i]<<" ";
	          count++;
	   }
	   /*if(count==9)
	   cout<<"1"<<endl;
	   else
	   cout<<"0"<<endl;
	   */
	   t--;
	}
	return 0;
}