#include<stdio.h>
#include<string.h>
int word=0,num=0,space=0,other=0;
	
int main()
{
	char a[100];
	void tongji(char s[]);
	
	printf("请输入一个字符串：");
	gets(a);
    tongji(a);
    printf("字母个数为%d\n",word);
	printf("数字个数为%d\n",num);
	printf("空格个数为%d\n",space);
	printf("其他字符个数为%d\n",other);
	return 0;
}
    void tongji(char a[])
   {
	 int i=0;
     
    while (a[i]!='\0')
    {
	 if((a[i]>='0')&& (a[i]<='9'))
		num=num+1;
		else if((a[i]>='a')&& (a[i]<='z') || (a[i]>='A')&& (a[i]<='Z'))
		word=word+1;
		else if((a[i]==' '))
		space=space+1;
		else other=other+1;
		i++; 
	}
}
