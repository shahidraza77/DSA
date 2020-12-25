#include <stdio.h>
#include <string.h>
void pFactor(int num);
int gcd(int,int);
int main()
{
	int a,b;
	printf("Enter the value of a,b:");
	scanf("%d%d",&a,&b);
	printf("prime factor of a is:");
	pFactor(a);
	printf("\ngcd of a,b=%d\n",gcd(a,b));
	return 0;
}
void pFactor(int num)
{
	int i=2;
	if(num==1)
		return;
	while(num%i !=0)
		i++;
	printf("%d ",i);
	pFactor(num/i);
}
int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
