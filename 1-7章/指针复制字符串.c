#include<stdio.h>
int main()
{
	char a[100],b[100]; 
	int m,n;
	char *p;
	p=a;
	printf("请输入n个字符：");
	gets(a);
	printf("请输入n的值：");
	scanf("%d",&n);
	printf("\n请输入m的值：");
	scanf("%d",&m);
	void copy(char *x,char y[],int g,int h);
	copy(p,b,m,n);
	printf("%s",b);
	return 0;
}

	void copy(char *x,char y[],int g,int h)
{	
	char *i,*j;
	i=x+g-1;
	j=y;
	for(;i<x+h;i++)
	{
	*j=*i;	
	j++;
	}
	*j='\0';
}
