#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	nl()
{
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int	i;
	char	c;

	if (argc != 2)
	{
		nl();
		return (0);
	}
	i = 0;
	while (argv[1][i] == 32 || argv[1][i] == 9)
	{
		i++;
	}
	while (argv[1][i] != 0 && argv[1][i] != 32 && argv[1][i] != 9)
	{
		c = argv[1][i];
		ft_putchar(c);
		i++;
	}
	nl();
	return (0);
}