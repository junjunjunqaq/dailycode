#include<stdio.h>
#include<string.h>
int main()
{
	void exchange(char arr[]);
	char arr[100];
	printf("������һ���ַ�����");
	scanf("%s",arr);
	exchange(arr);
	
	return 0;
}

    void exchange(char arr[])
	{
		int index=0,begin=0,end=0;
		char temp;
		while(arr[index++]!='\0');
		 for(end=index-2;begin<=end;begin++,end--)
		 {
		 	temp=arr[begin];
		 	arr[begin]=arr[end];
		 	arr[end]=temp;
		 }
		 printf("�����ַ���Ϊ%s",arr);
	 } 
