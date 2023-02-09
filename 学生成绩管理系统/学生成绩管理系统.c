#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct student {
	char name[20];
	int num;
	int score[3];
}stu[3];

void init() //��ѧ����������
{
	printf("������3��ѧ������Ϣ��\n");
	for (int i = 0; i < 3; i++)
		scanf("%s%d%d%d%d", 
			stu[i].name, &stu[i].num, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
	printf("aaaaa");
	FILE* fp = fopen("stu.dat", "wb");
	if (fp == NULL)
	{
		printf("cannot open file\n");
		return;
	}
	for (int i = 0; i < 3; i++)
		fwrite(&stu[i], sizeof(struct student), 1, fp);
	fclose(fp);
}

int search(int sum, int target)
{
	FILE* fp = fopen("stu.dat", "wb");
	if (fp == NULL)
	{
		printf("cannot open file\n");
		return 0;
	}
	struct student temp[20];
	int num[20];
	for (int i = 0; i < num; i++)
	{
		fread(&temp[i], sizeof(struct student), 1, fp);
		num[i] = temp[i].num;
	}
	int left = 0, right = sum - 1;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (num[mid] < target)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

void add(int sum)
{
	struct student add;
	printf("��������Ҫ��ӵ�ѧ����Ϣ��\n");
	scanf("%s%d%d%d%d", add.name, &add.num, &add.score[0], &add.score[1], &add.score[2]);
	int pos = search(sum, add.num);
	FILE* fp = fopen("stu.dat", "wb");
	if (fp == NULL)
	{
		printf("cannot open file\n");
		return;
	}
	struct student temp[20];
	for (int i = 0; i < sum; i++)
		fread(&temp[i], sizeof(struct student), 1, fp);
	for (int j = sum - 1; j >= pos; j--)
		temp[j + 1] = temp[j];
	temp[pos] = add;
	for(int i = 0; i < sum+ 1; i++)
		fwrite(&temp[i], sizeof(struct student), 1, fp);
	fclose(fp);
}

void delete(int sum, int target) //ѧ��������Ҫɾ��ѧ����ѧ��
{
	FILE* fp = fopen("stu.dat", "wb");
	if (fp == NULL)
	{
		printf("cannot open file\n");
		return;
	}
	struct student temp[20];
	for (int i = 0; i < sum; i++)
		fread(&temp[i], sizeof(struct student), 1, fp);
	int pos = search(sum, target);
	for (int i = pos + 1; i < sum; i++)
		temp[i - 1] = temp[i];
	rewind(fp);
	for (int i = 0; i < sum - 1; i++)
		fwrite(&temp[i], sizeof(struct student), 1, fp);
	fclose(fp);
}

void change(int sum) //�޸�ѧ������ɼ�
{
	printf("������Ҫ�޸�ѧ����ѧ�ţ��ڼ���ɼ�(0,1,2)���޸ĺ�ɼ���\n");
	int num, place,score;
	scanf("%d%d%d", &num, &place, &score);
	FILE* fp = fopen("stu.dat", "wb");
	if (fp == NULL)
	{
		printf("cannot open file\n");
		return;
	}
	struct student temp[20];
	for (int i = 0; i < sum; i++)
		fread(&temp[i], sizeof(struct student), 1, fp);
	int pos = search(sum, num);
	stu[pos].score[place] = score;
	for (int i = 0; i < sum; i++)
		fwrite(&temp[i], sizeof(struct student), 1, fp);
	fclose(fp);
}

int main() 
{
	init();
	add(3);
	change(4);
	delete(4, 105);
	return 0;
}
