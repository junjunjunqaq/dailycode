#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],b[100];
	int i,c,d,m,n,max;
	c=0;
	m=n=0;
	printf("�������һ���ַ�����");
	gets(a);
	printf("\n������ڶ����ַ�����");
	gets(b);
	for(i=0;a[i]!='\0';i++)
	 m=m+1;
	for(i=0;b[i]!='\0';i++)
	 n=n+1;
	if(m>n)
	 max=m;
	else max=n;
	for(i=0;i<=max-1;i++)
	{
		if(a[i]==b[i]) continue;
		if(a[i]!=b[i])
		 c=a[i]-b[i];
		 break;
      
	}
	printf("�ȽϽ��Ϊ%d",c);

	return 0;
}
