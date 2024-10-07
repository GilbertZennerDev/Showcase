#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_char(char *text, int index)
{
    while (text[index] != '\0')
    {
        text[index] = text[index + 1];
        index++;
    }
}

void remove_duplicates(int count, char c, char *text, int index)
{
    for (int i = 0; i < count; i++)
    {
        remove_char(text, index + 1);
    }
}

int count_duplicates(char c, char *text, int index)
{
    int count = 0;
    while (text[index] == c)
    {
        count++;
        index++;
    }
    return count - 1;  // Subtract 1 to exclude the original character
}

void insert_count(char *text, int index, int count)
{
    char count_str[20];
    sprintf(count_str, "%d", count);
    int len = strlen(count_str);
    
    memmove(text + index + len, text + index, strlen(text + index) + 1);
    memcpy(text + index, count_str, len);
}

int main(void)
{
    char text[] = "aaabbbccc";
    int index = 0;

    while (text[index] != '\0')
    {
        char currentchar = text[index];
        int duplicates = count_duplicates(currentchar, text, index);
        if (duplicates > 0)
        {
            remove_duplicates(duplicates, currentchar, text, index);
            insert_count(text, index + 1, duplicates + 1);
            index += 2;  // Move past the character and the count
        }
        else
        {
            index++;
        }
    }

    printf("Compressed string: %s\n", text);
    return 0;
}