int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    int i;

    i = 0;
    while (*s1 && *s2 && *s1==*s2 && i < n)
    {
        i++;
        s1++;
        s2++;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
}