#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define NUM 13
typedef struct people
{
	int num;
	struct people* next;
} people;

int main()
{
	int count = NUM;
	people p[NUM];
	people * head;
	head = p;
	for (int i = 0; i < NUM; i++)
	{
		head->num = i + 1;
		head->next = &p[i + 1];
		head = head->next;
	}
	p[NUM - 1].next = p;

	int i = 1;
	head = p;
	while (count > 1)
	{
		if (head->num == 0)
		{
			head = head->next;
			continue;
		}
		if (i == 3)
		{
			printf("�� %d λ�ñ���̭\n", head->num);
			head->num = 0;
			count--;
			i = 0;
		}
		head = head->next;
		i++;
	}
	while (head->num == 0)
	{
		head = head->next;
		if (head->num != 0)
		{
			printf("���������� %d�� \n", head->num);
		}
	}

	return 0;
}
