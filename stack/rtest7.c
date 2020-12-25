#include <stdio.h>
int length(char *str);
void display(char *str);
void rdisplay(char *str);
int main()
{
	char str[15];
	int len;
	printf("enter a string:");
	scanf("%s",str);
	len=length(str);
	printf("length of string=%d\n",len);
	display(str);
	printf("\n");
	rdisplay(str);
	return 0;
}
int length(char *str)
{
       if(*str=='\0')
       	return 0;
       return (1+length(str+1));
}
void display(char *str)
{
	if(*str=='\0')
		return;
	printf("%c ",*str);
	display(1+str);
}
void rdisplay(char *str)
{
	if(*str=='\0')
		return;
	
	display(1+str);
	printf("%c ",*str);
}