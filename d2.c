#include <stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *link;
};
struct node *createList(struct node *start);
void displayList(struct node *start);
void count(struct node *start);
void search(struct node *start,int data);
struct node *addAtBeg(struct node *start,int data);
struct node *addAtEnd(struct node *start,int data);
struct node *addAfter(struct node *start,int data,int item);
struct node *addBefore(struct node *start,int data,int item);
struct node *addAtPos(struct node *start,int data,int pos);
struct node *del(struct node *start,int data);
struct node *reverse(struct node *start);
struct node *sortSelection(struct node *start);
struct node *bubbleSort(struct node *start);
struct node *selectionSortByRearrangingLinks(struct node *start);
struct node *bubbleSortByRearrangingLinks(struct node *start);
int main()
{
	struct node *start=NULL;
    int choice,data,item,pos;
    while(1)
    {
        system("clear"); 
        printf("1. Create a list\n");
        printf("2. displayList\n");
        printf("3. count\n");
        printf("4.search\n");
        printf("5. Add to empty list/Add at beginning\n");
        printf("6. Add to end\n");
        printf("7. Add after node\n");
        printf("8. Add before node\n");
        printf("9. Add at position\n");
        printf("10. Delete\n");
        printf("11. Reverse\n");
        printf("12.Sorting by sortSelection sort\n");
        printf("13.Sorting by bubbleSort\n");
        printf("14.selectionSortByRearrangingLinks\n");
        printf("15.bubbleSortByRearrangingLinks\n");
        printf("16.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                   start=createList(start);
                   break;
            case 2:
                   displayList(start);
                   break;
            case 3:
                    count(start);
                    break;
            case 4:
                    //int data;
                    printf("Enter the element do u want to search\n");
                    scanf("%d",&data);
                    search(start,data);
                    break; 
            case 5:
                    //int data;
                    printf("Enter the element do u want to add in empty list/Add at beginning\n");
                    scanf("%d",&data);
                    start=addAtBeg(start,data);
                    break;
            case 6:
                    //int data;
                    printf("Enter the element do u want to add to the end of list\n");
                    scanf("%d",&data);
                    start=addAtEnd(start,data);
                    break; 
            case 7: 
                   printf("Enter the element to be inserted\n");
                   scanf("%d",&data);
                   printf("Enter the element after which to insert\n");
                   scanf("%d",&item);
                   start=addAfter(start,data,item);
                   break;
            case 8: 
                   printf("Enter the element to be inserted\n");
                   scanf("%d",&data);
                   printf("Enter the element before which to insert\n");
                   scanf("%d",&item);
                   start=addBefore(start,data,item);
                   break; 
            case 9: 
                   printf("Enter the element to be inserted\n");
                   scanf("%d",&data);
                   printf("Enter the position to which to insert\n");
                   scanf("%d",&pos);
                   start=addAtPos(start,data,pos);
                   break;                                           
            case 10:
                   printf("Enter the element to be deleted :\n");
                   scanf("%d",&data);
                   start=del(start,data);
                   break;
            case 11:
                    start=reverse(start);
                    break; 
            case 12:
                    start=sortSelection(start);
                    break; 
            case 13:
                      start=bubbleSort(start);
                      break;
            case 14:
                     start=selectionSortByRearrangingLinks(start);
                     break; 
            case 15:
                     start=bubbleSortByRearrangingLinks(start);
                     break;                               
            case 16:
                    exit(1);
             default:
                   printf("Wrong choice");

        }
    }
	
	
	return 0;
}
struct node *createList(struct node *start)
{
	int i,n,data;
	struct node *p,*temp;
    printf("Enter the number of elements:" );
    scanf("%d",&n);
    if(n==0)
    	return start;
    printf("Enter the element:");
    scanf("%d",&data);
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=start;
    p=temp;
    start=temp;
    for (i=2;i<=n;i++)
    {
    	temp=(struct node *)malloc(sizeof(struct node));
    	printf("Enter the element:");
        scanf("%d",&data);
        temp->info=data;
        p->link=temp;
        temp->link=NULL;
        p=temp;

    }
    return start;
}
void displayList(struct node *start)
    {
    	struct node *p,*temp;
    	p=start;
    	if(start==NULL)
    		printf("List is empty\n");
    	else
    	{ 
    		printf("List is:");
    		while(p!=NULL)
    		{
    			printf("%d ",p->info);
    			p=p->link;
    		}
          
         //printf("\n"); 
    	}
      getchar();
      getchar();
    }
    void count(struct node *start)
    {
      struct node *p;
      int count=0;
      p=start;
      while(p!=NULL)
      {
        count++;
        p=p->link;
      }
      printf("Total number of elements in list=%d\n",count);
      getchar();
      getchar();
    }
    void search(struct node *start,int data)
    {
      struct node *p;
      int pos=1;
      p=start;
      while(p!=NULL)
      {
        if(p->info==data)
        {
          printf("Element %d is found at position: %d\n",data,pos);
          getchar();
          getchar();
          return;
        }
        p=p->link;
        pos++;
      }
      printf("Element %d is not found in list\n",data);
      getchar();
      getchar();
    }
    struct node *addAtBeg(struct node *start,int data)
    { 
      struct node * temp;
      temp=(struct node *)malloc(sizeof(struct node));
      temp->info=data;
      temp->link=start;
      start=temp;
      return start;
      
    
    }
    struct node *addAtEnd(struct node *start,int data)
    {
      struct node *p,*temp;
      temp=(struct node *)malloc(sizeof(struct node));
      temp->info=data;
      p=start;
      while(p->link!=NULL)
      {
        p=p->link;
      }
      p->link=temp;
      temp->link=NULL;
      return start;

    }
  struct node *addAfter(struct node *start,int data,int item)
  {
    struct node *p,*temp;
   
    p=start;
    while(p!=NULL)
    {
    if(p->info==item)
    {
      temp=(struct node *)malloc(sizeof(struct node));
      temp->info=data;
      temp->link=p->link;
      p->link=temp;
     return start;
   }
   p=p->link;
 }
  printf("%d not present in the list\n",item);
  return start; 
  }
  struct node *addBefore(struct node *start,int data,int item)
   {
    struct node *p,*temp;
   if(start==NULL)
   {
    printf("List is empty\n:");
    return start;
   }
   if(item==start->info)
   {
      temp=(struct node *)malloc(sizeof(struct node));
      temp->info=data;
      temp->link=start;
      start=temp;
      return start;
   }
    p=start;
    while(p->link!=NULL)
    {
    if(p->link->info==item)
    {
      temp=(struct node *)malloc(sizeof(struct node));
      temp->info=data;
      temp->link=p->link;
      p->link=temp;
     return start;
   }
   p=p->link;
 }
  printf("%d not present in the list\n",item);
  return start;

   }
   struct node *addAtPos(struct node *start,int data,int pos)
    {
      struct node *p,*temp;
      int i;
      temp=(struct node *)malloc(sizeof(struct node));
      temp->info=data;
      if(pos==1)
      {
        temp->link=start;
        start=temp;
        return start;
      }
      p=start;
      for(i=1;i<pos-1 && p!=NULL;i++)
           p=p->link;
         if(p==NULL)
         {
          printf("There are less than %d elements\n",pos );
          getchar();
          getchar();
        }
        else
        {
          temp->link=p->link;
          p->link=temp;
        }
        return start;
    }
   struct node *del(struct node *start,int data)
   {
       struct node *p,*temp;
       if(start==NULL)
       {
        printf("List is empty\n");
        return start;
       }
       if(start->info==data)
       {
         temp=start;
         start=start->link;
         free(temp);
         return start;
       }
       p=start;
       while(p->link!=NULL)
       {
           if(p->link->info==data)
           {
            temp=p->link;
            p->link=temp->link;
            free(temp);
            return start;
           }
           p=p->link;
       }
       printf("element %d is not found\n",data );
       getchar();
       getchar();
       return start;
   }
   struct node *reverse(struct node *start)
   {
     struct node *ptr,*pre,*next;
     ptr=start;
     pre=NULL;
     while(ptr!=NULL)
     {
      next=ptr->link;
      ptr->link=pre;
      pre=ptr;
      ptr=next;
     }
      start=pre;
    return start;
     }
     struct node *sortSelection(struct node *start)
     {
      struct node *p,*q;int temp;
      p=start;
      for(p=start;p->link!=NULL;p=p->link)
      {
        for(q=p->link;q!=NULL;q=q->link)
          if(p->info>q->info)
          {
               temp=p->info;
               p->info=q->info;
               q->info=temp;
          }
      }
      return start;
     }
   struct node *bubbleSort(struct node *start)
   {
    struct node *p,*q,*end;
    int temp;
    for(end=NULL;end!=start->link;end=q)
    {
      for(p=start;p->link!=end;p=p->link)
      {
        q=p->link;
      if(p->info > q->info)
       {
           temp=p->info;
           p->info=q->info;
           q->info=temp;
       }
     }
    }
    return start;
   }
   struct node *selectionSortByRearrangingLinks(struct node *start)
   {
    struct node *p,*q,*temp,*r,*s;
      for(r=p=start;p->link!=NULL;r=p,p=p->link)
      {
        for(s=q=p->link;q!=NULL;s=q,q=q->link)
          if(p->info>q->info)
          {
            temp=p->link;
            p->link=q->link;
            q->link=temp;
            if(p!=start)
               r->link=q;
               s->link=p;
               if(p==start)
                  start=q;
                temp=p;
                p=q;
                q=temp;
          }
      }
      return start;
   }
   struct node *bubbleSortByRearrangingLinks(struct node *start)
   {
    struct node *p,*q,*r,*end,*temp;
    for(end=NULL;end!=start->link;end=q)
    {
      for(r=p=start;p->link!=end;r=p,p=p->link)
      {
           q=p->link;
           if(p->info > q->info)
           {
            p->link=q->link;
            q->link=p;
            if(p!=start)
              r->link=q;
            else
              start=q;
            temp=p;
            p=q;
            q=temp;
           }

      }
    }
    return start;
   }
