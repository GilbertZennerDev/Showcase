#include <stdlib.h>

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;
	char *dest;
	char *sc;

	dest = (char *)dst;
	sc = (char *)src;

	i = 0;
	while (n > 0 && i < n)
	{
		dest[i] = sc[i];
		i++;
	}
	return ((void *)dest);
}