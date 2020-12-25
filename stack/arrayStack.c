#include <stdio.h>
#include <stdlib.h>
# define MAX 10
int top=-1;
int stackArray[MAX];
void push(int item);
int pop();
int peek();
int isEmpty();
int isFull();
void display();
int main()
{
	int choice,element;
	while(1)
	{
		system("clear");
		printf("1.Insert element\n");
		printf("2.Delete element\n");
		printf("3.Display the top of element\n");
		printf("4.Display All element\n");
		printf("5.exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
         switch(choice)
         {
         	case 1:
         	       printf("Enter the element to be inserted:");
         	       scanf("%d",&element);
         	       push(element);
         	       break;
            case 2:
                   element=pop();
                   printf("Deleted element is %d:\n",element);
                   getchar();
                   getchar();
                   break;
            case 3:
                   element=peek();
                   printf("Element at top is: % d\n",element);
                   getchar();
                   getchar();
                   break;
            case 4:
                    display();
                    break;
            case 5:
                    exit(1);
            default:
                    printf("wrong choice\n");
             getchar();
             getchar();


         }

	}
	return 0;
}
void push(int item)
{
	if(isFull())
	{
		printf("Stack is overflow:\n");
		getchar();
		getchar()
		return;
	}
	top++;
	stackArray[top]=item;
}
int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int isFull()
{
	if(top==MAX-1)
		return 1;
	else
		return 0;
}
int pop()
{
	int item;
	if(isEmpty())
	{
		printf("Stack is underflow\n");
		exit(1);
	}
    item=stackArray[top];
    top--;
    return item;
}
int peek()
{
	if(isEmpty())
	{
		printf("Stack is underflow\n");
		exit(1);
	}
	return stackArray[top];
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("Stack is empty");
		getchar();
		getchar();
		return;
	}
	printf("Stack element is:");
	for(i=top;i>=0;i--)
	{
		printf("%d ",stackArray[i]);
	}
	printf("\n");
	getchar();
	getchar();
}