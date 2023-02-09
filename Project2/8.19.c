#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	
	int cmp(void*, void*);
	double a[10];
	printf("请输入5个整数：");
	for (int i = 0; i < 5; i++)
	{
		scanf("%lf", &a[i]);
	}
	qsort(a, 5, sizeof(a[0]), cmp);
	for (int i = 0; i < 5; i++)
	{
		printf("%lf ", a[i]);
	}
	return 0;
}

int cmp(void* e1, void* e2)
{
	return *((double*)e1) - *((double*)e2);
}

//int main()
//{
//	char a[5][10];
//	printf("请输入5个字符串：");
//	for (int i = 0; i < 5; i++)
//		gets(a[i]);
//	int cmp(void*, void*);
//	qsort(a, sizeof(a) / sizeof(a[0]), sizeof(a[0]), cmp);
//	for (int i = 0; i < 5; i++)
//	{
//		puts(a[i]);
//		
//	}
//}
//
//int cmp(void*e1, void*e2) {
//	return strcmp((char*)e1, (char*)e2);
//}