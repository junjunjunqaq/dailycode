#include<stdio.h>
int main()
{

int a,b,c;
scanf("%d",&a);

for (b=2;b<a;b=b+1)
 {

	if(a%b==0)
    c=b;
  }
 printf("%d",c);
return 0;
} 
