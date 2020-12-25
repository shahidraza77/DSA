#include <stdio.h>
#include <string.h>
int rseries(int n);
int main()
{
	/*char str[20];
	int i;
	scanf("%s",str);
	for(i=0;i<strlen(str);i++)
	 {
		if((str[i]<='9') && (str[i]>='0'))
		{
		  printf("%d ",(str[i]-'0'));
		}
     }*/
		int n;
		printf("Enter a number: ");
		scanf("%d",&n);
		printf("shahid");
		printf("\b\b:");
		printf("\b\b=%d\n\n\n",rseries(n));
	return 0;
}
int rseries(int n)
{
	int sum;
	if(n==0)
		return 0;
	sum=n+rseries(n-1);
	printf("%d + ",n);
	return sum;
}