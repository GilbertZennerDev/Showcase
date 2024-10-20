#include <stdlib.h>

char *ft_itoa(int n)
{
    int i;
    char *s;
    char digit;
    int div;

    i = 0;
    s = malloc(sizeof(char *));
    if (!s)
        return (NULL);
    div = 1;
    while (div <= n / 10)
        div *= 10;
    if (n < 0)
    {
        s[i] = '-';
        n *= -1;
        i++;
    }
    while (div > 0)
    {
        digit = (n / div) + '0';
        s[i] = digit;
        n %= div;
        div /= 10;
        i++;
    }
    return (s);
}