#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h> 
int main()
{
	int i, n, people[100];
	int count = 0;
	int * p=people;
	printf("������n��ֵ��n<=100):");
	scanf("%d", &n);
	if (n > 100) 
	{	printf("�������࣡");
		return 0;  }
	int left = n;

	for (i = 0; i < n; i++)
	{
		people[i] = i + 1;
	}
	  while (left > 1)
	{
		  p = people;
		for (; p < people + n; p++)
		{
			if ( *p != 0)
				count++;
			if (count == 3)
			{
				*p = 0;
				count = 0;
				left--;
			}
		
		}
	}

	for (i = 0; i < n; i++)
	{
		if(people[i]!=0)
			printf("���ʣ�µ���%d��", people[i]);
	}

	return 0;
}