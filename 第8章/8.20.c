#include<stdio.h>
#include<string.h>
int main()
{
	char *a[5];
	char *p=a;
	int i,j;
	for(i=0;i<5;i++)
	{
		printf("请输入第%d个字符串:",i+1);
		gets(a[i]);
		printf("%s",a[i]);
	}
	for(i=0;i<4;i++)
		for(j=0;j<4-i;j++)
		{
			if(strcmp(a[j],a[j+1])>0)
			{
			char *temp;
			*temp=*a[j];
			*a[j]=*a[j+1];
			*a[j+1]=*temp;	
			}
			
		}
	for(p=a;p<a+5;p++)
	{
		puts(*p);
	}
	return 0;
 } 
