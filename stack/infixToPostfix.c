#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50
void push(long int symbol);
long int pop();
void infixToPosfix();
char infix[MAX];
char postfix[MAX];
char stack[MAX];
int top=-1;
int priority(char symbol);
long int evaluate();
int isEmpty();
int main()
{
	long int value;
	printf("Enter infix expression:");
	scanf("%s",infix);
	infixToPosfix();
	printf("postfix:%s\n",postfix);
	value=evaluate();
	printf("value of expression=%ld\n",value);
	return 0;
}
void infixToPosfix()
{
	int i,p=0;
	char symbol,next;
	for(i=0;i<strlen(infix);i++)
	{
         symbol=infix[i];
         if(symbol!=' ' || symbol!='\t')
         {
         	switch(symbol)
         	{
         		case '(':
         			push(symbol);
         			break;
         	    case ')':
         	    while((next=pop())!='(')
         	    postfix[p++]=next;
         	    break;
         	    case '+':
         	    case '-':
         	    case '*':
         	    case '/':
         	    case '%':
         	    case '^':
         	    while(!isEmpty() && priority(stack[top])>=priority(symbol))
         	         postfix[p++]=pop();
         	         push(symbol);
         	         break;
         	     default:
         	     postfix[p++]=symbol;		
         	}
         }
	}
	while(!isEmpty())
		postfix[p++]=pop();
	    postfix[p]='\0';
}
void push(long int symbol)
{
	
	if(top==MAX-1)
	{
		printf("stack overflow\n");
		exit(1);
	}
	stack[++top]=symbol;

}
long int pop()
{
	if(isEmpty())
	{
		printf("Stack underflow\n");
		exit(1);
	}
	return stack[top--];
}
int priority(char symbol)
{
	   switch(symbol)
	   {
	   	case '(':
	   		     return 0;
	   	case '+':
	   	case '-':
	   		     return 1;
        case '*':
        case '/':
        case '%':
                 return 2;
        case '^':
                 return 3;
        default:
                 return 0;

	   }
		return 0;
}
long int evaluate()
{
	long int a,b,temp,result;
	unsigned int i;
	for(i=0;i<strlen(postfix);i++)
	{
		if(postfix[i]<='9' && postfix[i]>='0')
			push((postfix[i]-'0'));
		else
		{
            a=pop();
            b=pop();
            switch(postfix[i])
            {
            	case '+':
            	       temp=b+a;break;
            	case '-':
            	       temp=b-a;break;
            	case '*':
            	       temp=b*a;break;
            	case '/':
            	       temp=b/a;break;
                case '%':
            	       temp=b%a;break;
                case '^':
            	       temp=pow(b,a);break;

            }
            push(temp);
		}
	}
	result=pop();
	return result;
}
int isEmpty()
{
	if(top==-1)
	{
		return 1;
	}
	else
		return 0;

}