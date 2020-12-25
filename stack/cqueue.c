#include <stdio.h>
#include <stdlib.h>
# define MAX 10
int front=-1;
int rear=-1;
int cqueueArray[MAX];
void insert(int item);
int del();
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
         	       insert(element);
         	       break;
            case 2:
                   element=del();
                   printf("Deleted element is %d:\n",element);
                   getchar();
                   getchar();
                   break;
            case 3:
                   element=peek();
                   printf("Element at front is: % d\n",element);
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
void insert(int item)
{
	if(isFull())
	{
		printf("CQueue overflow\n");
		getchar();
		getchar();
		return;
	}
	if(front==-1)
		front=0;
	if(rear==MAX-1)
		rear=0;
	else
	rear=rear+1;
	cqueueArray[rear]=item;
}
int del()
{
	int item;
	if(isEmpty())
	{
		printf("CQueue underflow\n");
		getchar();
		getchar();
		exit(1);
	}
    item=cqueueArray[front];
    if(front==rear)
     {
    	 front=-1;
         rear=-1;
     }
     else if(front==MAX-1)
     	front=0;
     else
    front++;
    return item;
}
int peek()
{
	if(isEmpty())
	{
		printf("CQueue underflow\n");
		getchar();
		getchar();
		exit(1);
	}
	return cqueueArray[front];
}
int isFull()
{
    if(front==rear+1 || rear==MAX-1)
    	return 1;
    else
    	return 0;
}
int isEmpty()
{
	if(front==-1)
		return 1;
	else
		return 0;
}
void display()
{
	int i;
	if(isEmpty())
	{
		printf("CQueue underflow\n");
		getchar();
		getchar();
		exit(1);
	}
	printf("CQueue element are: ");
    i=front;
    if(front<=rear)
    {
    	while(i<=rear)
    		printf("%d ",cqueueArray[i++]);
    }
     else
     {
     	while(i<=MAX-1)
     		printf("%d ",cqueueArray[i++]);
     	i=0;
     	while(i<=rear)
     		printf("%d ",cqueueArray[i++]);
     }
    printf("\n");
    getchar();
    getchar();
}