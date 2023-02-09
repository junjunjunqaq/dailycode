#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool areSentencesSimilar(char* sentence1, char* sentence2) {
    if (strlen(sentence1) == strlen(sentence2))
    {
        if (strcmp(sentence1, sentence2) == 0)
            return true;
        else
            return false;
    }

    if (strlen(sentence1) < strlen(sentence2))
    {
        char* tmp = sentence1;
        sentence1 = sentence2;
        sentence2 = tmp;
    }

    int cnt = 0;
    int verb = 0;
    char word1[105] = { 0 };
    char word2[105] = { 0 };

    int i = 0, len1 = strlen(sentence1);
    int j = 0, len2 = strlen(sentence2);

    for (int k = 0; sentence2[k]; k++)
        if (sentence2[k] == ' ')
            verb++;
    verb++;

    while (i < len1 && j < len2)
    {
        memset(word1, 0, sizeof(word1));
        memset(word2, 0, sizeof(word2));

        int tmp = 0;
        while (sentence1[i] && sentence1[i] != ' ')
            word1[tmp++] = sentence1[i++];
        i++;

        tmp = 0;
        while (sentence2[j] && sentence2[j] != ' ')
            word2[tmp++] = sentence2[j++];
        j++;

        if (strcmp(word1, word2) == 0)
            cnt++;
        else
            break;
    }


    i = len1 - 1, j = len2 - 1;
    while (i >= 0 && j >= 0)
    {
        memset(word1, 0, sizeof(word1));
        memset(word2, 0, sizeof(word2));
        int tmp = 0;
        while (sentence1[i] != ' ' && i >= 0)
            word1[tmp++] = sentence1[i--];
        i--;

        tmp = 0;
        while (sentence2[j] != ' ' && j >= 0)
            word2[tmp++] = sentence2[j--];
        j--;

        if (strcmp(word1, word2) == 0)
            cnt++;
        else
            break;
    }

    if (cnt >= verb)
        return true;
    else
        return false;
}

int main()
{
	char s1[] = "My name is Haley";
	char s2[] = "My Haley";
//	bool areSentencesSimilar(char* sentence1, char* sentence2);
	printf("%d", areSentencesSimilar(s1,s2));
	return 0;
}

