#include<stdio.h>
int main() 
  {
   int s;
   printf("请输入一百分制成绩:");
   scanf("%d",&s);
   if (s>=90)
   {
    printf("成绩等级为A\n");
   }
   else if ((80<=s) && (s<90))
   {
   	printf("成绩等级为B\n");
   }
   
   else if ((70<=s) && (s<80))
   {
   printf("成绩等级为C\n");
   }
   else if ((60<=s) && (s<70))
   {
   printf("成绩等级为D\n");
   }
   else if (s<60)
   {
   printf("成绩等级为E\n");
   }
   return 0; 
   
}
