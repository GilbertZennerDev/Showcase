#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CHAR_REPEAT 5
#define STRING_LENGTH 50

void generate_random_string(char *str, size_t length)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyz";
    size_t charset_size = sizeof(charset) - 1;

    srand((unsigned int)time(NULL));

    size_t i = 0;
    while (i < length - 1)
    {
        char random_char = charset[rand() % charset_size];
        int repeat_count = rand() % MAX_CHAR_REPEAT + 1;

        for (int j = 0; j < repeat_count && i < length - 1; j++)
        {
            str[i++] = random_char;
        }
    }
    str[length - 1] = '\0'; // Null-terminate the string
}

char *shorten_string(const char *str)
{
    size_t length = 2 * STRING_LENGTH; // Allocate enough memory for the result
    char *shortstr = malloc(length);
    if (!shortstr)
    {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    int j = 0;
    while (str[i])
    {
        shortstr[j] = str[i];
        int k = 0;
        while (str[i] == str[i + k])
            k++;
        shortstr[j + 1] = k + '0'; // Convert count to character
        i += k;
        j += 2;
    }
    shortstr[j] = '\0'; // Null-terminate the result

    return shortstr;
}

int main(void)
{
    char str[STRING_LENGTH];
    generate_random_string(str, STRING_LENGTH);
    printf("Generated string: %s\n", str);

    char *shortstr = shorten_string(str);
    printf("Compressed string: %s\n", shortstr);

    free(shortstr); // Free allocated memory
    return 0;
}