#include <stdlib.h>

static int ft_strlen(const char *s)
{
    int len;

    len = 0;
    while (s[len])
        len++;
    return (len);
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *modifieds;
    int i;
    int len;

    if (!s || !f)
        return (NULL);

    len = ft_strlen(s);
    modifieds = malloc((len + 1) * sizeof(char));
    if (!modifieds)
        return (NULL);

    i = 0;
    while (s[i])
    {
        modifieds[i] = f(i, s[i]);
        i++;
    }
    modifieds[i] = '\0';
    return (modifieds);
}