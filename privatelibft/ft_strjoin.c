#include <stdlib.h>

char *ft_strjoin(char const *s1, char const *s2)
{
    int len1 = 0;
    int len2 = 0;
    int totalLength;
    char *joinedStr;
    int i;
    int j;

    while (s1[len1])
    {
        len1++;
    }
    while (s2[len2])
    {
        len2++;
    }
    totalLength = len1 + len2;
    joinedStr = malloc((totalLength + 1) * sizeof(char));
    if (!joinedStr)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        joinedStr[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
        joinedStr[i + j] = s2[j];
        j++;
    }
    joinedStr[i + j] = '\0';
    return (joinedStr);
}