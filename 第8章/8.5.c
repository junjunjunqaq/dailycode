#include<stdio.h>
void main()
{
	int a[100];
	int sum = 0;
	int left= 0;
	int count = 0;
	int i;
	printf("请输入总人数："); 
	scanf("%d", &sum);

	for ( i = 0; i < sum; i++)
	{
		a[i] = i + 1;
	}

	left = sum;
	do
	{
		int *p= a;
		while (p<a+sum)
		{
			if (*p!=0)
			{
				count++;
				if (count==3)
				{
					*p=0;
					count = 1;
					left--;
				}
			}
			p++;
		}
	}while(left>1);

	for ( i = 0; i < sum; i++)
	{
		if (a[i]!=0)
		{
			printf("最后留下来的是 %d号", a[i]);
			break;
		}
	}
}

