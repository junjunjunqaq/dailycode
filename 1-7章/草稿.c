#include<stdio.h>
#include<math.h>
int main()
{	
	float fun(float (*p)(float x));
	float fsinx(float x);
	float fcosx(float x);
	float fex(float x);
	float (*p)(float x);
	int n;
	printf("请选择要计算积分的函数（1.sinx，2.cosx，3.e^x）：");
	scanf("%d",&n);
	if(n==1) p=fsinx;
	if(n==2) p=fcosx;
	if(n==3) p=fex;
	printf("%f",fun(p));
	return 0;
}

	float fsinx(float x)
	{ 
		return sin(x);
	}
	
	float fcosx(float x)
	{ 
		return cos(x);
	}
	
	float fex(float x)
	{ 
		return exp(x);
	}
	
	float fun(float (*p)(float x))
	{
		int n=100000;
		int i;
		float s=0,x=0;
		for(i=0;i<n;i++)
		{
			x=x+1.0/n;
			s=s+p(x)*1/n;
		}
		return s;
	}
