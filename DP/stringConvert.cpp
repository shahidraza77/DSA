
/* ------------divide and concoquer --------------------*/
// #include <iostream>
// #include <string>
// using namespace std;
// int convert(string s1,string s2,int i,int j)
// {
//     if(i==s1.length())
//        return s2.length()-j;
//        if(j==s2.length())
//        return s1.length()-i;
//     if(s1[i]==s2[j])
//        return convert(s1,s2,i+1,j+1);
//     int x=1+convert(s1,s2,i+1,j);//insert
//     int y=1+convert(s1,s2,i,j+1);//delete
//     int z=1+convert(s1,s2,i+1,j+1);//replace
//     return min(x,min(y,z));
// }
// int main()
// {
//     int t;
//     cout<<"Enter the number of test cases:";
//     cin>>t;
//     while(t--)
//     {
//     string s1,s2;
//     cout<<"Enter 2 string:";
//     cin>>s1>>s2;
//     cout<<convert(s1,s2,0,0)<<endl;
//     }
//     return 0;
// }


//   /* ------------Top down --------------------*/

// #include <iostream>
// #include <string>
// #define MAX 100
// using namespace std;
// int convert(int dp[][MAX],string s1,string s2,int i,int j)
// {
//     if(dp[i][j]==-1)
//     {
//      if(i==s1.length())
//        dp[i][j]=s2.length()-j;
//        else if(j==s2.length())
//        dp[i][j]= s1.length()-i;
//      else if(s1[i]==s2[j])
//        dp[i][j]= convert(dp,s1,s2,i+1,j+1);
//        else
//        {
//         int x=convert(dp,s1,s2,i+1,j);//insert
//         int y=convert(dp,s1,s2,i,j+1);//delete
//         int z=convert(dp,s1,s2,i+1,j+1);//replace
//         dp[i][j]=1+min(x,min(y,z));
//        }
//     }
//     return dp[i][j];
    
// }
// int main()
// {
//     int t;
//     cout<<"Enter the number of test cases:";
//     cin>>t;
//     while(t--)
//     {
//     string s1,s2;
//     cout<<"Enter 2 string:";
//     cin>>s1>>s2;
//     int m=s1.length();
//     int dp[m+1][MAX];
//     for(int i=0;i<m+1;i++)
//        for(int j=0;j<MAX;j++)
//           dp[i][j]=-1;
//     cout<<convert(dp,s1,s2,0,0)<<endl;
//     }
//     return 0;
// }



/* ------------Bottom up --------------------*/

#include <iostream>
#include <string>
#define MAX 100
using namespace std;
int convert(string s1,string s2)
{
    int dp[s1.length()+1][s2.length()+1];
    for(int i=0;i<=s1.length();i++)
         dp[i][0]=i;
         for(int j=0;j<=s2.length();j++)
         dp[0][j]=j;
         for(int i=1;i<=s1.length();i++)
         {
            for(int j=1;j<=s2.length();j++)
            {
                if(s1[i-1]==s2[j-1])
                  dp[i][j]=dp[i-1][j-1];
                  else dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            } 
         }
    
    return dp[s1.length()][s2.length()];
    
}
int main()
{
    int t;
    cout<<"Enter the number of test cases:";
    cin>>t;
    while(t--)
    {
    string s1,s2;
    cout<<"Enter 2 string:";
    cin>>s1>>s2;
    // int m=s1.length();
    // int dp[m+1][MAX];
    // for(int i=0;i<m+1;i++)
    //    for(int j=0;j<MAX;j++)
    //       dp[i][j]=-1;
    cout<<convert(s1,s2)<<endl;
    }
    return 0;
}