#include<stdio.h>
#include<string.h>
int main()
{
	char s1[100],s2[100];
	int i; 
	printf("�������ַ���s2��");
	gets(s2);
    for(i=0;s2[i]!='\0';i++)
    {
    	s1[i]=s2[i];
	}
    s1[i]='\0';
	printf("�ַ���s1Ϊ%s",s1);
	return 0;
}
