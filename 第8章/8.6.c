#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	char *p=a;
	int num=0;
	printf("请输入一个字符串：");
	gets(a);
	int count(char a[],char *p);
	num=count(a,*p);
	printf("字符串长度为%d",num);
	
	return 0;
}
	int count(char a[],char *p)
	{
		int num;
		for(p=a;*p!='\0';p++)
			num++;
		return num;
	}
	
