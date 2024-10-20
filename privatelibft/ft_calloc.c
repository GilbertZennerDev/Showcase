#include <stdlib.h>

void *ft_calloc(size_t num, size_t size)
{
    size_t total_size;
    unsigned char *arr;
    size_t i;

    total_size = num * size;
    arr = (unsigned char *)malloc(total_size);
    if (!arr)
        return (NULL);

    i = 0;
    while (i < total_size)
    {
        arr[i] = 0;
        i++;
    }
    return ((void *)arr);
}