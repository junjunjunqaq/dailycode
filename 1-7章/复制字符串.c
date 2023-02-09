#include<stdio.h>
#include<string.h>
int main()
{
	char s1[100],s2[100];
	int i; 
	printf("ÇëÊäÈë×Ö·û´®s2£º");
	gets(s2);
    for(i=0;s2[i]!='\0';i++)
    {
    	s1[i]=s2[i];
	}
    s1[i]='\0';
	printf("×Ö·û´®s1Îª%s",s1);
	return 0;
}
