#include<stdio.h>
int main()
{
	char *p[13]={"Non-existent month","January","February","March","April","May","June",
	"July","August","September","October","Novemver","December"};
	int n;
	printf("«Î ‰»Î‘¬∑›£®1-12£©£∫");
	scanf("%d",&n);
	printf("%s",*(p+n));
	return 0;
}
