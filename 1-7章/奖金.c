#include<stdio.h>
int main()
{
  float I,p;
  printf("请输入利润额：");	
  scanf("%f",&I);
  if(I<=100000.0)
  {
  	p=0.1*I;
	printf("奖金总数为%f",p);	
  }
  else if(I>100000.0 && I<=200000.0)
  {
  	p=0.075*(I-100000)+10000;
	printf("奖金总数为%f",p);	
  }
  else if(I>200000.0 && I<=400000.0)
  {
  	p=0.05*(I-200000)+17500;
	printf("奖金总数为%f",p);	
  }
  else if(I>400000.0 && I<=600000.0)
  {
  	p=0.03*(I-400000)+17500+10000;
	printf("奖金总数为%f",p);	
  }
  else if(I>600000.0 && I<=1000000.0)
  {
  	p=100000*0.1+200000*0.05+100000*0.075+200000*0.03+(I-600000)*0.015;
	printf("奖金总数为%f",p);	
  }
  else if(I>1000000.0)
  {
  	p=100000*0.1+200000*0.05+100000*0.075+200000*0.03+400000*0.015+(I-1000000)*0.01;
	printf("奖金总数为%f",p);	
  }
	return 0;
}
