#include <stdlib.h>

static int ft_strlen(const char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

static int ft_isinset(char const *set, char c)
{
    int i;
    i = 0;
    while (set[i])
    {
        if (set[i] == c)
            return (1);
        i++;
    }
    return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
    char *trimmedStr;
    int start;
    int end;
    int i;

    if (!s1 || !set)
        return (NULL);

    start = 0;
    while (s1[start] && ft_isinset(set, s1[start]))
        start++;

    end = ft_strlen(s1);
    while (end > start && ft_isinset(set, s1[end - 1]))
        end--;

    trimmedStr = malloc(sizeof(char) * (end - start + 1));
    if (!trimmedStr)
        return (NULL);

    i = 0;
    while (start < end)
        trimmedStr[i++] = s1[start++];
    trimmedStr[i] = '\0';

    return (trimmedStr);
}