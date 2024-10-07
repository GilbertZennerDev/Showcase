#include <stdio.h>

int	find_max(int *arr, int size)
{
	int a, i;

	a = 0;
	i = 0;
	while(i < size)
	{
		if(i == 0)
			a = arr[i];
		else
		{
			if(arr[i] > a)
				a = arr[i];
		}
		i++;
	}
	return (a);
}

void	print_results(int *arr, int size)
{
	printf("max = %d\n", find_max(arr, size));
}

int	main(void)
{
	print_results((int[]){1,2,3,4,5}, 5); //this line is enough to have the desired array temporarily to work with
	return (0);
}
