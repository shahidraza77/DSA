/*  ---------------D & C-----------------*/


#include<iostream>
#include<string.h>
using namespace std;
int LCS(string s1,string s2,int i1,int i2)
{
   if(i1==s1.size()||i2==s2.size())
      return 0;
         int c3=0;
            if(s1[i1]==s2[i2])
                 c3=1+LCS(s1,s2,i1+1,i2+1);
                 int c1=LCS(s1,s2,i1,i2+1);
                 int c2=LCS(s1,s2,i1+1,i2);
                 return max(c3,max(c1,c2));
}
int main()
{

    int t;
    cout<<"Enter number of test cases:";
    cin>>t;
    while(t--)
    {
        cout<<"Enter two string:";
        string s1,s2;
        cin>>s1>>s2;
        cout<<LCS(s1,s2,0,0)<<endl;
    }
    // string s1="AGGTAB";
    // string s2="GXTXAY";
    // int m=s1.size();
    // int n=s2.size();
    // int dp[m][MAX];
    // memset(dp,-1,sizeof(dp));
    // cout<<LCS(s1,s2,0,0,dp)<<endl;
    return 0;
}
// #include<iostream>
// #include<string.h>
// const int MAX=1000;
// using namespace std;
// int LCS(string s1,string s2,int i1,int i2,int dp[][MAX])
// {
//    if(i1==s1.size()||i2==s2.size())
//       return 0;
//       if(dp[i1][i2]==-1)
//         {
//             if(s1[i1]==s2[i2])
//              {
//                  dp[i1][i2]=1+LCS(s1,s2,i1+1,i2+1,dp);
//                  return dp[i1][i2];
//              }
//              else
//              {
//                  int c1=LCS(s1,s2,i1,i2+1,dp);
//                  int c2=LCS(s1,s2,i1+1,i2,dp);
//                  dp[i1][i2]=max(c1,c2);
//              }
//         }
//         return dp[i1][i2];
// }
// int main()
// {
//     string s1="AGGTAB";
//     string s2="GXTXAY";
//     int m=s1.size();
//     int n=s2.size();
//     int dp[m][MAX];
//     memset(dp,-1,sizeof(dp));
//     cout<<LCS(s1,s2,0,0,dp)<<endl;
//     return 0;
// }
/* ------------------using Recursion------------------*/
// #include <iostream>
// using namespace std;
// int LCS(string s1,string s2,int i,int j)
//   {
//     if(s1[i]=='\0'||s2[j]=='\0')
//         return 0;
//     else if(s1[i]==s2[j])
//            return 1+LCS(s1,s2,i+1,j+1);
//        else
//         return max(LCS(s1,s2,i+1,j),LCS(s1,s2,i,j+1));
//   }
// int main()
// {
//     string s1="abcd";
//     string s2="bd";
//     //int m=s1.size();
//     //int n=s2.size();
//     //int dp[m][MAX];
//     //memset(dp,-1,sizeof(dp));
//     cout<<LCS(s1,s2,0,0)<<endl;
//     return 0;
// }
/* ------------------using bottom up ------------------*/
/* Dynamic Programming C++ implementation of LCS problem */
// #include<bits/stdc++.h>  
// using namespace std; 
  
// int max(int a, int b);  
  
// /* Returns length of LCS for X[0..m-1], Y[0..n-1] */
// int lcs( char *X, char *Y, int m, int n )  
// {  
//     int L[m][n]; 
//     int i, j;  
      
//     /* Following steps build L[m+1][n+1] in  
//        bottom up fashion. Note that L[i][j]  
//        contains length of LCS of X[0..i-1] 
//        and Y[0..j-1] */
//     for (i = 0; i <= m; i++)  
//     {  
//         for (j = 0; j <= n; j++)  
//         {  
//         if (i == 0 || j == 0)  
//             L[i][j] = 0;  
      
//         else if (X[i - 1] == Y[j - 1])  
//             L[i][j] = L[i - 1][j - 1] + 1;  
      
//         else
//             L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
//         }  
//     }  
          
//     /* L[m][n] contains length of LCS  
//     for X[0..n-1] and Y[0..m-1] */
//     return L[m][n];  
// }  
  
// /* Utility function to get max of 2 integers */
// int max(int a, int b)  
// {  
//     return (a > b)? a : b;  
// }  
  
// // Driver Code 
// int main()  
// {  
//     char X[] = "AGGTAB";  
//     char Y[] = "GXTXAYB";  
      
//     int m = strlen(X);  
//     int n = strlen(Y);  
      
//     cout << "Length of LCS is :" << lcs( X, Y, m, n )<<endl;  
      
//     return 0;  
// }  