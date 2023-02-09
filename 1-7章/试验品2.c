#include<stdio.h>
void main()
{
  void bubble(int *arr);
  printf("请输入十个数：");
  int i,j,arr[10];
  for(i=0;i<9;i++)
   scanf("%d",arr[i]);
  bubble(arr);
  printf("排序后的数为：");
  for(j=9;j>0;j--)
   printf("%d ",arr[j]); 

}
  void bubble(int *arr)
  {
  	int i,j,m;
  	for(i=0;i<9;i++)
  	 for(j=0;j<9-i;j++)
  	{
	
  	 if(arr[j]>arr[j+1])
  	 {
  	 	m=arr[j];
  	 	arr[j]=arr[j+1];
  	 	arr[j+1]=m;
	   }
    }
  }
