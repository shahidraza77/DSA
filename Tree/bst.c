#include <stdio.h>
#include <stdlib.h>
struct node
{
     struct node *lchild;
     int info;
     struct node *rchild;
};
struct node *search(struct node *ptr,int skey);
struct node *insert(struct node *root,int key);
struct node *del(struct node *root,int dkey);
struct node *case_a(struct node *root,struct node *par,struct node *ptr);
struct node *case_b(struct node *root,struct node *par,struct node *ptr);
struct node *case_c(struct node *root,struct node *par,struct node *ptr);
struct node *Min(struct node *ptr);
struct node *Max(struct node *ptr);
int main()
{
	struct node *root=NULL,*ptr;
	int choice,k;
	while(1)
	{
		system("clear");
		printf("1.search element\n");
		printf("2.insert element\n");
		printf("3.Delete element\n");
		printf("4.Find minimum and maximum\n");
		printf("5.exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
         switch(choice)
         {
         	case 1:
         	       printf("Enter the element to be searched:");
         	       scanf("%d",&k);
         	       ptr=search(root,k);
         	       if(ptr==NULL)
         	       	printf("element is not found:");
         	         else
         	         	printf("element is present");
         	         getchar();
                     getchar();
         	       break;
            case 2:
                   printf("Enter the element to be inserted:");
         	       scanf("%d",&k);
         	       root=insert(root,k);
                   getchar();
                   getchar();
                   break;
            case 3:
                   printf("Enter the element to be deleted:");
                   scanf("%d",&k);
                   root=del(root,k);
                   break;
            case 4:
                    ptr=Min(root);
                    if(ptr!=NULL)
                    	printf("Minimum key is:%d\n",ptr->info);
                    ptr=Max(root);
                    if(ptr!=NULL)
                    	printf("Maximum key is:%d\n",ptr->info);
                    getchar();
                    getchar();
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

struct node *search(struct node *ptr,int skey)
{
	while(ptr!=NULL)
	{
		if(skey<ptr->info)
			ptr=ptr->lchild;
		else if(skey>ptr->info)
			ptr=ptr->rchild;
		else
			return ptr;
	}
	return NULL;
}
struct node *insert(struct node *root,int key)
{
	struct node *ptr,*par,*temp;
	ptr=root;
	par=NULL;
	while(ptr!=NULL)
	{
		par=ptr;
		if(key<ptr->info)
			ptr=ptr->lchild;
		else if(key>ptr->info)
			ptr=ptr->rchild;
		else
		{
			printf("Dublicate key");
			return root;
		}
	}
	temp=(struct node *)malloc(sizeof(struct node));
	temp->lchild=NULL;
	temp->info=key;
	temp->rchild=NULL;
	if(par==NULL)
		return temp;
	else if(key<par->info)
		par->lchild=temp;
	else
		par->rchild=temp;
	return root;
}
struct node *del(struct node *root,int dkey)
{
	struct node *par,*ptr;
	ptr=root;
	par=NULL;
	while(ptr!=NULL)
	{
		if(ptr->info==dkey)
			break;
		if(dkey<ptr->info)
			ptr=ptr->lchild;
		else
			ptr=ptr->rchild;
	}
	if(ptr==NULL)
	{
		printf("Element is not present:");
		getchar();
		getchar();
	}
	else if(ptr->lchild!=NULL && ptr->rchild!=NULL)
		root=case_c(root,par,ptr);
	else if(ptr->lchild!=NULL)
		root=case_b(root,par,ptr);
	else if(ptr->rchild!=NULL)
	        root=case_b(root,par,ptr);
	        else
	        	root=case_a(root,par,ptr);
	        return root;
}
struct node *case_a(struct node *root,struct node *par,struct node *ptr)
{
	if(par==NULL)
		root=NULL;
	else if(ptr==par->lchild)
		par->lchild=NULL;
	else
		par->rchild=NULL;
	free(ptr);
	return root;
}
struct node *case_b(struct node *root,struct node *par,struct node *ptr)
{
	struct node *child;
	if(ptr->lchild!=NULL)
		child=ptr->lchild;
	else if(ptr->rchild!=NULL)
		child=ptr->rchild;
	if(par==NULL)
		root=child;
	else if(ptr==par->lchild)
		par->lchild=child;
	else
		par->rchild=child;
	free(ptr);
	return root;
}
struct node *case_c(struct node *root,struct node *par,struct node *ptr)
{
	struct node *succ,*parsucc;
	parsucc=ptr;
	succ=ptr->rchild;
	while(succ->lchild!=NULL)
	{
		parsucc=succ;
		succ=succ->lchild;
	}
	ptr->info=succ->info;
	if(succ->lchild==NULL && succ->rchild==NULL)
		root=case_a(root,parsucc,succ);
	else
		root=case_b(root,parsucc,succ);
	return root;
}
struct node *Min(struct node *ptr)
{
     if(ptr!=NULL)
     	while(ptr->lchild!=NULL)
     		ptr=ptr->lchild;
     	return ptr;
}
struct node *Max(struct node *ptr)
{
     if(ptr!=NULL)
     	while(ptr->rchild!=NULL)
     		ptr=ptr->rchild;
     	return ptr;
}