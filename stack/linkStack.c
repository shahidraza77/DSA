#include <stdio.h>
#include <stdlib.h>
struct node
{
   int info;
   struct node *link;
};
struct node * top=NULL;
void push(int item);
int pop();
int peek();
int isEmpty();
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
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("stack is overflow\n");
		getchar();
		getchar();
		return;
	}
	temp->info=item;
	temp->link=top;
	top=temp;
}
int pop()
{
	int item;
	if(isEmpty())
	{
		printf("stack is underflow\n");
		getchar();
		getchar();
		exit(1);
	}
	struct node *temp;
	temp=top;
	item=top->info;
	top=top->link;
	free(temp);
	return item;
}
int peek()
{
	
	if(isEmpty())
	{
		printf("stack is underflow\n");
		getchar();
		getchar();
		exit(1);
	}
	return top->info;
}
int isEmpty()
{
	if(top==NULL)
		return 1;
	else 
		return 0;
}
void display()
{
	if(isEmpty())
	{
		printf("stack is underflow\n");
		getchar();
		getchar();
		return;
	}
	struct node *ptr;
	ptr=top;
	printf("stack element is: ");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		ptr=ptr->link;
	}
	printf("\n");
    getchar();
    getchar();
}