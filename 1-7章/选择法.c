#include<stdio.h>
int main()
{
	int m,n,k,i,a[10];
	printf("������10��������"); 
	for(i=0;i<=9;i++)
	{
		scanf("%d",&a[i]);
	}


	for(m=0;m<=8;m++)
	  for(n=m+1;n<=9;n++) 
	{
		if(a[m]>a[n])
		{
			k=a[m];
			a[m]=a[n];
			a[n]=k;
		}
    }
      printf("����������Ϊ��");
		for(i=0;i<=9;i++)
	   {
		printf("%d ",a[i]);
	    }
	return 0;
}
