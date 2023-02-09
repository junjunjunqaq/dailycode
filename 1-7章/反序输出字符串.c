#include<stdio.h>
#include<string.h>
int main()
{
	void exchange(char arr[]);
	char arr[100];
	printf("ÇëÊäÈëÒ»¸ö×Ö·û´®£º");
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
		 printf("·´Ğò×Ö·û´®Îª%s",arr);
	 } 
