#include<stdio.h>
int main()
{
   char c1,c2;
   c1=getchar();
   c2=getchar();
   printf("%d,%d",c1,c2);
   return 0;
}
//不可以，char和int的范围不同，只有在公共范围内才可以互相替代 
//如果整数超出了字符的存储范围，则不能相互替换 
