#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
struct stu{
	int num;
	struct stu* next;
};
void del(int val,struct stu **head)  //删除节点的条件
{
	struct stu * pre = *head;
	struct stu * cur = NULL;
	if (pre->num == val)  //头删
	{
		*head = pre->next;
		free(pre);
	}
	while (pre->num!= val)
	{
		cur = pre;
		pre = pre->next;
		
		cur->next = pre->next;
		free(pre);
				
			
	}
	
	}
	
}