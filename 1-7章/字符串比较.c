#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],b[100];
	int i,c,d,m,n,max;
	c=0;
	m=n=0;
	printf("请输入第一个字符串：");
	gets(a);
	printf("\n请输入第二个字符串：");
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
	printf("比较结果为%d",c);

	return 0;
}
