#include<stdio.h>
int main() 
  {
   int s;
   printf("������һ�ٷ��Ƴɼ�:");
   scanf("%d",&s);
   if (s>=90)
   {
    printf("�ɼ��ȼ�ΪA\n");
   }
   else if ((80<=s) && (s<90))
   {
   	printf("�ɼ��ȼ�ΪB\n");
   }
   
   else if ((70<=s) && (s<80))
   {
   printf("�ɼ��ȼ�ΪC\n");
   }
   else if ((60<=s) && (s<70))
   {
   printf("�ɼ��ȼ�ΪD\n");
   }
   else if (s<60)
   {
   printf("�ɼ��ȼ�ΪE\n");
   }
   return 0; 
   
}
