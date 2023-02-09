#include<stdio.h>
int main()
{
	int a[3][3];
	int (*p)[3];
	p=a;
	int i,j;
	printf("请输入一个3x3的整型矩阵：\n");
	for(i=0;i<3;i++)
	{
	
		for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
		}
	void exchange(int (*p)[3]);
	exchange(p);
	printf("转置后的矩阵为：\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%d ",a[i][j]);
			printf("\n");
		}
	return 0;
} 

	void exchange(int (*p)[3])
	{
		int temp;
		int j;
		
		for(j=1;j<3;j++)
			{
				temp=*(*(p+0)+j);
				*(*(p+0)+j)=*(*(p+j)+0);
				*(*(p+j)+0)=temp;
			}
			
		while(1)
		{
			     temp=*(*(p+1)+2);
				*(*(p+1)+2)=*(*(p+2)+1);
				*(*(p+2)+1)=temp;
				break;
		}
	}
	
	
