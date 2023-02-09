#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool areSentencesSimilar(char* sentence1, char* sentence2) {
    int i = 0, len1 = strlen(sentence1);
    int j = 0, len2 = strlen(sentence2);

    if (len1 == len2)
    {
        if (strcmp(sentence1, sentence2) == 0)
            return true;
        else
            return false;
    }

    int cnt = 0;
    int verb = 0;
    char word1[105] = { 0 };
    char word2[105] = { 0 };

    while (len1 > len2 && i < len1 && j < len2)
    {
        while (sentence1[i] != ' ' && sentence1[i])
        {
            word1[i] = sentence1[i];
            i++;
        }

        while (sentence2[j] != ' ' && sentence2[j])
        {
            word2[j] = sentence2[j];
            j++;
        }

        verb++;

        if (strcmp(word1, word2) != 0 && i < len1)
        {
            memset(word1, 0, sizeof(word1));
            while (sentence1[i] != ' ' && sentence1[i])
            {
                word1[i] = sentence1[i];
                i++;
            }
        }

        else if (strcmp(word1, word2) == 0 && i <= len1 && j <= len2)
        {
            cnt++;
            memset(word1, 0, sizeof(word1));
            memset(word2, 0, sizeof(word2));
            while (sentence1[i] != ' ' && sentence1[i])
            {
                word1[i] = sentence1[i];
                i++;
            }

            while (sentence2[j] != ' ' && sentence2[j])
            {
                word2[j] = sentence2[j];
                j++;
            }
            verb++;
        }

    }


    while (len1 < len2 && i < len1 && j < len2)
    {

        while (sentence1[i] != ' ' && sentence1[i])
        {
            word1[i] = sentence1[i];
            i++;
        }

        verb++;

        while (sentence2[j] != ' ' && sentence2[j])
        {
            word2[j] = sentence2[j];
            j++;
        }


        if (strcmp(word1, word2) != 0 && j < len2)
        {
            memset(word2, 0, sizeof(word2));
            while (sentence2[j] != ' ' && sentence2[j])
            {
                word2[j] = sentence2[j];
                j++;
            }
        }

        else if (strcmp(word1, word2) == 0 && i < len1 && j < len2)
        {
            cnt++;
            memset(word1, 0, sizeof(word1));
            memset(word2, 0, sizeof(word2));
            while (sentence1[i] != ' ' && sentence1[i])
            {
                word1[i] = sentence1[i];
                i++;
            }
            verb++;

            while (sentence2[j] != ' ' && sentence2[j])
            {
                word2[j] = sentence2[j];
                j++;
            }
        }
    }

    if (len1 < len2 && cnt == verb)
        return true;
    else if (len1 > len2 && cnt == verb)
        return true;
    else
        return false;
}
int main()
{
    char a[] = "hjv L hvp rh d XG rXXPnZ hLLRNw BGdAHx UeSOg Twn b eo yQNdmhI";
    char b[] = "hjv rXXPnZ hLLRNw BGdAHx UeSOg Twn b eo yQNdmhI";
    printf("%d", areSentencesSimilar(a, b));
	return 0;
}