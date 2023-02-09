#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
struct stu {
	int num;
	struct stu* next;
};

void insert(int num,int val, struct stu** head)  //向指定节点前插入新节点
{
	struct stu* pre= *head;
	struct stu* cur = NULL;
	struct stu* newNode = (struct stu*)malloc(sizeof(struct stu));
	newNode->num = num;
	if (pre->num == val)  //头插
	{
		newNode->next = pre;
		*head = newNode;
	}
	while (pre->num != val) {
		cur = pre;
		pre = pre->next;
		if (pre->num == val)
		{
			cur->next = newNode;
			newNode->next = pre;
			break;
		}
	}
}
