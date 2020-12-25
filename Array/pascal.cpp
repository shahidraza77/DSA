#include <iostream>
using namespace std;
long int fact(int k);
int main() 
   {
   long long Arr[25],t,i,n;
    unsigned int k;
    cin>>t;
    while(t>0)
    {
       cin>>k;
       for(i=0;i<k;i++)
       {
           Arr[i]=fact(k-1)/(fact(k-1-i)*fact(i));
       }
       for(i=0;i<k;i++)
          cout<<Arr[i]<<" ";
          cout<<endl;
        t--;
    }
    
	return 0;
}
long int fact(int k)
{
    if(k==0 || k==1)
    return 1;
    return k*fact(k-1);
}/*#include <bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k) 
{ 
  int res = 1; 
  if (k > n - k) 
  k = n - k; 
  for (int i = 0; i < k; ++i) 
  { 
    res *= (n - i); 
    res /= (i + 1); 
  } 
  
  return res; 
} 
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        n = n-1;
        for(int i = 0; i <= n; i++)
        {
            cout << binomialCoeff(n,i) << " ";
        }
        cout << endl;
    }

  return 0;
}*/