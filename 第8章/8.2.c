//2. ���������ַ���������С�����˳�����
#include<stdio.h>
#include<string.h>
int main()
{
	char s1[200],s2[200],s3[200];
	char temp[200];
	char *temp1;
	printf("�������һ���ַ�����");
	gets(s1);
	printf("������ڶ����ַ�����");
	gets(s2);
	printf("������������ַ�����");
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
	printf("�����ַ�����С���������Ϊ��%s %s %s",a,b,c);
	return 0;
}
