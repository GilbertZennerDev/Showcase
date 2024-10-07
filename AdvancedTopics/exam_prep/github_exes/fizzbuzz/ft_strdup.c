char    *ft_strdup(char *src)
{
    int i;
    int len;
    char *dup;

    len = 0;
    while(src[len])
        len++;

    dup = malloc(1*(len + 1));
    if(!dup)
        return (0);
    i = 0;
    while(i < len)
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}