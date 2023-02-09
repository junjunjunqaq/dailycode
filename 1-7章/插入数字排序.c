#include<stdio.h>
int main()
{
	int a[11];
	int i,j,t,p;
	t=p=0;
	
	printf("请输入10个整数：");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
    
	for(i=0;i<9;i++)
	   for(j=0;j<9-i;j++)
	{
		if(a[j]>a[j+1])
		{
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		}
	}
	printf("\n排序后的数组为：");
	for(i=0;i<10;i++)
	   printf("%d ",a[i]); 
	   
	printf("\n请再输入一个整数：");
	scanf("%d",&a[10]);
	
	for(i=0;i<10;i++)
	   for(j=0;j<10-i;j++)
	{
		if(a[j]>a[j+1])
		{
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		}
	}
	
	
	printf("\n重新排序后的数组为：");
	for(i=0;i<11;i++)
	   printf("%d ",a[i]); 
	return 0;
}
