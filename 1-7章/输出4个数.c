#include<stdio.h>
int main()
{
	int a,b,c,d,x,y,max,min,s1,s2;
	printf("请输入a,b,c,d的值："); 
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a>b)
	{
	x=a;
	s1=b;
	     }
	else 
	{
	x=b;
	s1=a;
	     } 
	if(c>d)
	{
	 y=c;
	 s2=d;
	      }
	else
	{
	 y=d;
	 s2=c;
	      } 
	if(x>y)
	{
	 if(s1>y)
	 {printf("4个整数由小到大为：%d %d %d %d",s2,y,s1,x);
	 }
	 if(s1<s2)
	 {printf("4个整数由小到大为：%d %d %d %d",s1,s2,y,x);
	 }
	 if(s1>s2 && s1<y)
	 {printf("4个整数由小到大为：%d %d %d %d",s2,s1,y,x);
	 }
	}
	if(y>x)
	{
	 if(s2>x)
	 {printf("4个整数由小到大为：%d %d %d %d",s1,x,s2,y);
	 }
	 if(s1>s2)
	 {printf("4个整数由小到大为：%d %d %d %d",s2,s1,x,y);
	 }
	 if(s1<s2 && s2<x)
	 {printf("4个整数由小到大为：%d %d %d %d",s1,s2,x,y);
	 }
	}
	return 0; 
}
