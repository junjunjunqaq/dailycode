#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,x,f;
	a=-10; b=10;
	x=(a+b)/2;
	f=2*x*x*x-4*x*x+3*x-6; 
	for(x=(a+b)/2;fabs(f)>1e-5;)
	{
	
	 if(f<0)
	  {
		a=x;
		x=(a+b)/2;
     	}
	 else 
	 { b=x;
	   x=(a+b)/2;}
	f=2*x*x*x-4*x*x+3*x-6; 
    }
	printf("该方程在（-10,10）的根为%f",x);
	return 0;
}
