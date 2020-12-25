#include <stdio.h>
#include <string.h>
int fib(int n);
int main()
{
	int nterm,i;
	printf("enter number of terms:");
	scanf("%d",&nterm);
	for(i=0;i<nterm;i++)
		printf("%d ",fib(i));
}
int fib(int n)
{
	if(n==0 || n==1)
		return 1;
	return fib(n-1)+fib(n-2);
}