#include <stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};
struct node *createList(struct node *start);
struct node *insert_s(struct node *start,int data);
void displayList(struct node *start);
void merge(struct node *start1,struct node *start2);
struct node *insert(struct node *start,int data);
int main()
{
	struct node *start1,*start2,*start3;
	start1=NULL;start2=NULL;
	start1=createList(start1);
	start2=createList(start2);
	printf("List1 is: ");displayList(start1);
	printf("List2 is: ");displayList(start2);
	merge(start1,start2);
	//printf("After merging list is:");
	return 0;
}
void merge(struct node *start1,struct node *start2)
{
	struct node *start3,*p1,*p2;
	    start3=NULL;
	    p1=start1;
	    p2=start2;
	    while(p1!=NULL && p2!=NULL)
	    {
	    if(p1->info<p2->info)
	    {
	    	start3=insert(start3,p1->info);
	    	p1=p1->link;
	    }
	    else if(p2->info<p1->info)
	    {
	    	start3=insert(start3,p2->info);
	    	p2=p2->link;
	    }
	    else if(p1->info==p2->info)
	    {
	    	start3=insert(start3,p1->info);
	    	p1=p1->link;
	    	p2=p2->link;
	    }
	}
	while(p1!=NULL)
	{
		start3=insert(start3,p1->info);
		p1=p1->link;
	}
	while(p2!=NULL)
	{
		start3=insert(start3,p2->info);
		p2=p2->link;
	}
     printf("Merge list is:");
     displayList(start3);
}
struct node *insert(struct node *start,int data)
{
	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
    if(start==NULL)
    {
        temp->link=start;
        start=temp;
        return start;
    }
    else
    {
    	p=start;
    	while(p->link!=NULL && p->link->info<data)
    		p=p->link;
    	temp->link=p->link;
    	p->link=temp;
    }
    return start;
}
struct node *createList(struct node *start)
{
	//struct node *p,*temp;
	int i,data,n;
	printf("Enter the number of elements to be inserted:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		//temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter the %d Element:",i);
		scanf("%d",&data);
		start=insert_s(start,data);
		//temp->info=data;

	}
  return start;
}
struct node *insert_s(struct node *start,int data)
{
	struct node *p,*temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
     if(start==NULL || data< start->info)
     {
     	temp->link=start;
     	start=temp;
     	return start;
     }
     else
     {
     	p=start;
     	while(p->link!=NULL && p->link->info<data)
     		p=p->link;
     	temp->link=p->link;
     	p->link=temp;
     }
     return start;
}
void displayList(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is empty");
		return;
	}
	p=start;
      while(p!=NULL)
      {
      	printf("%d ",p->info);
      	p=p->link;
      }
      printf("\n");
}