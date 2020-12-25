#include <iostream>
using namespace std;
int PalinArray(int a[], int n);
int main()
{
    int a[20],n;
    cin>>n;
    int result=PalinArray(a,n);
    if((resut==1))
        cout<<"True";
    else
        cout<<"False";
    return 0;
}
int PalinArray(int a[], int n)
{  
    int count=0,i;
    while(1)
    {
        for(i=0;i<n;i++)
        {
            int rev=0;
            int num=a[i];
            int digit=0;
            while(num>0)
            {
                digit=num%10;
                num=num/10;
                rev=rev*10+digit;
            }
                if(rev==a[i])
                 count++;
                 else
                 return 0;
        }
        return 1;
    }
}