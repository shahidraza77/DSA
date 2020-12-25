#include <stdio.h>
#include <string.h>
int sumdigit(int n);
void display( int n);
void rdisplay(int n);
int main()
{
	int num;
	printf("enter the number:");
	scanf("%d",&num);
	printf("sum of digit=%d\n",sumdigit(num));
	display(num);
	printf("\n");
	rdisplay(num);
	return 0;
}
int sumdigit(int n)
{
	if(n/10==0)
		return n;
	return n%10+sumdigit(n/10);
}
void display(int n)
{
	if(n/10==0)
	{
		printf("%d ",n);
		return;
	}
	display(n/10);
	printf("%d ",n%10);
}
void rdisplay(int n)
{
	if(n/10==0)
	{
		printf("%d ",n);
		return;
	}
	printf("%d ",n%10);
	rdisplay(n/10);
}