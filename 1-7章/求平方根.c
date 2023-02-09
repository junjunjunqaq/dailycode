#include<stdio.h>
#include<math.h>
int main()
{
	double x1,x2,a;
	printf("请输入a的值：");
	scanf("%lf",&a);
	x1=a/2;
	x2=0;
	while( fabs(x1-x2)>0.00001 )
	{
		x2=x1;
		x1=(x2+a/x2)/2;
	}
	printf("a的平方根为%8.5f",x2);
	
	return 0;
}
