#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee {
	char name[20];
	int num;
	int sex;
	int age;
	char address[20];
	int salary;
	char health[15];
	char education[20];
}em[3],employee[3];

void write()
{
	FILE* fp = fopen("employee.dat", "w");
	if (fp == NULL)
	{
		printf("cannot open file\n");
		return;
	}
	printf("请输入3个职工的信息：\n");
	for (int i = 0; i < 3; i++)
	{
		scanf("%s%d%d%d%d%s%s%s",
			em[i].name, &em[i].num, &em[i].sex, &em[i].age, &em[i].salary,em[i].address, em[i].health, em[i].education);
	}
	for (int i = 0; i < 3; i++)
	{
		/*printf("%-5s%3d%3d%-5d%-10s%-15s%-15s\n",
			em[i].name, em[i].num, em[i].sex, em[i].age, em[i].address, em[i].health, em[i].education);*/
		fwrite(&em[i], sizeof(struct employee), 1, fp);
	}
	fclose(fp);
}

struct NewData {
	char name[20];
	int salary;
}new[3];

int main()
	{
	write(); //创建employee文件
	FILE* fp = fopen("employee.dat", "rb");
	if (fp == NULL)
	{
		printf("cannot open file\n");
		return;
	}
	for (int i = 0; i < 3; i++) 
		fread(&employee[i], sizeof(struct employee), 1, fp); //读出employee数据
	printf("职工工资文件的数据为：\n");
	for (int i = 0; i < 3; i++)
	{
		/*printf("%-5s%3d%3d%-5d%-10s%-15s%-15s\n",
			employee[i].name, employee[i].num, employee[i].sex, employee[i].age, employee[i].address, employee[i].health, employee[i].education);*/
		strcpy(new[i].name, employee[i].name);
		new[i].salary = employee[i].salary;
	}
	fclose(fp);
	FILE* newfp = fopen("salary.dat", "w");
	struct NewData temp;
	for (int i = 0; i < 3; i++)
	{
		temp = new[i];
		printf("%-5s%4d\n", temp.name, temp.salary);
		fwrite(&new[i], sizeof(struct NewData), 1, newfp); //写入工资文件
	}
	fclose(newfp);
	return 0;
	}
