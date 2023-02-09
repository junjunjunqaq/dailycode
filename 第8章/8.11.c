#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char *p[10];
	int i;
	for(i=0;i<10;i++)
	{
	printf("请输入第%d个等长字符串：",i+1);
	p[i]=(char*)malloc(sizeof(char)*50);
	gets(p[i]);
	printf("%s",p[i]);
    }
	void sort(char *p[10]);
	sort(p);
/*	if(strlen(p[0])==strlen(p[1])==strlen(p[2])==strlen(p[3])==
	strlen(p[4])==strlen(p[5])==strlen(p[6])==strlen(p[7])==strlen(p[8])
	==strlen(p[9]))
		{
			sort(p);
		}
	else printf("输入的字符串不等长！");  */
	printf("排序后的字符串为：");
	for(i=0;i<10;i++)
		printf("%s\n",p[i]);
	return 0;
}

	void sort(char *p[10])
	{
		char temp;
		int i,j;
		for(i=0;i<10;i++)
		{
			for(j=0;j<10-i;j++)
			{
				if(strcmp(p[j],p[j+1])>0)
				{
					temp=*p[j];
					*p[j]=*p[j+1];
					*p[j+1]=temp;
				}
			}
		}
	}  
