#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],b[100];
	int i; 
	printf("���������룺");
	gets(a);
	strcpy(b,a);
    for(i=0;b[i]!='\0';i++)
    {
    	if((a[i]>='a')&& (a[i]<='z'))
    	
    	b[i]=26+96-a[i]+1+96;
    	
    	else if((b[i]>='A')&&(b[i]<='Z'))

        b[i]=26+64-a[i]+1+64;
        
        else b[i]=b[i];
	}

	printf("����Ϊ%s\n",a);
	printf("ԭ��Ϊ%s",b);
	return 0;
}
