// task: define 2 functions add(a, b) and multiply(a, b) and run them from the main function using a function pointer ft_ptr
// rate for efficiency

#include <stdio.h>

int	add(int a, int b)
{
	return a + b;
}

int	multiply(int a, int b)
{
	return a * b;
}

int	main(void)
{
	int a = 5;
	int b = 10;

	int add_result;
	int multiply_result;

	//int (*ft_ptr[])(int, int) = {add, multiply};
	int (*ft_ptr)(int, int);
	ft_ptr = &add;
	//add_result = ft_ptr[0](a, b);
	add_result = ft_ptr(a, b);
	ft_ptr = &multiply;
	multiply_result = ft_ptr(a, b);
	//multiply_result = ft_ptr[1](a, b);

	printf("add: %d\n", add_result);
	printf("multiply: %d\n", multiply_result);

	return (0);
}
