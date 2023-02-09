/*3.输入十个整数，将其中最小的数与第一个数对换，把最大的数与最后一个数对换。

写三个函数：1、输入十个数；2、进行处理；3、输出十个数*/
#include<stdio.h>
int main()
{
	int a[10];
	int *p=a;
	void input(int a[],int *p);
	void swap(int a[],int *p);
	void output(int a[],int *p);
	input(a,*p);
	swap(a,*p);
	output(a,*p);
	return 0;
}

void input(int a[],int *p)
{
	printf("请输入10个整数：");
	int i;
	for(i=0;i<10;i++)
		scanf("%d",p);
	
}

void swap(int a[],int *p)
{
	
	
}

void output(int a[],int *p)
{
	
	
}
