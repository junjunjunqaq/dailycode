#include<stdio.h>
int main()
{
	int m,n;
	int i;	
	printf("请输入n的值：");
	scanf("%d",&n);
	int a[50];
	int *p=a;
	printf("%p\t", p);
	printf("%p\n", p + n);
	printf("请输入m的值：");
	scanf("%d",&m);
	printf("请输入n个整数：");
	for(p=a;p<a+n;p++){
		scanf("%d",p);
	}
		

	printf("%d\n", a[0]);
	void change(int *x,int g,int h);
	printf("%d\n", a[0]);
	p=a;
	change(p,m,n);
	p=a;
	for(;p<a+n;p++)
		printf("%d ",*p); 	 
	return 0;
}

	void change(int *arr,int m,int n)
	{
		int temp;
		int i;
		int *end,*start;
		end=arr+n-1;
		start=arr;
		for(i=0;i<m;i++)
			{
				temp=*end;
				while(start < end)
				{
					*(start+1) = *start;
					start++;
				}
				*arr=temp;
				start = arr;
			}
		
	}
