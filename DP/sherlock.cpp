#include <bits/stdc++.h> 
#include<string.h> 
using namespace std; 
  
  
/* Following function is used by 
the library qsort() function  
to sort an array of chars */
//int compare (const void * a, const void * b);  
  
/* The main function that recursively 
prints all repeated permutations of 
the given string. It uses data[] to store all  
permutations one by one */
void allLexicographicRecur (vector<int>&v, vector<int>&temp,  
                            int last, int index,vector<int>r[],int &j)  
{  
     
  
    // One by one fix all characters at 
    // the given index and recur for  
    // the/ subsequent indexes  
    for (int i = 0; i < v.size(); i++ )  
    {  
        // Fix the ith character at index  
        // and if this is not the last  
        // index then recursively call  
        // for higher indexes  
        temp[index] = v[i] ;  
  
        // If this is the last index then 
        // print the string stored in  
        // data[]  
        if (index == last)  
            {
                r[j]=temp;
                j++;
            }  
        else // Recur for higher indexes  
            allLexicographicRecur (v, temp, last, index+1,r,j);  
    }  
}  
  
/* This function sorts input string, 
allocate memory for data (needed  
for allLexicographicRecur()) and  
calls allLexicographicRecur() for  
printing all permutations */
void cost(vector<int>&v)  
{  
    //int len = strlen (str) ;  
  
    // Create a temp array that will  
    // be used by allLexicographicRecur()  
    //char *data = (char *) malloc (sizeof(char) * (len + 1)) ;  
    //data[len] = '\0'; 
    vector<int>temp; 
    vector<int>r[v.size()*v.size()];
  
    // Sort the input string so that 
    // we get all output strings in  
    // lexicographically sorted order  
    //qsort(str, len, sizeof(char), compare);  
  
    // Now print all permutaions  
    int j=0;
    allLexicographicRecur (v, temp, v.size()-1, 0,r,j);
    for(int i=0;i<v.size()*v.size();i++)
    {
        for(int j=0;j<r[i].size();j++)
        cout<<r[i][j];

      cout<<endl;
}


  
    // Free data to avoid memory leak  
    //free(data);  
}  
  
// Needed for library function qsort()  
// int compare (const void * a, const void * b)  
// {  
//     return ( *(char *)a - *(char *)b );  
// }  
  
// Driver code  
int main()  
{  
    int t;
    cin>>t;
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
         cin>>v[i];
     cost(v);
    // char str[] = "ABC";  
    // cout << "All permutations with repetition of "<<  
    //                             str <<" are: "<<endl ;  
    // allLexicographic(str);  
    return 0;  
}  