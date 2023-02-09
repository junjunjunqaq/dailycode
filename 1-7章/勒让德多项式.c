#include<stdio.h>

    int main()
{
    int x, n;
    double p(int n,int x); 
	printf("请输入n和x的值：");
	scanf("%d%d",&n,&x);
	printf("n=%d x=%d\n",n,x);
	printf("P%d(%d)=%lf\n",n,x, p(n,x));
return 0;
}

    double p(int n,int x) 
	{
	if (n == 0) return 1;
	else if (n == 1) return x;
	else return((2 *n - 1) * x - p((n - 1), x) - (n - 1) * p((n - 2), x)) / n;
}

