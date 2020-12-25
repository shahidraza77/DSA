#include <stdio.h>
#include <stdlib.h>
struct node{
	float coef;
	int expo;
	struct node *link;
};
struct node *create(struct node *start);
struct node *insert_s(struct node *start,float coef,int expo);
void display(struct node *start);
void polyAdd(struct node *p1,struct node *p2);
void polyMult(struct node *,struct node *);
struct node *insert(struct node *start,float coef,int expo);


int main()
{
	struct node *start1=NULL,*start2=NULL;
	printf("Enter polynomial 1:\n");start1=create(start1);
	printf("Enter polynomial 2:\n");start2=create(start2);
	printf("polynomial 1 is: ");display(start1);
	printf("polynomial 2 is: ");display(start2);
	polyAdd(start1,start2);
	polyMult(start1,start2);
	return 0;
}
   struct node *create(struct node *start)
   {
	int n,i,expo;
	float coef;
	printf("Enter the number of terms:");
	scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    	printf("Enter the coeficient for term %d:",i);
    	scanf("%f",&coef);
    	printf("Enter the exponent for term %d:",i);
    	scanf("%d",&expo);
        start=insert_s(start,coef,expo);

    }
    return start;
	
}
struct node *insert_s(struct node *start,float coef,int expo)
{
	struct node *temp,*ptr;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->coef=coef;
	temp->expo=expo;
	if(start==NULL || start->expo < expo)
	{
        temp->link=start;
        start=temp;
        return start;
	}
	else
	{
      ptr=start;
      while(ptr->link!=NULL && ptr->link->expo >=expo)
      	ptr=ptr->link;
        temp->link=ptr->link;
        ptr->link=temp;
	}
	return start;
}
void display(struct node *start)
{
	struct node *ptr;
     if(start==NULL)
     {
     	printf("zero polynomial\n");
     	return;
     }
   ptr=start;
   while(ptr!=NULL)
   {
   	printf("(%.1fx^%d)",ptr->coef,ptr->expo);
   	ptr=ptr->link;
   	if(ptr!=NULL)
   		printf(" + ");
   	else
   		printf("\n");
   }
}
void polyAdd(struct node *p1,struct node *p2)
{
	struct node *start3=NULL;
	while(p1!=NULL && p2!=NULL)
	{
	  if(p1->expo >p2->expo)
	 {
        start3=insert(start3,p1->coef,p1->expo);
        p1=p1->link;
	 }
	 else if(p2->expo >p1->expo)
	 {
        start3=insert(start3,p2->coef,p2->expo);
        p2=p2->link;
	 }
	 else if(p1->expo == p2->expo)
	 {
        start3=insert(start3,(p1->coef+p2->coef),p1->expo);
        printf("%f",p1->coef+p2->coef );
        printf("shahid");
        p1=p1->link;
        p2=p2->link;
	 }
	 while(p1!=NULL)
	 {
	 	start3=insert(start3,p1->coef,p1->expo);
        p1=p1->link;
	 }
	 while(p2!=NULL)
	 {
	 	start3=insert(start3,p2->coef,p2->expo);
        p2=p2->link;
	 }
	 printf("Added polynomial is:");display(start3);
}
}
struct node *insert(struct node *start,float coef,int expo)
{
	struct node *temp,*ptr;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->coef=coef;
	temp->expo=expo;
	if(start==NULL)
	{
		temp->link=start;
		start=temp;
	}
	else
	{
		ptr=start;
		while(ptr->link!=NULL)
			ptr=ptr->link;
		temp->link=ptr->link;
		ptr->link=temp;
	}
	return start;
}
void polyMult(struct node *p1,struct node *p2)
{
   struct node *start3;
   struct node *p2_beg=p2;
   start3=NULL;
   if(p1==NULL || p2==NULL)
   {
   	printf("Multiplied polynomial is zero\n");
   	return ;
   }
   while(p1!=NULL)
   {
   	p2=p2_beg;
   	while(p2!=NULL)
   	{
   		start3=insert_s(start3,p1->coef*p2->coef,p1->expo+p2->expo);
   		p2=p2->link;
   	}
   	p1=p1->link;
   }
   printf("Multiplied polynomial is: ");display(start3);
}