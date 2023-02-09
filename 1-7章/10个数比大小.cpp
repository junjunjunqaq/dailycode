#include<iostream>
#include<windows.h> 
using namespace std;
int main()
{ 
  int a,b,c,d,e,f,g,h,m,n,x,y,z,p,q;
  cout<<"请输入第1个数：";
  cin>>a;
  cout<<"请输入第2个数：";
  cin>>b;
  cout<<"请输入第3个数：";
  cin>>c;
  cout<<"请输入第4个数：";
  cin>>d;
  cout<<"请输入第5个数：";
  cin>>e;
  cout<<"请输入第6个数：";
  cin>>f;
  cout<<"请输入第7个数：";
  cin>>g;
  cout<<"请输入第8个数：";
  cin>>h;
  cout<<"请输入第9个数：";
  cin>>m;
  cout<<"请输入第10个数：";
  cin>>n;
  
  if (a>b)
	  x=a;   
	else  
	  x=b;
    if (c>x) 
      x=c;
    else x=x;
    
    if (d>e)
	  y=d;   
	else  
	  y=e;
    if (f>y) 
      y=f;
    else y=y;
    
     if (g>h)
	  z=g;   
	else  
	  z=h;
    if (m>z) 
      z=m;
    else z=z;
    
    if (n>x)
    p=n;
    else p=x;
    
    if(y>z)
    q=y;
    else q=z;
    
    if(p>q)
    cout<<"最大值是"<<p;
    else cout<<"最大值是"<<q;
    
  return 0;
}
