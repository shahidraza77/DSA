#include <iostream>
#include <string>
using namespace std;
#define max 100
void show(int a[][max],int m,int n)
     {
       for(int i=0;i<m;i++)
         for(int j=0;j<n;j++) 
         cout<<a[i][j]<<" "; 
     }
int main() {
  int a[3][max];
  for(int i=0;i<3;i++)
     for(int j=0;j<3;j++)
         cin>>a[i][j];
  
  show(a,3,3);
  //cout << "The length of the txt string is: " << txt.length();
  return 0;
}

