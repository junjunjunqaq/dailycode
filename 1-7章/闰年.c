#include<stdio.h>
int main()
{ 
  int a=1900;
  int r,s,t;
  
  while (a<=2000)
  {
  	r=a%4; s=a%100; t=a%400;
   if (s==0 && t==0)
	{
	  printf("%d",a);
	  printf("������\n"); 
	} 
    else if (r==0 && s!=0)
    {
	  printf("%d",a);
	  printf("������\n");
	} 
	else 
	{
	  printf("%d",a); 
	  printf("��������\n");
	}

  a=a+1;
  }
  
  return 0;
}
