#include <stdio.h>

void	ft_swap_values(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_inc(int *a)
{
	*a += 1;
}

int	ft_length_arr(int *arr)
{
	int length;

	length = 0;
	while(*arr)
	{
		length++;
	}
	return length;
}

int *ft_inv_arr(int *arr)
{
	int *start = arr;
	int *end = arr;
	int tmp;

	while(*end)
	{
		end++;
	}
	end--;

	while(start < end)
	{
		tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
	return (arr);
}

int	main(void)
{
	int	a;
	int b;

	a = 5;
	b = 10;

	int	arr[] = {1,2,3};
	ft_inv_arr(arr);
	return (0);
}
