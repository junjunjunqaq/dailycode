#include<stdio.h>
#include<math.h>
int main()
{ 
  	
  	double f1,f2,x1;
	f1=2*x1*x1*x1-4*x1*x1+3*x1-6; 
	f2=6*x1*x1-8*x1+3;
	while(fabs(f1)>0.00001)
	{
		x1=x1-f1/f2;
		f1=2*x1*x1*x1-4*x1*x1+3*x1-6; 
	}
	printf("该方程的根为%lf",x1);
  return 0;
}
