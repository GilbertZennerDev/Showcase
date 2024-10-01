#include <stdio.h>

int	main(void)
{
	int i;
	int *iptr = &i;

	*iptr = 1;
	printf("%d, %p\n", i, (void *)iptr);

	return (0);
}
