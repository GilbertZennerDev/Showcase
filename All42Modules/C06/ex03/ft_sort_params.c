#include <unistd.h>

void	ft_swap(char **a, char **b)
{
	char *temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	sort_args(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) > 0)
				ft_swap(&av[i], &av[j]);
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int i;
	char *str;

	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	sort_args(ac, av);
	i = 1;
	while (i < ac)
	{
		str = av[i];
		while (*str)
		{
			write(1, str, 1);
			str++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}