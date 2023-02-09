#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* create(int val)
{
	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newnode->val = val;
	newnode->next = NULL;
	return newnode;
}

void print(struct ListNode* head)
{
	struct ListNode* cur = head;
	while (cur->next)
	{
		printf("%d->", cur->val);
		cur = cur->next;
		if (cur->next == NULL)
		{
			printf("%d", cur->val);
			return;
		}
	}
}

void insert(struct ListNode* pos, int val)  //指定位置后插入
{
	struct ListNode *newnode = create(val);
	newnode->next = pos->next->next;
	pos->next = newnode;
}

struct ListNode* delete(struct ListNode** head, struct ListNode* pos)
{
	if (pos == *head)  //头删
	{
		struct ListNode* temp = (*head)->next;
		free(*head);
		*head = temp;
		return *head;
	}
	struct ListNode* find = *head;
	while (find->next != pos)
		find = find->next;
	find->next = pos->next;
	free(pos);
	return *head;
}

int main()
{
	struct ListNode* head = NULL;
	head= create(0);
	struct ListNode* cur = head;
	for (int i = 1; i < 10; i++)
	{
		cur->next = create(i);
		cur = cur->next;
	}
	print(head);
	printf("\n");
	head = delete(&head, head);
	print(head);
	insert(head->next, 10);
	printf("\n");
	print(head);
	return 0;
}