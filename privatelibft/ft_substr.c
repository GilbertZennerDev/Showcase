#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start,
                size_t len)
{
    char *sub;
    size_t i;

    sub = malloc((len + 1) * sizeof(char));
    if (!sub)
        return (NULL);
    i = 0;
    while (i < len && s[i + start])
    {
        sub[i] = s[i + start];
        i++;
    }
    sub[i] = '\0';
    return (sub);
}