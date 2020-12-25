#include <stdio.h>
#include <stdlib.h>
# define MAX 7
int front=-1;
int rear=-1;
int dqueueArray[MAX];
void insertAtFrontEnd(int item);
void insertAtRearEnd(int item);
int delFromFrontEnd();
int delFromRearEnd();
//int peek();
int isEmpty();
int isFull();
void display();
int main()
{
	int choice,element;
	while(1)
	{
		system("clear");
		printf("1.Insert element at Front end\n");
        printf("2.Insert element at Rear end\n");
		printf("3.Delete element from front end\n");
        printf("4.Delete element from rear end\n");
		//printf("3.Display the top of element\n");
		printf("5.Display All element\n");
		printf("6.exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
         switch(choice)
         {
         	case 1:
         	       printf("Enter the element to be inserted at front end:");
         	       scanf("%d",&element);
         	       insertAtFrontEnd(element);
         	       break;
            case 2:
                   printf("Enter the element to be inserted at rear end:");
                   scanf("%d",&element);
                   insertAtRearEnd(element);
                   break;
            case 3:
                   element=delFromFrontEnd();
                   printf("Deleted element is %d:\n",element);
                   getchar();
                   getchar();
                   break;
            case 4:
                   element=delFromRearEnd();
                   printf("Deleted element is %d:\n",element);
                   getchar();
                   getchar();
                   break;
            case 5:
                    display();
                    break;
            case 6:
                    exit(1);
            default:
                    printf("wrong choice\n");
             getchar();
             getchar();


         }

	}
	return 0;
}
void insertAtFrontEnd(int item)
{
	if(isFull())
	{
		printf("DQueue overflow\n");
		getchar();
		getchar();
		return;
	}
	if(front==-1)
    {
		front=0;
        rear=0;
    }
	else if(front==0)
        front=MAX-1;
      else
      front=front-1;
	dqueueArray[front]=item;
}
void insertAtRearEnd(int item)
{
    if(isFull())
    {
        printf("DQueue overflow\n");
        getchar();
        getchar();
        return;
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else if(rear==MAX-1)
        rear=0;
      else
      rear=rear+1;
    dqueueArray[rear]=item;
}
int delFromFrontEnd()
{
	int item;
	if(isEmpty())
	{
		printf("DQueue underflow\n");
		getchar();
		getchar();
		exit(1);
	}
    item=dqueueArray[front];
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
int delFromRearEnd()
{
    int item;
    if(isEmpty())
    {
        printf("DQueue underflow\n");
        getchar();
        getchar();
        exit(1);
    }
    item=dqueueArray[rear];
    if(front==rear)
     {
         front=-1;
         rear=-1;
     }
     else if(rear==0)
        rear=MAX-1;
     else
    rear--;
    return item;
}
/*
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
}*/
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
		printf("DQueue underflow\n");
		getchar();
		getchar();
		exit(1);
	}
	printf("DQueue element are: ");
    i=front;
    if(front<=rear)
    {
    	while(i<=rear)
    		printf("%d ",dqueueArray[i++]);
    }
     else
     {
     	while(i<=MAX-1)
     		printf("%d ",dqueueArray[i++]);
     	i=0;
     	while(i<=rear)
     		printf("%d ",dqueueArray[i++]);
     }
    printf("\n");
    getchar();
    getchar();
}