#include<stdio.h>
#include<stdio.h>
int main()
{   
    char name[10][10];
    int num[10];
	void input(char name[10][10],int num[]);
	input(name,num);
	void bubble(char name[10][10],int num[]);
	bubble(name,num);
	void search(int n, int num[], char name[10][10]); 
	int number;
	printf("请输入需要查找的职工号：");
	scanf("%d",&number); 
	search(number,num,name);
	return 0;
}
   void input(char name[10][10],int num[])
   {
   	int i=0;
   	for(i=0;i<10;i++)
   	{
   	printf("No.");
   	scanf("%d",&num[i]);
   	printf("姓名:");
	getchar(); 
   	gets(name[i]);
	}
	
   }
   
   void bubble(char name[10][10],int num[])
   {
   	int i, j, min, temp1;
	char temp2[8];
	for (i = 0; i < 10 - 1; i++)
	{
		min = i;
		for (j = i; j < 10; j++)
			if (num[min] > num[j])
				min = j;
		temp1 = num[i];
		strcpy(temp2, name[i]);
		num[i] = num[min];
		strcpy(name[i], name[min]);

		num[min] = temp1;
		strcpy(name[min], temp2);
	}	
		
	printf("排序后:\n");
	for(i=0;i<10;i++)
	  printf("No.%d  %s\n",num[i],name[i]);
   }

void search(int n, int num[], char name[10][10]) 
{

	int top, bott, mid, loca, sign;
	top = 0;
	bott = 10 - 1;
	loca = 0;
	sign = 1;
	if ((n < num[0]) || (n > num[10 - 1]))
		loca = -1;
	while ((sign == 1) && (top <= bott))
	{
		mid = (bott + top) / 2;
		if (n == num[mid])
		{
			loca = mid;
			printf("NO.%d的姓名是 %s.\n", n, name[loca]);
			sign = -1;
		}
		else if (n < num[mid])
			bott = mid - 1;
		else
			top = mid + 1;
	}
	if (sign == 1 || loca == -1)
		printf("%d not been found.\n", n);
}

