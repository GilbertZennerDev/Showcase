#include <stdio.h>

char *ft_remove_chars(char *string)
{
	char	*base;
	char	c;
	int	i;
	int	j;
	int	k;

	base = string;
	while(*base)
	{
		i = 0;
		c = *base;
		while(base[i] != '\0')
		{
			i++;
			if(base[i] == c)
			{
				j = i;
				while(base[j] != '\0')
				{
					base[j] = base[j+1];
					j++;
				}
			}
		}
		base++;
	}
}

int	main(void)
{
	char	text[] = "aabbcc";
	printf("Resultat = %s\n", ft_remove_chars(text));
	return (0);
}
