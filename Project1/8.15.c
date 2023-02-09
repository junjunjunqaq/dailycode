#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a[4][5];
	int* p = a;
	int i, j;
	printf("请输入4位学生的5门课的成绩：\n");
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
	printf("第一门课的总分是%f,", sum);
	printf("第一门课的平均分是%f\n", aver);
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
				printf("该生有两门以上课程不及格,学号（0,1,2,3）是%d,", i);
				printf("他的全部课程成绩为%d %d %d %d %d,", *(p + 5 * i + 0), *(p + 5 * i + 1),
					*(p + 5 * i + 2), *(p + 5 * i + 3), *(p + 5 * i + 4));
				float average;
				average = (*(p + 5 * i + 0) + *(p + 5 * i + 1) +
					*(p + 5 * i + 2) + *(p + 5 * i + 3) + *(p + 5 * i + 4)) / 5;
				printf("平均分是%f\n", average);
			
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
				printf("第%d位(1,2,3,4)学生全部课程成绩在85分以上\n", i + 1);
		}
	}
	for (i = 0; i < 4; i++)
	{
		aver = (*(p + 5 * i + 0) + *(p + 5 * i + 1) +
			*(p + 5 * i + 2) + *(p + 5 * i + 3) + *(p + 5 * i + 4)) / 5;
		if (aver > 90)
			printf("第%d位学生平均成绩在90分以上\n", i + 1);
	}
}
