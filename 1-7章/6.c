#include<stdio.h>
int main()
{
	float x,y;
	printf("������x��ֵ��");
	scanf("%f",&x);
	if(x<1)
	 y=x;
	if(1<=x && x<10)
	 y=2*x-1;
	if(x>=10)
	 y=3*x-11;
	printf("y��ֵΪ%f",y);
	return 0; 
}
