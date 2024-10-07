#include <stdio.h>

void	swap_params(int *iptr, int *jptr)
{
	int tmp;
	tmp = *iptr;
	*iptr = *jptr;
	*jptr = tmp;
}

int	main(void)
{
	int i;
	int j;

	int *iptr = &i;
	int *jptr = &j;

	i = 1;
	j = 2;

	printf("i = %d; j = %d\n", *iptr, *jptr);
	swap_params( iptr, jptr);
	printf("i = %d; j = %d\n", *iptr, *jptr);

	return (0);
}
