#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int getMaximumConsecutive(int* coins, int coinsSize){
    qsort(coins, coinsSize, sizeof(int), cmp);
    int count = 1;
    while(1)
    {
        int flag = 0;
        int sum = 0;
        for(int i = 0; i < coinsSize; i++)
        {
            sum += coins[i];
            if(coins[i] == count || sum == count)
           {
               flag = 1;
               break;
           }
        }
        if(flag == 1)
            count++;
        else
            break;
    }
    return count;
}

int main()
{
    int coins[] = {1,1,1,4};
    printf("%d",getMaximumConsecutive(coins, 4));
    system("pause");
	return 0;
}


char* greatestLetter(char* s) {
    int up[30] = { 0 }, low[30] = { 0 };
    for (int i = 0; s[i]; i++)
    {
        if (s[i] >= 'a') low[s[i] - 'a']++;
        else up[s[i] - 'A']++;
    }
    char ret[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    for (int i = 25; i >= 0; i--)
    {
        if (low[i] && up[i])
            return (ret + i);
    }
    return NULL;
}