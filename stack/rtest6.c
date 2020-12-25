#include <stdio.h>
void tofh(int,char,char,char);
int main()
{
   int ndisk;
   char source='A',temp='B', dest='C';
   printf("Enter the number of disks:");
   scanf("%d",&ndisk);
   printf("sequence is :\n");
   tofh(ndisk,source,temp,dest);
	return 0;
}
void tofh(int ndisk,char source,char temp,char dest)
{
      if(ndisk==1)
      {
      	printf("Move Disk %d from %c----->%c\n",ndisk,source,dest);
      	return;
      }
      tofh(ndisk-1,source,dest,temp);
      printf("Move Disk %d from %c----->%c\n",ndisk,source,dest);
      tofh(ndisk-1,temp,source,dest);
}