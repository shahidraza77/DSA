#include <stdio.h>
#include <stdlib.h>
struct node
{
	int priority;
	int info;
	struct node *link;
}*front=NULL;
void insertElement(int priority,int info);
int delete();
int isEmpty();
void display();
int main()
{
	int item,priority,choice;
	while(1)
	{
		system("clear");
		printf("1.Insert element\n");
		printf("2.Delete element\n");
		printf("3.Display all elements\n");
		printf("4. exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			       printf("Enter the priority of element: ");
			       scanf("%d",&priority);
			       printf("Enter the element: ");
			       scanf("%d",&item);
			       insertElement(priority,item);
			       break;
			case 2:
			       item=delete();
			       printf("Deleted item is :%d",item);
			       getchar();
                    getchar();
			       break;
			case 3:
			        display();
			        break;
            case 4:
                    exit(1);
			default:
                    printf("wrong choice\n");

               getchar();
               getchar();


		}
	}
	return 0;
}
void insertElement(int priority,int info)
{
	struct node *temp,*ptr;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Memory is not available\n");
		getchar();
		getchar();
		return;
	}
	temp->priority=priority;
	temp->info=info;
     if(isEmpty() || front->priority>priority)
     {
     	temp->link=front;
     	front=temp;
     }
     else
     {
       ptr=front;
       while(ptr->link!=NULL && ptr->link->priority<=priority)
       	   ptr=ptr->link;
       	temp->link=ptr->link;
       	ptr->link=temp;
     }

}
int isEmpty()
{
	if(front==NULL)
		return 1;
	else 
		return 0;
}
int delete()
{
	int item;
	struct node * temp;
	if(isEmpty())
	{
		printf("PQueue underflow\n");
		exit(1);
	}
	else
	{
	temp=front;
	item=front->info;
	front=front->link;
	free(temp);
    }
	return item;
}
void display()
{
	struct node *ptr;
	if(isEmpty())
	{
		printf("PQueue underflow\n");
		getchar();
		getchar();
		exit(1);
		return;
	}
	else
	{
		   ptr=front;
			printf("Queue is :\n");
			printf("priority     Item\n");
		while(ptr!=NULL)
		{
         printf("%5d      %5d\n",ptr->priority,ptr->info);
         ptr=ptr->link;
		}
		     getchar();
             getchar();
	}
}
