#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct student {
	int num;
	char name[20];
	int score[3];
	float aver;
}stu[5];

int main() {
	struct student temp;
	printf("请输入5个学生的信息:\n");
	for (int i = 0; i < 5; i++)
	{
		scanf("%d%s%d%d%d", &stu[i].num, stu[i].name, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
		stu[i].aver = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3.0;
	}
	FILE* fp;
	fp = fopen("stud.dat", "wb+");
	if (fp == NULL)
	{
		printf("cannot open file\n");
		return;
	}
	for(int i = 0;i < 5;i++)
	{
		if ( fwrite (&stu[i], sizeof(struct student), 1, fp)   != 1)
			printf("file write error\n");
	}
	rewind(fp);
	for(int i = 0;i < 5;i++)
	{
		fread(&temp, sizeof(struct student), 1, fp);
		printf("%-5d%-5s%4d%4d%4d%8.2f\n",
			temp.num, temp.name, temp.score[0], temp.score[1], temp.score[2], temp.aver);
	}
	fclose(fp);
	return 0;
}



