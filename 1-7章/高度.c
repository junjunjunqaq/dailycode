#include<stdio.h>
int main()
{
	float x,y;
	float a,b,c,d;
	int h; 
	printf("��ֱ�����x,y��ֵ��"); 
	scanf("%f%f",&x,&y);
	a=(x-2)*(x-2)+(y-2)*(y-2);
	b=(x-2)*(x-2)+(y+2)*(y+2);
	c=(x+2)*(x+2)+(y-2)*(y-2);
	d=(x+2)*(x+2)+(y+2)*(y+2);
	printf("x=%f y=%f\n",x,y);
	if(a<=1 || b<=1 || c<=1 || d<=1)
	{
	  h=10;
	}
	
	else h=0;
	printf("�õ�Ľ����߶�Ϊ%d��\n",h);
	return 0; 
}
