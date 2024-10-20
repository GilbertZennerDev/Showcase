#include <stdio.h>
#include <stdlib.h>

char **ft_split(char const *s, char c)
{
    size_t i;
    size_t len_s1;
    size_t len_s2;
    char **subs;

    i = 0;
    len_s1 = 0;
    len_s2 = 0;
    while (s[i] != c)
    {
        len_s1++;
        i++;
    }
    while (s[i])
    {
        len_s2++;
        i++;
    }

    subs = malloc(3 * sizeof(char *));
    if (!subs)
        return (NULL);
    subs[0] = malloc((len_s1 + 1) * sizeof(char));
    subs[1] = malloc((len_s2 + 1) * sizeof(char));
    if (!subs[0] || !subs[1])
        return (NULL);
    i = 0;
    while (i < len_s1)
    {
        subs[0][i] = s[i];
        i++;
    }
    subs[0][i] = '\0';
    i = 0;
    while (i < len_s2)
    {
        subs[1][i] = s[i + len_s1 + 1];
        i++;
    }
    subs[1][i] = '\0';
    subs[2] = NULL;
    return (subs);
}