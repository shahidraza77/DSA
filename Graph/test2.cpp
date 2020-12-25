#include<bits/stdc++.h>
using namespace std;

int main()
    {
        int n,m;
        cin>>n>>m;
        set<int>s1;
        set<int>s2;
        set<int>s3;
    for (int i=1;i<=n;i++) 
    {
        if (n%i==0) 
            s1.insert(i);
    }
        
        for(int i=1;i<=m;i++) 
        {
        if (m%i==0) 
            s2.insert(i);
        }
       int  c=0;
       //int i=0;
           set <int> :: iterator itr1; 
           set <int> :: iterator itr2; 
    //cout << "\nThe set s1 is : "; 
    // for (itr = s1.begin(); itr != s2.end(); ++itr) 
    // { 
    //     c++;
    // } 
    itr1=s1.begin();
    itr2=s2.begin();
    while(itr1 !=s1.end() && itr2!=s2.end())
    {
        if(*itr1!=*itr2)
            c++;
            itr1++;itr2++;

    }
    if(itr1!=s1.end())
    {
        while(itr1!=s1.end())
        {
            c++;
            itr1++;
        }

    }
    if(itr2!=s2.end())
    {
        while(itr2!=s2.end())
        {
            c++;
            itr2++;
        }

    }
 
    cout<<c<<endl;
              
        
        return 0;
    }
    

