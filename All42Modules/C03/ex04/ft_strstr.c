char *strstr(char *str, char *to_find)
{
    char *a, *b;

    if (*to_find == '\0')
        return str;

    while (*str)
    {
        a = str;
        b = to_find;

        while (*a && *b && *a == *b)
        {
            a++;
            b++;
        }

        if (*b == '\0')
            return str;

        str++;
    }

    return 0;
}