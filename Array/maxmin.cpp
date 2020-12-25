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
	     cout<<"Please enter 3 didgit number or more";
	     continue;
	    }
	    else
	    {
	    n1=n*2;
	    n2=n*3;
	    int i=0;
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
	   for(int i=0;i<9;i++)
	   {
	       if(a2[i]==a1[i])
	          count++;
	   }
	   if(count==9)
	   cout<<"1"<<endl;
	   else
	   cout<<"0"<<endl;
	   t--;
	}
	return 0;
}
/*#include <iostream>
using namespace std;
int main()
{
	/*int a[20],n,t,i,min,max;
	cout<<"Enter the test cases:";
	cin>>t;
	while(t>0)
	{
		cout<<"Enter size of array: ";
		cin>>n;
		cout <<"enter the elements:";
		for(i=0;i<n;i++)
             cin>>a[i];
         max=min=a[0];
         for(i=1;i<n;i++)
         {
         	if(max<a[i])
         		max=a[i];
         	else if(min>a[i])
         		min=a[i];
         }
         cout<<max<<" "<<min<<endl;
         t--;
	}
	return 0;
	
	int t,n;
	int a[500];
	cin>>t;
	  while(t--)
	  {
	  	 cin>>n;
	  	 for(int i=0;i<n;i++)
	      cin>>a[i];
	    for( int i=0;i<n-1;i++)
	    {
	    	for(int j=0;j<n-1-i;j++)
	    	{
	          if(a[j]>a[j+1])
	         {
	            int temp=a[j];
	            a[j]=a[j+1];
	            a[j+1]=temp;
	         }
	       }
	    }
	       cout<<a[n-2]<<endl;
	    }  
	
	
	return 0;
}*/