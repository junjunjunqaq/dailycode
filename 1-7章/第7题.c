#include<stdio.h>
int main()
{
   float r,h,c,s,s1,v1,v2;
   const float pi=3.1415926;
   printf("������뾶�͸ߣ�");
   scanf("%f%f",&r,&h);
   c=2*pi*r;
   s=pi*r*r;
   s1=4*pi*r*r;
   v1=4.0/3.0*pi*r*r*r;
   v2=s*h;
   printf("Բ�ܳ�Ϊ%2.2f\n",c);
   printf("Բ���Ϊ%2.2f\n",s);
   printf("Բ������Ϊ%2.2f\n",s1);
   printf("Բ�����Ϊ%2.2f\n",v1);
   printf("Բ�����Ϊ%2.2f\n",v2);
   return 0;
}

