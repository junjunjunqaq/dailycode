#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

typedef struct student {
	int num;
	char name[20];
	float score[3];
	float aver;
}student;

int main()
{
	student stu[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("�������%d��ѧ������Ϣ��\n", i + 1);
		scanf("%d%s%f%f%f", &stu[i].num, stu[i].name,
			&stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
		stu[i].aver = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3;
	}
	for (i = 0; i < 10; i++)
	{
		printf("��%d��ѧ����ƽ����Ϊ��%5.2f\n", i + 1, stu[i].aver);

	}
	student max (student stu[]);
	max(stu);
	void print(student stu);
	print( max(stu) );

	return 0;
}
student max(student stu[])
{
	int i, pointer;
	float temp = 0, max = 0;

	for (i = 0; i < 10; i++)
	{

		if (stu[i].score[0] > stu[i].score[1])
			temp = stu[i].score[0];
		else temp = stu[i].score[1];
		if (stu[i].score[2] > temp)
			temp = stu[i].score[2];

		if (temp > max) {
			max = temp;
			pointer = i;
		}
	}
	return stu[pointer];
}

void print(student stu)
{
	printf("��߷�ѧ���ǣ�\n");
	printf("ѧ�ţ�%d\n������%s\n���ſγɼ���%5.2f %5.2f %5.2f\nƽ��������%5.2f",
		stu.num, stu.name,
		stu.score[0], stu.score[1], stu.score[2], stu.aver);
}
