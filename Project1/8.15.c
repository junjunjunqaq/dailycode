#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a[4][5];
	int* p = a;
	int i, j;
	printf("������4λѧ����5�ſεĳɼ���\n");
	for (i = 0; i < 4; i++)
	{
		 for(j=0;j<5;j++)
			scanf("%d", &a[i][j]);
		
	}

	/*for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}*/

	void aver(int* p);
	aver(p);
	void fail(int* p);
	fail(p);
	void search(int* p);
	search(p);
	return 0;
}

void aver(int* p)
{
	float aver = 0,sum=0;
	int i;
	for (i = 0; i < 4; i++)
	{
		sum += *(p + 5*i);
	}
	aver = sum / 4;
	printf("��һ�ſε��ܷ���%f,", sum);
	printf("��һ�ſε�ƽ������%f\n", aver);
}

void fail(int* p)
{
	int fail = 0;
	int i, j;
	for (i = 0; i < 4; i++)
	{
		fail = 0;
		for (j = 0; j < 5; j++)
		{
			if ( *(p +5*i+j)  < 60)
			{
				fail++;
			}
			if (fail > 2)
			{
				printf("�������������Ͽγ̲�����,ѧ�ţ�0,1,2,3����%d,", i);
				printf("����ȫ���γ̳ɼ�Ϊ%d %d %d %d %d,", *(p + 5 * i + 0), *(p + 5 * i + 1),
					*(p + 5 * i + 2), *(p + 5 * i + 3), *(p + 5 * i + 4));
				float average;
				average = (*(p + 5 * i + 0) + *(p + 5 * i + 1) +
					*(p + 5 * i + 2) + *(p + 5 * i + 3) + *(p + 5 * i + 4)) / 5;
				printf("ƽ������%f\n", average);
			
				break;
			}
			else continue;
			}
	}
}



void search(int* p)
{
	int i, j;
	int score = 0;
	int aver = 0;
	for (i = 0; i < 4; i++)
	{
		score = 0;
		for (j = 0; j < 5; j++)
		{
			if (*(p + 5 * i + j) > 85)
			{
		
				score++;
			}
			if (score == 5)
				printf("��%dλ(1,2,3,4)ѧ��ȫ���γ̳ɼ���85������\n", i + 1);
		}
	}
	for (i = 0; i < 4; i++)
	{
		aver = (*(p + 5 * i + 0) + *(p + 5 * i + 1) +
			*(p + 5 * i + 2) + *(p + 5 * i + 3) + *(p + 5 * i + 4)) / 5;
		if (aver > 90)
			printf("��%dλѧ��ƽ���ɼ���90������\n", i + 1);
	}
}
