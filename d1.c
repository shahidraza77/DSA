#include <stdio.h>
/*void func(int a[]);
 int main()
{
	
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	func(arr+3);
	return 0;
}
void func(int a[])
 {
 	int i;
 	for ( i = 0; a[i]!=8; ++i)
 	{
 		
 		printf("%d ",a[i]);
 	}
 }*/
 	/*void func(int x,int *y);
 	int  main()
 	{
 		
 		int a=2,b=6;
 		func(a,&b);
 		printf("a=%d, b=%d\n",a,b );
 		return 0;
 	}
 	void func(int x,int *y)
 	{
 		int temp;
 		temp=x;
 		x=*y;
 		*y=temp;
 	}*/

 		int a=5,b=10;
 		void change1(int *p);
 		void change2(int **pp);
 		int main()
 		{
 		    int x=20, *ptr=&x;
 		     int arr[10]={25,30,35,40,55,60,65,70,85,90},*p;
 		     for (p= arr+2; p <arr+8;p=p+2)
 		     {
 		     	/* code */
 		     	printf("%d ",*p );
 		     }
 		    printf("%d ",*ptr );
 		    change1(ptr);
 		    printf("%d ",*ptr );
 		    change2(&ptr);
 		    printf("%d\n",*ptr );
 			return 0;
 		}
 		void change1(int *p)
 		{
 			p=&a;
 		}
 		void change2(int **pp)
 		{
 			*pp=&b;
 		}

