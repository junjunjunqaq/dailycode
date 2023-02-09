#define _CRT_SECURE_NO_WARNINGS 1
# include<stdio.h>
#include<string.h>
int main()
{
	char arr[100];
	int a[100] = { 0 };
	char * p = arr;
	printf("请输入一个字符串：");
	gets(arr);
	void sort(char* p, int  a[100]);
	sort(p, a);
	return 0;
}

void sort(char* p,int a[100])
{
	int i,count = 0;
	while(*p !='\0')
	{
		int flag =1;
		
		if (*p == '-' && *(p + 1) >= '0' && *(p + 1) <= '9')
		{
			flag = -1;
			p++;
		}
		 if (*p >= '0' && *p <= '9')
		{
			int num = 0;
			while (*p >= '0' && *p <= '9')
			{
				num = num * 10 + *p - '0';
				p++;
			}
			a[count++] = flag * num;
		}
		else p++;
		
	}

	printf("有%d个整数\n", count);
	for (i=0;i<count; i++)
	{
		printf("%d ", a[i]);
	}

}