#include <stdio.h>
void gcd(int n1,int n2);
int main()
{
	int n1,n2;
	printf("Enter two numbers:");
	scanf("%d %d",&n1,&n2);
	gcd(n1,n2);
	return 0;
}
void gcd(int n1,int n2)
{
	int temp;
	if(n2>n1)
	{
		n1=n1+n2;
		n2=n1-n2;
		n1=n1-n2;
		printf(" %d %d ",n1,n2);
	}
	while(n1%n2!=0)
	{
      temp=n2;
      n2=n1%n2;
      n1=temp;
	}
	printf("gcd of n1 and n2=%d\n",n2);
}