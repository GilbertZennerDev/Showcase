char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    int i;
    int j;
    unsigned int k;

    i = 0;
    j = 0;
    k = 0;
    while (dest[i])
        i++;
    while(src[j] && k < nb)
    {
        dest[i] = src[j];
        i++;
        j++;
        k++;
    }
    dest[i] = '\0';
    return (dest);
}