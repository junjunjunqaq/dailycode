#define _CRT_SECURE_NO_WARNINGS 1
#include "stu.h"


void menu()
{
	printf("**************************\n");
	printf("*****    0.exit      *****\n");
	printf("*****    1.add       *****\n");
	printf("*****    2.delete    *****\n");
	printf("*****    3.search    *****\n");
	printf("*****    4.modify    *****\n");
	printf("*****    5.sort      *****\n");
	printf("*****    6.print     *****\n");
	printf("**************************\n");
}

int main()
{
	Data d;
	init(&d);
	read_data(&d);
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��Ҫ���еĲ�����");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			store_data(d);
			free_data(&d);
			printf("�˳��ɹ�\n");
			break;
		case 1:
			add(&d);
			break;
		case 2:
			erase(&d);
			break;
		case 3:
			search(d);
			break;
		case 4:
			modify(&d);
			break;
		case 5:
			sort_by_name(&d);
			break;
		case 6:
			print(d);
			break;
		default:
			printf("��Чѡ��������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}