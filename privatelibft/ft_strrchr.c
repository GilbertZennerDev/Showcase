#include <stdio.h>

char *ft_strrchr(const char *s, int c)
{
    char *addr = NULL;
    while (*s)
    {
        if (*s == (char)c)
            addr = (char *)(s);
        s++;
    }
    if (c == '\0')
        return ((char *)(s));
    return (addr);
}