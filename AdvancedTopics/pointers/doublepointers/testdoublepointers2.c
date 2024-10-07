#include <stdio.h>
#include <stdlib.h>

void change_value(int *ptr, int newvalue)
{
	*ptr = newvalue;
}

int	main(void)
{
	int i = 0;

	printf("Before change i = %d\n", i);

	change_value(&i, 1);

	printf("After change i = %d\n", i);

	return 0;
}
