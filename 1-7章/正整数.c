#include<stdio.h>
 int main()
 {
   int a,b,c,d,e,x;
   printf("请输入一个不多于5位的正整数："); 
   scanf("%d",&x);
   a=x/10000;
   b=x%10000/1000;
   c=x%1000/100;
   d=x%100/10;
   e=x%10;
   if (a!=0)
   printf("这是一个五位数%d%d%d%d%d\n逆序输出为%d%d%d%d%d",a,b,c,d,e,e,d,c,b,a);	
   else if(b!=0) 
   printf("这是一个四位数%d%d%d%d\n逆序输出为%d%d%d%d",b,c,d,e,e,d,c,b);
   else if(c!=0) 
   printf("这是一个三位数%d%d%d\n逆序输出为%d%d%d",c,d,e,e,d,c);
   else if(d!=0) 
   printf("这是一个两位数%d%d\n逆序输出为%d%d",d,e,e,d);
   else if(e!=0) 
   printf("这是一个个位数%d\n逆序输出为%d",e,e);
   return 0;
 }
