#include<stdio.h>
int main()
{
	int a[11];
	printf("请输入10个整数：");
	int *p=a;
	int *j=a;
	for(p=a+1;p<a+11;p++)
		scanf("%d",p);

	for(p=a+2;p<a+11;p++)
	{
		if(*p<*(p-1))
		{
			*a=*p;
			for(j=p-1;*j>*a;j--)
			{
				*(j+1)=*j;
			}	
		
			*(j+1)=*a;
		}
	}
	
	
	printf("排序后的10个整数为：");
	for(p=a+1;p<a+11;p++)
		printf("%d ",*p); 

	return 0;
}
