#include <stdio.h>

void	ft_inc(int *ptr)
{
	*ptr += 1;
}

int	main(void)
{
	int	i;

	i = 5;
	printf("i : %d\n", i);
	ft_inc(&i);
	printf("i : %d\n", i);
}
