#include <stdio.h>

// this program has two variables a and b defined in the main function.
// for a there is pointer a_ptr
// for b there is pointer b_ptr
// the task is to build a swapping function ft_swap which swaps only the addresses stored in the pointers
// so b_ptr will point to a and a_ptr will point to b
// secondly, have a function ft_inc which increases the variable pointed at by the pointer by 1

void	ft_swap(int **a_ptr, int **b_ptr)
{
	//exchanging the addresses
	int	*tmp = *a_ptr;
	*a_ptr = *b_ptr;
	*b_ptr = tmp;
}

void	ft_inc(int *ptr)
{
	*ptr += 1;
}

int	main(void)
{
	int	a;
	int	b;

	a = 5;
	b = 7;

	int	*a_ptr = &a;
	int	*b_ptr = &b;

	printf("a : %d\n", *a_ptr);
	printf("b : %d\n", *b_ptr);
	ft_swap(&a_ptr, &b_ptr);
	printf("a : %d\n", *b_ptr);
	printf("b : %d\n", *a_ptr);

	ft_inc(b_ptr);//a++
	ft_inc(a_ptr);//b++

	printf("a : %d\n", *b_ptr);
	printf("b : %d\n", *a_ptr);
}
