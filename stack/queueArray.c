#include <stdio.h>
#include <stdlib.h>
# define MAX 10
int front=-1;
int rear=-1;
int queueArray[MAX];
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
		printf("Queue overflow\n");
		getchar();
		getchar();
		return;
	}
	if(front==-1)
		front=0;
	rear=rear+1;
	queueArray[rear]=item;
}
int del()
{
	int item;
	if(isEmpty())
	{
		printf("Queue underflow\n");
		getchar();
		getchar();
		exit(1);
	}
    item=queueArray[front];
    front++;
    return item;
}
int peek()
{
	if(isEmpty())
	{
		printf("Queue underflow\n");
		getchar();
		getchar();
		exit(1);
	}
	return queueArray[front];
}
int isFull()
{
    if(rear==MAX-1)
    	return 1;
    else
    	return 0;
}
int isEmpty()
{
	if(front==rear+1 || front==-1)
		return 1;
	else
		return 0;
}
void display()
{
	int i;
	if(isEmpty())
	{
		printf("Queue underflow\n");
		getchar();
		getchar();
		exit(1);
	}
	printf("Queue element is: ");
    for(i=front;i<=rear;i++)
    	printf("%d ",queueArray[i]);
    printf("\n");
    getchar();
    getchar();
}