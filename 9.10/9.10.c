#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student {
	int num;
	char name[20];
	struct student* next;
}stu;

void print(stu* head)
{
    stu* cur = head;
    while (cur)
    {
        printf("%-6d%-10s\n", cur->num, cur->name);
        cur = cur->next;
    }
    return;
}

stu* create()
{
    stu* newnode = (struct student*)malloc(sizeof(struct student));
    newnode->next = NULL;
    return newnode;
}

stu* combine(stu* head_a, stu* head_b)
{
    stu* newhead;
    if (head_a->num < head_b->num)
    {
        newhead = head_a;
        head_a = head_a->next;
    }
    else
    {
        newhead = head_b;
        head_b = head_b->next;
    }
    stu* cur = newhead;
    while(head_a && head_b)
    {
        if (head_a->num < head_b->num)
        {
            cur->next = head_a;
            head_a = head_a->next;
            cur = cur->next;
        }
        else if (head_b->num < head_a->num)
        {
            cur->next = head_b;
            head_b = head_b->next;
            cur = cur->next;
        }
    }
    if (!head_a)
        cur->next = head_b;
    else
        cur->next = head_a;
    return newhead;
}

int main()
{
    stu* head_a = (struct student*)malloc(sizeof(struct student));
    stu* cur_a = head_a;
    printf("（这是链表a）\n");
    for (int i = 0; i < 3; i++)
    {
        printf("请输入第%d个学生的信息：", i + 1);
        scanf("%d%s",&cur_a->num, cur_a->name);
        if (i == 2)
            break;
        cur_a->next = create();
        cur_a = cur_a->next;
    }

    stu* head_b = (struct student*)malloc(sizeof(struct student));
    stu* cur_b = head_b;
    printf("（这是链表b）\n");
    for (int i = 0; i < 3; i++)
    {
        printf("请输入第%d个学生的信息：", i + 1);
        scanf("%d%s", &cur_b->num, cur_b->name);
        if (i == 2)
            break;
        cur_b->next = create();
        cur_b = cur_b->next;
    }
    print(combine(head_a, head_b));
    return 0;
}