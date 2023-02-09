#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main() {
	char* p[5];
	printf("ÇëÊäÈë5¸ö×Ö·û´®£º");
	for(int i=0;i<5;i++)
	{
		scanf("%s", p[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		char * temp = p[0];
		for (int j = 0; j < 5; j++)
		{
			if (strcmp(temp, p[j]) > 0)
			{
				*temp = *j;

			}
		}
	}
	return 0;
}