#include <stdio.h>

int	main(void)
{
	int arr[] = {0,1,2,3,4};
	int *arrptr = arr;
	for(int i=0; i < 5; i++)
	{
		printf("%d ", arrptr[i]);
	}
	printf("\n");

	return (0);
}
