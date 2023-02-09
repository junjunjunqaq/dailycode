//2. 输入三个字符串，按由小到大的顺序输出
#include<stdio.h>
#include<string.h>
int main()
{
	char s1[200],s2[200],s3[200];
	char temp[200];
	char *temp1;
	printf("请输入第一个字符串：");
	gets(s1);
	printf("请输入第二个字符串：");
	gets(s2);
	printf("请输入第三个字符串：");
	gets(s3);
	char *a,*b,*c;
	a=s1;b=s2;c=s3; 
	if(strcmp(s1,s2)>0)
	{
		temp1=a;
		a=b;
		b=temp1;	
	}
	if(strcmp(s1,s3)>0)
	{
		temp1=a;
		a=c;
		c=temp1;	
	}
	if(strcmp(s2,s3)>0)
	{
		temp1=b;
		b=c;
		c=temp1;	
	}
	printf("三个字符串从小到大排序后为：%s %s %s",a,b,c);
	return 0;
}
