#define _CRT_SECURE_NO_WARNINGS 1 
#include "stu.h"

//初始化
void init(Data* d)
{
	d->data = (StuInfo*)malloc(sizeof(StuInfo) * 4);
	d->size = 0;
	d->capacity = 4;
}


//检查是否需要扩容
void is_full(Data* d)
{
	if (d->capacity == d->size)
	{
		StuInfo* tmp = (StuInfo*)realloc(d->data, sizeof(StuInfo) * (d->capacity + 4));
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		d->data = tmp;
		d->capacity += 4;
	}
}


//添加学生数据
void add(Data* d)
{
	is_full(d);
	char province[20];
	char city[20];
	printf("请输入待添加学生的姓名：");
	scanf("%s", d->data[d->size].name);
	printf("请输入待添加学生的性别：");
	scanf("%s", d->data[d->size].sex);
	printf("请输入待添加学生的学号：");
	scanf("%d", &d->data[d->size].num);
	printf("请输入待添加学生的成绩：");
	scanf("%d", &d->data[d->size].score);
	printf("请输入待添加学生的地址(请用空格分隔省和市)：");
	scanf("%s", province);
	scanf("%s", city);
	addr_to_code();
	printf("添加成功\n");

	d->size++;
}


//按照姓名查找学生
int find_by_name(char name[], Data d)
{
	for (int i = 0; i < d.size; i++)
		if (strcmp(name, d.data[i].name) == 0)
			return i;
	return -1;
}


//删除学生
void erase(Data* d)
{
	if (d->size == 0)
	{
		printf("没有学生，无需删除\n");
		return;
	}
	char name[20] = { 0 };
	printf("请输入要删除的学生的姓名：");
	scanf("%s", name);
	int pos = find_by_name(name, *d);
	if (pos != -1)
	{
		for (int j = pos; j < d->size; j++)
			d->data[j] = d->data[j + 1];
		d->size--;
		printf("删除成功\n");
		return;
	}
	else
		printf("学生%s不存在\n", name);
}


//查找学生，并打印出来该学生的信息
void search(Data d)
{
	char name[20] = { 0 };
	printf("请输入要查找的学生的姓名：");
	scanf("%s", name);
	int pos = find_by_name(name, d);
	if (pos != -1)
	{
		printf("%-10s\t%-4s\t%-9s\t%-4s\t%-20s\n", "姓名", "性别", "学号", "成绩", "地址");
		printf("%-10s\t%-4s\t%-9d\t%-4d\t%-20s\n",
			d.data[pos].name, d.data[pos].sex, d.data[pos].num, d.data[pos].score, d.data[pos].addr);
		return;
	}
	else
		printf("学生%s不存在\n", name);
}


//修改指定学生的信息
void modify(Data* d)
{
	char name[20] = { 0 };
	printf("请输入要查找的学生的姓名：");
	scanf("%s", name);
	int pos = find_by_name(name, *d);
	if (pos != -1)
	{
		printf("%s学生当前信息如下：\n", name);
		printf("%-10s\t%-4s\t%-9s\t%-4s\t%-20s\n", "姓名", "性别", "学号", "成绩", "地址");
		printf("%-10s\t%-4s\t%-9d\t%-4d\t%-20s\n",
			d->data[pos].name, d->data[pos].sex, d->data[pos].num, d->data[pos].score, d->data[pos].addr);
		printf("请输入修改后的姓名：");
		scanf("%s", d->data[pos].name);
		printf("请输入修改后的性别：");
		scanf("%s", d->data[pos].sex);
		printf("请输入修改后的学号：");
		scanf("%d", &d->data[pos].num);
		printf("请输入修改后的成绩：");
		scanf("%d", &d->data[pos].score);
		printf("请输入修改后的地址：");
		scanf("%s", d->data[pos].addr);
		printf("修改成功\n");
		return;
	}
	else
		printf("学生%s不存在\n", name);
}


//根据姓名进行排序
int cmp(const void* a, const void* b)
{
	return strcmp(((StuInfo*)a)->name, ((StuInfo*)b)->name);
}
void sort_by_name(Data* d)
{
	qsort(d->data, d->size, sizeof(StuInfo), cmp);
}


//打印所有学生信息
void print(Data d)
{
	printf("%-10s\t%-4s\t%-9s\t%-4s\t%-20s\n", "姓名", "性别", "学号", "成绩", "地址");
	for (int i = 0; i < d.size; i++)
	{
		code_to_addr;
		printf("%-10s\t%-4s\t%-9d\t%-4d\t%-20s\n",
			d.data[i].name, d.data[i].sex, d.data[i].num, d.data[i].score, d.data[i].addr);
	}
}


//从文件中读取数据
void read_data(Data* d)
{
	FILE* fp = fopen("data.dat", "rb");
	if (fp == NULL)
	{
		perror("fopen");
		return;
	}
	StuInfo tmp;
	while (fread(&tmp, sizeof(StuInfo), 1, fp))
	{
		is_full(d);
		d->data[d->size] = tmp;
		d->size++;
	}
	printf("数据读取完成\n");
}


//保存数据
void store_data(Data d)
{
	FILE* pf = fopen("data.dat", "wb");
	if (pf == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	for (int i = 0; i < d.size; i++)
		fwrite(&d.data[i], sizeof(StuInfo), 1, pf);
	printf("数据保存成功\n");
}


//释放空间
void free_data(Data* d)
{
	free(d->data);
	d->size = 0;
	d->capacity = 0;
}

void code_to_addr(char a[], Data* d)
{
	switch(a[0])
	{
	case 1:
		d->data[]
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
	case 11:
		break;
	case 12:
		break;
	case 13:
		break;
	case 14:
		break;
	case 15:
		break;
	case 16:
		break;
	case 17:
		break;
	case 18:
		break;
	case 19:
		break;
	case 20:
		break;
	case 21:
		break;
	case 22:
		break;
	case 23:
		break;
	case 24:
		break;
	case 25:
		break;
	case 26:
		break;
	case 27:
		break;
	case 28:
		break;
	case 29:
		break;
	case 30:
		break;
	case 31:
		break;
	case 32:
		break;
	case 33:
		break;
	case 34:
		break;
	default:
		printf("地址代码无效\n");
		break;
	}
}