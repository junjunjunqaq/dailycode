#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
typedef struct student {
	int num;
	char name[20];
	int sex;
	int age;
	struct student* next;
}stu;

stu* create()
{
	stu* newnode = (struct student*)malloc(sizeof(struct student));
	newnode->next = NULL;
	return newnode;
}

void print(stu* head)
{
	stu* cur = head;
	printf("学号  姓名	性别	年龄\n", cur->num, cur->name, cur->sex, cur->age);
	while (cur)
	{
		printf("%-6d%-10s%-8d%-6d\n", cur->num,cur->name,cur->sex,cur->age);
		cur = cur->next;
	}
	return;
}

stu* delete(stu* head, int age)
{
	stu* find = head;
	stu* pre = NULL;
	stu* dummy = malloc(sizeof (struct student));
	dummy->next = head;

	while (find)
	{
		if (find->age == age && find == head)
		{
			dummy->next = head->next;
			break;
		}
		else if (find->age == age)
		{
			pre->next = find->next;
			free(find);
			break;
		}
		else
		{
			pre = find;
			find = find->next;
		}
	}

	return dummy->next;
}

int main()
{
	stu* head = (struct student*)malloc(sizeof(struct student));
	stu* cur = head;
	printf("请输入第%d个学生的信息(学号，姓名，性别，年龄)(0=female,1=male)：", 1);
	scanf("%d%s%d%d", &cur->num, cur->name, &cur->sex, &cur->age);
	for (int i = 0; i < 2; i++)
	{
		cur->next = (struct student*)malloc(sizeof(struct student));
		cur = cur->next;
		printf("请输入第%d个学生的信息(学号，姓名，性别，年龄)(0=female,1=male)：", i + 2);
		scanf("%d%s%d%d", &cur->num, cur->name, &cur->sex, &cur->age);
	}
	cur->next= NULL;
	print(delete(head, 20));
	return 0;
}

