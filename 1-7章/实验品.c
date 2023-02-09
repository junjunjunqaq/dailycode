#include<stdio.h>
#include<string.h>
int main()
{
	char a[3][80];
	int i,j;
	 for(i=0;i<=2;i++)
	 {
	 	gets(a[i]);
	 }
	 for(i=0;i<=2;i++)
	    printf("%s",a[i]);
	return 0;
}
