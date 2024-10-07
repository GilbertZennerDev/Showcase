#include <stdio.h>

void	take_double_pointer(int **dbptr)
{
	**dbptr = 0;
}

int	main(void)
{
	int i = 1;
	int *ptr = &i;

	printf("i before change: %d\n",i);
	take_double_pointer(&ptr);
	printf("i after change: %d\n",i);

	return (0);
}
