#include<iostream>
#include<windows.h> 
using namespace std;
int main()
{ 
  int a,b,c,d,e,f,g,h,m,n,x,y,z,p,q;
  cout<<"�������1������";
  cin>>a;
  cout<<"�������2������";
  cin>>b;
  cout<<"�������3������";
  cin>>c;
  cout<<"�������4������";
  cin>>d;
  cout<<"�������5������";
  cin>>e;
  cout<<"�������6������";
  cin>>f;
  cout<<"�������7������";
  cin>>g;
  cout<<"�������8������";
  cin>>h;
  cout<<"�������9������";
  cin>>m;
  cout<<"�������10������";
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
    cout<<"���ֵ��"<<p;
    else cout<<"���ֵ��"<<q;
    
  return 0;
}
