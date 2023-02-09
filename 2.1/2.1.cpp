#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

char* decodeMessage(char* key, char* message) {
    char letter[26] = { 0 };
    int count = 0;
    for (int i = 0; key[i]; i++)
    {
        if (key[i] == ' ')
            count++;
        else if (letter[key[i] - 'a'] == 0)
            letter[key[i] - 'a'] = 'a' + i - count;

    }
  //  printf("%d\n", count);
    /*for (int i = 0; i < 26; i++)
        printf("%c ", 'a' + i);
    printf("\n");
    for(int i = 0; i < 26; i++)
        printf("%c ", letter[i]);*/
    printf("%c", letter['o' - 'a']);
    for (int i = 0; message[i]; i++)
        if (message[i] != ' ')
            message[i] = letter[message[i] - 'a'];

    return message;
}

int main()
{
	char key[] = "the quick brown fox jumps over the lazy dog";
	char message[] = "vkbs bs t suepuv";
    char* final = decodeMessage(key, message);
    printf("%s",message);
	return 0;
}