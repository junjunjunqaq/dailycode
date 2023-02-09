#include<stdio.h>
int main()
{
  float I,j;
  printf("请输入利润额：");	
  scanf("%f",&I);
  int branch=I/100000;
  if (branch>10) branch=10;
  switch(branch)
  {
  	case 0:j=I*0.1;break;
  	case 1:j=100000*0.1+(I-100000)*0.075;break;
  	case 2:
  	case 3:j=100000*0.1+(I-200000)*0.05+100000*0.075;break;
  	case 4:
  	case 5:j=100000*0.1+200000*0.05+100000*0.075+(I-400000)*0.03;break;
  	case 6:
  	case 7:
  	case 8:
  	case 9:j=100000*0.1+200000*0.05+100000*0.075+200000*0.03+(I-600000)*0.015;break;
  	case 10:j=100000*0.1+200000*0.05+100000*0.075+200000*0.03+400000*0.015+(I-1000000)*0.01;break;
  }
   printf("奖金总数为%f",j);
	return 0;
}
