#include<stdio.h>
int main()
{
	char a[300];
	int num,b,A,c,space;
	num=b=A=c=space=0;
	int i,m;
	m=0;
	printf("������һƪ���£�") ;
	gets(a);
	for(i=0;a[i]!='\0';i++)
	 m=m+1;
	for(i=0;i<=m-1;i++)
	{
		if((a[i]>='0')&& (a[i]<='9'))
		num=num+1;
		else if((a[i]>='a')&& (a[i]<='z'))
		b=b+1;
		else if((a[i]>='A')&& (a[i]<='Z'))
		A=A+1;
		else if((a[i]==' '))
		space=space+1;
		else c=c+1;
	}
	printf("��д��ĸ����Ϊ%d\n",A);
	printf("Сд��ĸ����Ϊ%d\n",b);
	printf("���ָ���Ϊ%d\n",num);
	printf("�ո����Ϊ%d\n",space);
	printf("�����ַ�����Ϊ%d\n",c);
	return 0;
}
