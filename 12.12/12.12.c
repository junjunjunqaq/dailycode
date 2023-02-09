#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int compare(int* a, int* b)
{
	return *a - *b;
}
int main() 
{
	int a[] = { 10, 5, 12, 34, 54, 17, 3, 26 };
	qsort(a, sizeof a / sizeof(int), sizeof(int), compare);
	return 0;
}