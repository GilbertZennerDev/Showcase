#include <stdio.h>

void	ft_inc(int *iptr)
{
	*iptr = *iptr + 1;
}

int	main(void)
{
	int i = 0;

	printf("Before change i = %d\n", i);
	ft_inc(&i);
	printf("After change i = %d\n", i);
	
	return (0);
}
