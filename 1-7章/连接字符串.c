#include<stdio.h>
#include<string.h>
int main()
{
	char a[200],b[100];
	int i,m,n,c;
	m=0;c=0;
	printf("�������һ���ַ�����");
	gets(a);
	printf("\n������ڶ����ַ�����");
	gets(b);
	for(i=0;a[i]!='\0';i++)
	 m=m+1;
	for(i=0;b[i]!='\0';i++)
	 n=n+1;
	for(i=m;i<=m+n-1;i++)
	{
	
	    if(c<=n-1) 
	    {
	
	    a[i]=b[c];
	    c=c+1;
         }

    }
    a[i]='\0';
    printf("ƴ�Ӻ���ַ���Ϊ%s",a);
	return 0;
}
