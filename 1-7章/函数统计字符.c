#include<stdio.h>
#include<string.h>
int word=0,num=0,space=0,other=0;
	
int main()
{
	char a[100];
	void tongji(char s[]);
	
	printf("������һ���ַ�����");
	gets(a);
    tongji(a);
    printf("��ĸ����Ϊ%d\n",word);
	printf("���ָ���Ϊ%d\n",num);
	printf("�ո����Ϊ%d\n",space);
	printf("�����ַ�����Ϊ%d\n",other);
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
