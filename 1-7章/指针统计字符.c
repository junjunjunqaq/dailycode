#include<stdio.h>
int main()
{
	char a[300];
	int num,b,A,c,space;
	char *p=a;
	char t;
	num=b=A=c=space=0;
	int i,m;
	m=0;
	printf("������һ�����֣�") ;
	gets(a);
	for(i=0;a[i]!='\0';i++)
	 m=m+1;
	for(p=a;p<a+m;p++)
	{
		t=*p;
		if((t>='0')&& (t<='9'))
		num=num+1;
		else if((t>='a')&& (t<='z'))
		b=b+1;
		else if((t>='A')&& (t<='Z'))
		A=A+1;
		else if((t==' '))
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
