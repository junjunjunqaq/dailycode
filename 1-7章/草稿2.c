#include<stdio.h> 
int main()
{
	int i,n,people[100];
	int *p=people,count=1;
	printf("������n��ֵ:");
	scanf("%d",&n);
	int left=n;

	for(i=0;i<n;i++)
		people[i]=i+1;
	while(left>1)
	{	p=people;
	   for(;p<p+n;p++)
	   {
	   	if(*p!=0)
		count++;
		if(count==3)
		{
			*p=0;
			count=1;
			left--; 
		}
	   }
	}
printf("%d",people[4]);
	for(i=0;i<n;i++)
	{
	//if(people[i]!=0)
		printf("�������������%d��",people[i]);	
	}	
		
	return 0;
}
