#include <stdio.h>
#include <stdlib.h>


int	main(void)
{
	int *ptr = (int *)malloc(5*sizeof(int));

	if(ptr == NULL)
	{
		printf("Memory allocation failed!\n");
		return 1;
	}

	for(int i=0; i<5; i++)
	{
		ptr[i] = i+1;
		printf("%d\n", ptr[i]);
	}

	free(ptr);
	return 0;
}
