#include<stdio.h>
#include<string.h>

int main(){
int i,len;
	char arr [256][256];
	printf("请输入单词的个数:\n");
	scanf("%d", &len);
	for (i = 0;i < len; i++)
		scanf("%s", arr [i]);
	word(arr,len);
return 0;
}

    void word(char p[][256], int n) {
	int i, * arr_max;
	arr_max = p;
	for (i = 0; i < n; i++)
		if (strlen(arr_max) < strlen(p [i])) arr_max = p [i];
	puts(arr_max);
}
