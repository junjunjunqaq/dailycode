#include<stdio.h>
#include<math.h>

int main()
{
	float fun(float (*p)(float));
	int n;
	printf("请选择要求积分的函数（n=1,2,3）:");
	scanf("%d",&n);
	float fsinx(float x);
	float fcosx(float x);
	float fex(float x);
	float result;
	float (*p)(float x);
	if(n==1) p=fsinx;
	if(n==2) p=fcosx;
	if(n==3) p=fex;
	result=fun(p);
	printf("%f",result);
	return 0;
}

	float fun(float (*p)(float))
	{
		float x=0;
		float n=100000;
		float s=0;
		int i;
		for(i=0;i<100000;i++)
		{
		x=x+1/n;
		s=s+(*p)(x)/100000;	
		}
		return s;
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

