#include<stdio.h>
int main()
{
	int a,b,c,d;
	double x2;
	printf("�����뷽�̵�ϵ����"); 
	scanf("%d%d%d%d",&a,&b,&c,&d);
	double newton(int a,int b,int c,int d);
	x2=newton(a,b,c,d);
	printf("�÷��̵ĸ�Ϊ%lf",x2);
	return 0;
}
   double newton(int a,int b,int c,int d)
   {
   	double f1,f2,x1;
	f1=a*x1*x1*x1+b*x1*x1+c*x1+d; 
	f2=3*a*x1*x1+2*b*x1+c;
	while(fabs(f1)>0.00001)
	{
		x1=x1-f1/f2;
		f1=a*x1*x1*x1+b*x1*x1+c*x1+d; 
	}
	return x1;
   }
