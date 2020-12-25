// #include<iostream>
// #include<vector>
// using namespace std;
// int maxStolen(int a[],int i,int m,int result[]);
// //vector<int>result(100);
// int main()
// {
//     int t;
//     cout<<"enter number of test cases:";
//     cin>>t;
//     while(t--)
//     {
//         int n;
//         cout<<"enter size of array";
//         cin>>n;
//         int A[n];
//         int result[n];
//         cout<<"Enter array element:";
//         for(int i=0;i<n;i++)
//           cin>>A[i];
//           for(int i=0;i<n;i++)
//           result[i]=0;
//           cout<<maxStolen(A,0,n,result)<<endl;
//         //   result.clear();
//         //   for(int i=0;i<n;i++)
//         //       cout<<result[i]<<" ";
//         //       cout<<endl;
          
//     }
//     //int A[]={6,7,1,30,8,2,4};
//     //int m=sizeof(A)/sizeof(*A);
//     return 0;
// }
// int maxStolen(int a[],int i,int m,int result[])
// {
//     // if(i>=m)
//     //    return 0;
//     // int x=a[i]+maxStolen(a,i+2,m);
//     // int y=maxStolen(a,i+1,m);
//     // return max(x,y);
//     if(i>=m)
//       return 0;
//     if(result[i]==0)
//     {
//        int x=a[i]+maxStolen(a,i+2,m,result); 
//        int y=maxStolen(a,i+1,m,result);
//        result[i]=max(x,y);
//     }
//     return result[i];
// }
/* --------Bottom up approach-------*/
#include<iostream>
#include<vector>
using namespace std;
int maxStolen(int a[],int m);
//vector<int>result(100);
int main()
{
    int t;
    cout<<"enter number of test cases:";
    cin>>t;
    while(t--)
    {
        int n;
        cout<<"enter size of array";
        cin>>n;
        int A[n];
       // int result[n];
        cout<<"Enter array element:";
        for(int i=0;i<n;i++)
          cin>>A[i];
          cout<<maxStolen(A,n)<<endl;
        //   result.clear();
        //   for(int i=0;i<n;i++)
        //       cout<<result[i]<<" ";
        //       cout<<endl;
          
    }
    //int A[]={6,7,1,30,8,2,4};
    //int m=sizeof(A)/sizeof(*A);
    return 0;
}
int maxStolen(int a[],int m)
{
    // if(i>=m)
    //    return 0;
    // int x=a[i]+maxStolen(a,i+2,m);
    // int y=maxStolen(a,i+1,m);
    // return max(x,y);
    int result[m+2]={0};
    for(int i=m-1;i>=0;i--)
    {
       
       result[i]=max(a[i]+result[i+2],result[i+1]);
    }
    return result[0];
}