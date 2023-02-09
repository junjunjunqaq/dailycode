//#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	double fsinx(double x);
	double fcosx(double x);
	double fex(double x);
	double(*p)(double x) = NULL;
	double fun(double(*p)(double x), double a , double b);
	printf("请选择要计算积分的函数（1.sinx，2.cosx，3.e^x）：");
	scanf("%d",&n);
	if(n==1) p=fsinx;
	if(n==2) p=fcosx;
	if(n==3) p=fex;
	double a, b;
	printf("请输入函数的下限（a）和上限（b）：");
	scanf("%lf%lf", &a,&b);
	printf("%lf", fun(p,a,b));
	return 0;
}

	double fun(double (*p)(double x), double a, double b)
	{
		double s=0;
		double flag=1;
		double n=100000;
		int i;
		if (a ==b)
		{
			return 0;
		}

		else if(a>b)
		{
			double temp=0;
			temp = a;
			a = b;
			b = temp;
			flag = -1;
		}
		double x = a;
	for(i = 0; i < n; i++)
	{
		x = x + (b - a) / n;
		s = s + (*p)(x) * (1 / n);
	}
	return flag * s;
	}
	
    double fsinx(double x)
    {
    	return sin(x);
	}
	double fcosx(double x)
	{
    	return cos(x);
	}
	double fex(double x)
	{
    	return exp(x);
	}
	
	
	
