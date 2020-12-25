#include <stdio.h>
void pf(int num);
int main()
{
	int num;
	printf("Enter a number:");
	scanf("%d",&num);
	pf(num);
	return 0;
}
void pf(int num)
 {
 	int i;
 	for(i=2;num>1;i++)
 	{
 		while(num%i==0)
 		{
 			printf("%d ",i);
 			num=num/i;
 		}
 	}
 	printf("\n");
 }