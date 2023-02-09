#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],b[100];
	void yuanyin(char s[]);
	printf("请输入一个字符串：");
	gets(a);
    yuanyin(a);
	return 0;
}
    void yuanyin(char a[])
    {
    int i,j;
    char b[100]={'\0'};
    j=0;
    for(i=0;a[i]!='\0';i++)
    {
	
	if(a[i]=='a'|| a[i]=='A'
	  || a[i]=='e'|| a[i]=='E'
	  || a[i]=='i'|| a[i]=='I'
	  || a[i]=='o'|| a[i]=='O'
	  || a[i]=='u'|| a[i]=='U')
	 {
	   b[j]=a[i];
	   j++;
    }
	else continue;
    }
	  b[j]='\0';
	  printf("该字符串中的元音字母为%s",b);
	}
