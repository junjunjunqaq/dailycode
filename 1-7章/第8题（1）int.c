#include<stdio.h>
int main()
{
   int c1,c2;
   printf("�����������ַ�c1,c2:");
   c1=getchar();
   c2=getchar();
   printf("��printf���������Ϊ:");
   printf("%c%c\n",c1,c2);
   printf("��putchar���������Ϊ:");
   putchar(c1);
   putchar(c2);
   return 0;
}
//c1��c2���Զ���Ϊ�ַ��ͻ�����,���߽Կ� 
