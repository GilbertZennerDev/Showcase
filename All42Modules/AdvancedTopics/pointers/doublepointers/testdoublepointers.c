#include <stdio.h>
#include <stdlib.h>

void change_value(int **ptr)
{
	**ptr = 1;
}

int	main(void)
{
	int i = 0;
	int *iptr = &i;

	printf("Before change i = %d\n", i);

	change_value(&iptr);

	printf("After change i = %d\n", i);

	return 0;
}
