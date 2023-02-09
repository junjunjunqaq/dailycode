#include<stdio.h>
int main()
{
	int a[10];
	printf("请输入10个整数：");
	int *p=a;
	int *j=a;
	for(p=a;p<a+10;p++)
		scanf("%d",p);
/*	p=a+1;
	for(;p<a+11;p++)
	{
		if(*p<*(p-1))
			*a=*p;
		for(j=p-1;*j>*a;j--)
			*(j+1)=*j;
		
		j+1=a;
	}
	printf("排序后的10个整数为：");  */
//	for(p=a+1;p<a+11;p++)
		printf("%d ",*a); 
	
	return 0;
}
