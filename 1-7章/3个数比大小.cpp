#include<iostream>
#include<windows.h> 
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c;
	if (a>b)
	  d=a;   
	else  
	  d=b;
    if (d>c)
    cout<<"最大值是"<<d;
	else cout<<"最大值是"<<c;		           
	return 0;
}

