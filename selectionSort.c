#include <stdio.h>
#include <stdlib.h>
# define MAX 30
int *insertElement(int a[],int n);
void displayArray(int a[],int n);
int *selectionSort(int a[],int n);
int *bubbleSort(int a[],int n);
int *insertionSort(int a[],int n);
int *shellSort(int a[],int n);
void mergeSort(int a1[],int a2[],int a3[],int n1,int n2);
void quickSort(int a[],int low,int up);
int partition(int a[],int low,int up);
int main()
{
	int arr[MAX],i,n,*ptr,choice,n1,n2,a1[MAX],a2[MAX],a3[2*MAX];
	while(1)
	{
		system("clear");
		printf("1.selectionSort\n");
		printf("2.Bubble sort\n");
		printf("3.Insertion sort\n");
		printf("4.shell sort\n");
		printf("5.Merge sort\n");
		printf("6.Quick sort\n");
		printf("7.Binary Tree sort\n");
		printf("8.Heap sort\n");
		printf("9.Radix sort\n");
		printf("10.Exit\n");
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:   
			       printf("enter the number of elements:");
			       scanf("%d",&n);
			       ptr=insertElement(arr,n);
			       ptr=selectionSort(arr,n);
	               printf("After sorting Array is:");
	               displayArray(ptr,n);
	               //for(i=0;i<n;i++)
		           //printf("%d ",*(ptr+i));
	               //printf("\n");
	               break;
	         case 2:
	                printf("enter the number of elements:");
			        scanf("%d",&n);
	                ptr=insertElement(arr,n);
	                ptr=bubbleSort(arr,n);
	                printf("After sorting Array is:");
	                displayArray(ptr,n);
	                break;
	         case 3:
	                printf("enter the number of elements:");
			        scanf("%d",&n);
			        ptr=insertElement(arr,n);
			        ptr=insertionSort(arr,n);
			        printf("After sorting Array is:");
	                displayArray(ptr,n);
	                break;
	        case 4:
	                printf("enter the number of elements:");
			        scanf("%d",&n);
			        ptr=insertElement(arr,n);
			        ptr=shellSort(arr,n);
			        printf("After sorting Array is:");
	                displayArray(ptr,n);
	                break;
	        case 5:
	               printf("Enter the number of elements in first array:");
	               scanf("%d",&n1);
	               printf("Enter the elements of first array in sorted manner:\n");
	                 for(i=0;i<n1;i++)
	                 	  scanf("%d",&a1[i]);
	               printf("Enter the number of elements in 2nd array:");
	               scanf("%d",&n2);
	               printf("Enter the elements of first array in sorted manner:\n");
	                 for(i=0;i<n2;i++)
	                 	  scanf("%d",&a2[i]);
	                 	mergeSort(a1,a2,a3,n1,n2);
	                 	break;
	        case 6:
	               printf("Enter the number of elements:");
	               scanf("%d",&n);
	               for(i=0;i<n;i++)
	               {
	               printf("Enter the %d elements:",i+1);
	               scanf("%d",&arr[i]);
	               } 
	               quickSort(arr,0,n-1);
	               printf("After sortint Array is:");
	                for(i=0;i<n;i++)
	                   {
	                   	printf("%d ",arr[i]);
	                   } 
	                   getchar();
	                   getchar();
	                   break;       	
	          case 10:
	                   exit(1);
	           default:
	             printf("wrong choice");
	             getchar();
	             getchar();


		}
	}
	return 0;
}
int *insertElement(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("enter the %d element:",i+1);
		scanf("%d",&a[i]);
	}
	return a;
	getchar();
	getchar();
}
void displayArray(int a[],int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	getchar();
	getchar();
}

int *selectionSort(int a[],int n)
{
	int i,j,temp,start;
    for(i=0;i<n-1;i++)
    {
    	start=a[i];
    	for(j=i+1;j<n;j++)
    	{
    		if(start>a[j])
    		{
    			temp=a[j];
    			a[j]=start;
    			start=temp;
    		}
    	}
    	a[i]=start;
    }
    return a;

}
int *bubbleSort(int a[],int n)
{
	int i,j,xchange,temp;
	for(i=0;i<n-1;i++)
	{
		xchange=0;
		for(j=0;j<n-1-i;j++)
		{
           if(a[j]>a[j+1])
           {
              temp=a[j];
              a[j]=a[j+1];
              a[j+1]=temp;
              xchange++;
           }
		}
		if(xchange==0)
			break;
	}
	return a;
}
int *insertionSort(int a[],int n)
{
	int i,k,j;
	for(i=1;i<n;i++)
	{
       k=a[i];
       for(j=i-1;j>=0 && k<a[j];j--)
       	    a[j+1]=a[j];
       	a[j+1]=k;
	}
	return a;
}
int *shellSort(int a[],int n)
{
	int incr,i,j,k;
	printf("\n Enter maximum increment(odd value):");
	scanf("%d",&incr);
	while(incr>=1)
	{
		for(i=incr;i<n;i++)
		{
			k=a[i];
			for(j=i-incr;j>=0 && k<a[j];j=j-incr)
			    a[j+incr]=a[j];
			   a[j+incr]=k;
		}
		incr=incr-2;
	}
	return a;

}
void mergeSort(int a1[],int a2[],int a3[],int n1,int n2)
{
	int i,j,k;
	i=j=k=0;
	while((i<=n1-1) && (j<=n2-1))
	{
		if(a1[i]< a2[j])
			a3[k++]=a1[i++];
		else
			a3[k++]=a2[j++];
	}
	while(i<=n1-1)
		a3[k++]=a1[i++];
	while(j<=n2-1)
		a3[k++]=a2[j++];
	printf("After sording Array is:");
	 for(i=0;i<(n1+n2);i++)
	 	printf("%d ",a3[i]);
	 getchar();
	 getchar();
}
void quickSort(int a[],int low,int up)
{
	int pivloc;
	if(low>=up)
		return;
    pivloc=partition(a,low,up);
    quickSort(a,low,pivloc-1);
    quickSort(a,pivloc+1,up);
}
int partition(int a[],int low,int up)
{
	int temp,i,j,pivot;
	i=low+1;
	j=up;
	pivot=a[low];
	while(i<=j)
	{
		while((a[i]<pivot)&& i<up)
			i++;
		while(a[j]>pivot)
			j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		else
			i++;
	}
	a[low]=a[j];
	a[j]=pivot;
	return j;
}