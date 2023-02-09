#include <stdio.h>
#define MAX 1000
int main()
{
	int htoi(char s[]);
	int c, i, flag, flag1;
	char t[MAX];
	i = 0;
	flag = 0;
	flag1 = 1;
	printf("请输入一个十六进制数:");
	while ((c = getchar()) != '\0' && i < MAX && flag1)
	{
		if (c >= '0' && c <= '9' || c >= 'a' && c <= 'f' || c >= 'A' && c <= 'F')
		{
			flag = 1;
			t[i++] = c;
		}
		else if (flag)
		{
			t[i] = '\0';
			printf("对应的十进制数为 %d\n", htoi(t));
	        break; 
		}
	}
	return 0;
}


int htoi(char s[])
{
	int i, n;
	n = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			n = n * 16 + s[i] - '0';
		if (s[i] >= 'a' && s[i] <= 'f')
			n = n * 16 + s[i] - 'a' + 10;
	}
	return (n);
}

