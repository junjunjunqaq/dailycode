#include<stdio.h>
#include<string.h>
int main()
{
	int compare(char *p1,char *p2,int len);
	int len;
	char s1[100],s2[100];
	char *p1=s1,*p2=s2;
	printf("请输入第一个字符串：");
	gets(s1);
	printf("请输入第二个字符串：");
	gets(s2);
	len=strlen(s1)>strlen(s2)?strlen(s1):strlen(s2);
	printf("%d",compare(p1,p2,len));
	return 0;
}
	int compare(char *p1,char *p2,int len)
	{
		int i,differ;
		for(i=0;i<len;i++)
		{
			if(*(p1+i)==*(p2+i)) continue;
			else 
			{
				differ=*(p1+i)-*(p2+i);
				break;
			}
		}
		return differ;
		
	}
