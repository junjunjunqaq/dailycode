#include<stdio.h>
void bubble(char a[10]);
int main()
{
	char a[10];
	int i; 
	printf("������ʮ���ַ���\n");
	for(i=0;i<10;i++)
	{
		scanf("%c",&a[i]);
	}
	bubble(a);
	return 0;
}
void bubble(char a[10])
{
	int i,j;
	char t; 
	for(i=0;i<9;i++)
	{
		for(j=0;j<9-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j],a[j]=a[j+1],a[j+1]=t;
			}
		}
	}
	printf("��С��������Ϊ��\n");
	for(i=0;i<10;i++)
	{
	    printf("%c",a[i]);
    } 	
}

