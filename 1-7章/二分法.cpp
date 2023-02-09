#include <stdio.h>
#include <math.h>
int main()
{
  float x0,x1,x2,fx0,fx1,fx2;
  x1=-10;
  x2=10;
  do
  {
   fx1=((2*x1-4)*x1+3)*x1-6;
   fx2=((2*x2-4)*x2+3)*x2-6; 
  }while(fx1*fx2>0);

  do
  {
   x0=(x1+x2)/2;
   fx0=((2*x0-4)*x0+3)*x0-6;
   if((fx0*fx1)<0)
   {
   x2=x0;
   fx0=fx2;
   }
   else
   {
  x1=x0;
  fx1=fx0;}
  }while(fabs(fx0)>=1e-5);
  printf("x=%5.2lf",x0);
   return 0;
}
