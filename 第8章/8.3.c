/*3.����ʮ����������������С�������һ�����Ի����������������һ�����Ի���

д����������1������ʮ������2�����д���3�����ʮ����*/
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
	printf("������10��������");
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
