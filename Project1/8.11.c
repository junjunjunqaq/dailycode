#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char  * p[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("�������%d���ȳ��ַ�����", i + 1);
		p[i] = (char*)malloc(sizeof(char) * 50);
		scanf("%s", p[i]);
	}
	void sort(char* p[10]);
	sort(p);
		/*if(strlen(p[0])==strlen(p[1])==strlen(p[2])==strlen(p[3])==
		strlen(p[4])==strlen(p[5])==strlen(p[6])==strlen(p[7])==strlen(p[8])
		==strlen(p[9]))
			{
				sort(p);
			}
		else {
			printf("������ַ������ȳ���");*/
			/*return 0;
		}*/
	
	printf("�������ַ���Ϊ��\n");
	for (i = 0; i < 10; i++)
	{
		printf("%s\n", p[i]);
		free(p[i]);
	}
	
	return 0;
}

void sort(char* p[10])
{
	
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 9 - i; j++)
		{
			if (strcmp(p[j], p[j + 1]) > 0)
			{
				char *temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}
