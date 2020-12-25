#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 15
void push(char);
char pop();
int check(char str[]);
int match(char a,char b);
int top=-1;
char stack[MAX];
int main()
{
	char str[MAX];
	int valid;
	printf("Enter the expresion\n");
	scanf("%s",str);
	valid=check(str);
	if(valid==1)
		printf("valid expresion\n");
	else
		printf("invalid expresion\n");
	return 0;
}
void push(char ch)
{
	if(top==MAX-1)
	{
		printf("Stack is overflow\n");
		exit(1);
	}
	else
	{
		stack[++top]=ch;
	}
}
char pop()
{
	if(top==-1)
	{
		printf("stack underflow\n");
		exit(1);
	}
	else
		return stack[top--];
}
int check(char str[])
{
	int i;
	char temp;
  for(i=0;i<strlen(str);i++)
	{
		if(str[i]=='(' || str[i]=='{' || str[i]=='[')
			push(str[i]);

			if(str[i]==')' || str[i]=='}' || str[i]==']')
				{
					if(top==-1)
				 {
					printf("Right parentheses are more than left\n");
                    return 0;
				 }
			 else
			 {
                 temp=pop();
				if(!match(temp,str[i]))
				{
					printf("Missmatched parentheses are \n");
					printf("%c and %c",temp,str[i]);
					return 0;
				}
			}
		}
			
   }
          if(top==-1)
			{
				printf("Balanced parentheses\n");
				return 1;
			}   
			else
			{
				printf("Left parentheses are more than right\n");
				return 0;
			}
}
int match(char a,char b)
 {
	if(a=='(' && b==')')
		return 1;
	if(a=='{' && b=='}')
		return 1;
	if(a=='[' && b==']')
		return 1;
	return 0;
}