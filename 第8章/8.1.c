//1.输入三个整数，按从小到大的顺序输出。
#include<stdio.h>
int main()
{
	int a,b,c;
	int temp;
	int *i,*j,*k;
	i=&a;j=&b;k=&c;
	printf("请输入3个整数：");
	scanf("%d%d%d",i,j,k);
	if(a>b)
	{
		temp=*i;
		*i=*j;
		*j=temp;	
	}
	if(a>c)
	{
		temp=*i;
		*i=*k;
		*k=temp;	
	}
	if(b>c)
	{
		temp=*j;
		*j=*k;
		*k=temp;	
	}
	printf("三个整数从小到大排序后为：%d %d %d",*i,*j,*k);
	return 0;
}
