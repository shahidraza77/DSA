#include <iostream>
using namespace std;

int main() {
    int n,t,a1[100],a2[100];
    cin>>t;
    while(t>0)
    {
        int count=0;
        cin>>n;
        for(int i=0;i<n;i++)
           cin>>a1[i];
            int j=0;
           for(int i=n-1;i>=0;i--)
           {
               a2[j+1]=a1[i];
           }
           for(int i=0;i<n;i++)
           {
               if(a1[i]==a2[i])
               count++;
           }
           if(count==n)
           cout<<"perfect"<<endl;
           else
           cout<<"not perfect"<<endl;
           t--;
    }
	//code
	return 0;
}