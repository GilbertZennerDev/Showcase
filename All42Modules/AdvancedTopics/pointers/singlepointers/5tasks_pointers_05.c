#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int *iptr;
	iptr = (int *)malloc(sizeof(int));

	if (iptr == NULL)
	{
    		fprintf(stderr, "Memory allocation failed\n");
    		return 1;
	}

	*iptr = 100;
	printf("%d\n", *iptr);
	
	free(iptr);
	iptr = NULL;

	return (0);
}
