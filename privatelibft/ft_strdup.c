#include <stdlib.h>

char *ft_strdup(char *src)
{
	char *dup;
	int len;
	int i;

	len = 0;
	while (src[len])
		len = len + 1;
	dup = malloc(len + 1);
	if (dup == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		dup[i] = src[i];
		i = i + 1;
	}
	dup[i] = '\0';
	return (dup);
}