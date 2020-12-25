#include <iostream> 
//#include <bits/stdc++.h> 
#include <set>  
  
using namespace std;  
int main()  
{  
    set<int> s;  
   
    // Function to insert elements  
    // in the set container  
    s.insert(1);  
    s.insert(4);  
    s.insert(2);  
    s.insert(5);  
    s.insert(3); 
    s.insert(3); 
    s.insert(8);
    set<int>:: iterator it=s.begin();
    cout << "The elements in set are: ";  
    for (it = s.begin(); it != s.end(); it++)  
        cout << *it << " ";  
        cout<<endl<<s.size();
    return 0;  
}  
for(int i=0;i<n;i++)
{
    for(int j=i+1;j<n;j++)
    {
        if(A[i]==A[j])
        {
            for(int k=j;k<n;k++)
            {
                A[k]=A[k+1];
            }
            n--;
            j--;
        }
    }
}
return n;