#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n,i;
	float a[50];
	float * p = a;
	printf("������n��n<=50����ֵ��");
	scanf("%d", &n);
	printf("������n������");
	for (i = 0; i < n; i++)
	{
		scanf("%f", &a[i]);

	}
	void sort(int n, float *p);
	sort(n, p);
	printf("�������к����Ϊ��\n");
	for (i = 0; i < n; i++)
	{
		printf("%f ", a[i]);

	}
	return 0;
}

void sort(int n, float *p)
{

	float * i, *j,temp;
	int m;
	i = p;  j = p + n - 1;
	for (m=0;m<n/2;m++)
	{
		temp = *i;
		*i = *j;
		*j = temp;
		j--; i++;
	}

}