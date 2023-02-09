#include<stdio.h>
int main()
{
   float r,h,c,s,s1,v1,v2;
   const float pi=3.1415926;
   printf("请输入半径和高：");
   scanf("%f%f",&r,&h);
   c=2*pi*r;
   s=pi*r*r;
   s1=4*pi*r*r;
   v1=4.0/3.0*pi*r*r*r;
   v2=s*h;
   printf("圆周长为%2.2f\n",c);
   printf("圆面积为%2.2f\n",s);
   printf("圆球表面积为%2.2f\n",s1);
   printf("圆球体积为%2.2f\n",v1);
   printf("圆柱体积为%2.2f\n",v2);
   return 0;
}

