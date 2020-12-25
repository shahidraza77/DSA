#include <iostream>
#include<array>
using namespace std;
int knapsackAux(int profits[],int weights[],int c,int currentIndex,int s)
{
    if(c<=0||currentIndex<0||currentIndex>=s)
       return 0;
       int profit1=0;
   if(weights[currentIndex]<=c)
     profit1=profits[currentIndex]+knapsackAux(profits,weights,c-weights[currentIndex],currentIndex+1,s);
     int profit2= knapsackAux(profits,weights,c,currentIndex+1,s);
     return max(profit1,profit2);
}
int main()
{
    int profits[4]={31,26,72,17};
    int weights[4]={3,1,5,2};
    int capacity=7;
    cout<<knapsackAux(profits,weights,capacity,0,sizeof(profits)/sizeof(profits[0]))<<endl;
    return 0;
}