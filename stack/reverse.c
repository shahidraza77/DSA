#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
int top=-1;
void push(char);
char pop();
char stack[MAX];
int main()
{
	char str[20];
	int i;
	printf("Enter the string: ");
	scanf("%s",str); 
	for(i=0;i<strlen(str);i++)
		 push(str[i]);
	for(i=0;i<strlen(str);i++)
		 str[i]=pop();
	printf("Reverse string is:");
	 puts(str);
	return 0;
}
void push(char ch)
{
	if(top==MAX-1)
	{
		printf("stack overflow\n");
		exit(1);
	}
	stack[++top]=ch;
}
char pop()
{
	if(top==-1)
	{
		printf("stack underflow\n");
		exit(1);
	}
	return stack[top--];
}