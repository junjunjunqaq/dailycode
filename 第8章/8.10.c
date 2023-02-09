#include<stdio.h>
int main()
{
	int a[5][5];
	int i,j;
	int (*p)[5]=a;
	printf("请输入一个5x5的矩阵：\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
			scanf("%d",&a[i][j]);
		}
	void exchange(int (*p)[5],int a[][5]);
	exchange(p,a);
	printf("排序后的矩阵为：\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
			printf("%d ",a[i][j]);
			printf("\n");
		}
	return 0;
 } 

	void exchange (int (*p)[5],int a[][5])
	{
		int *max,*min,*min2,*min3,*min4;
		max=min=min2=min3=min4=p; 
		int i,j;
		for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(*(*(p+i)+j)>*max)
			{
				max=*(p+i)+j;
			}
			
			if(*(*(p+i)+j)<*min)
			{
				min=*(p+i)+j;
			}
			
		}
	} 

	
	for(i=0;i<5;i++)  //第二小的元素 
	{
		for(j=0;j<5;j++)
		{
			if(*(*(p+i)+j)<*min2 && *(*(p+i)+j)>*min)
			{
				min2=*(p+i)+j;
			}			
		}
	} 
 
	
	for(i=0;i<5;i++)  //第三小的元素 
	{
		for(j=0;j<5;j++)
		{
			if(*(*(p+i)+j)<*min3 && *(*(p+i)+j)>*min2)
			{
				min3=*(p+i)+j;
			}			
		}
	} 
	
	for(i=0;i<5;i++)  //第四小的元素 
	{
		for(j=0;j<5;j++)
		{
			if(*(*(p+i)+j)<*min4 && *(*(p+i)+j)>*min3)
			{
				min4=*(p+i)+j;
			}			
		}
	} 
	printf("max=%d\n",*max);
	printf("min1=%d\n",*min);
	printf("min2=%d\n",*min2);
	printf("min3=%d\n",*min3);
	printf("min4=%d\n",*min4);

	int temp;
		temp=*max;
		*max=a[2][2];
		a[2][2]=temp;
		
		temp=*min;
		*min=a[0][0];
		a[0][0]=temp; 
		
		temp=*min2;
		*min2=a[0][4];
		a[0][4]=temp; 
		
		temp=*min3;
		*min3=a[4][0];
		a[4][0]=temp;
		
		temp=*min4;
		*min4=a[4][4];
		a[4][4]=temp; 
	}
	
