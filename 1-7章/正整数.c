#include<stdio.h>
 int main()
 {
   int a,b,c,d,e,x;
   printf("������һ��������5λ����������"); 
   scanf("%d",&x);
   a=x/10000;
   b=x%10000/1000;
   c=x%1000/100;
   d=x%100/10;
   e=x%10;
   if (a!=0)
   printf("����һ����λ��%d%d%d%d%d\n�������Ϊ%d%d%d%d%d",a,b,c,d,e,e,d,c,b,a);	
   else if(b!=0) 
   printf("����һ����λ��%d%d%d%d\n�������Ϊ%d%d%d%d",b,c,d,e,e,d,c,b);
   else if(c!=0) 
   printf("����һ����λ��%d%d%d\n�������Ϊ%d%d%d",c,d,e,e,d,c);
   else if(d!=0) 
   printf("����һ����λ��%d%d\n�������Ϊ%d%d",d,e,e,d);
   else if(e!=0) 
   printf("����һ����λ��%d\n�������Ϊ%d",e,e);
   return 0;
 }
