#include <iostream>
#include<cstring>
#define MAX 256
using namespace std;
bool compare(char arr1[],char arr2[]);
void search(char *pat,char *txt);
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    char s[MAX],c[MAX];
	    scanf("%s",s);
	    scanf("%s",c);
	   // gets(c);
	    search(c,s);
	}
	return 0;
}
void search(char *pat,char *txt)
{
    int M=strlen(pat);
    int N=strlen(txt);
    char countP[MAX]={0},countTW[MAX]={0};
    for(int i=0;i<M;i++)
    {
        (countP[pat[i]])++;
        (countTW[txt[i]])++;
    }
    int c=0;
    for(int i=M;i<N;i++)
    {
        if(compare(countP,countTW))
            c++;
            (countTW[txt[i]])++;
            (countTW[txt[i-M]])--;
    }
    if(compare(countP,countTW))
         c++;
         cout<<c<<endl;
}
bool compare(char arr1[],char arr2[])
     {
         for(int i=0;i<MAX;i++)
         {
           if(arr1[i]!=arr2[i])
              return false;
         }
         return true;
     }