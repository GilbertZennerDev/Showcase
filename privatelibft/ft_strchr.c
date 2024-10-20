#include <stdio.h>

char *ft_strchr(const char *haystack, int needle)
{
    while (*haystack)
    {
        if (*haystack == (char)needle)
            return ((char *)(haystack));
        haystack++;
    }
    if (needle == '\0')
        return ((char *)(haystack));
    return (NULL);
}