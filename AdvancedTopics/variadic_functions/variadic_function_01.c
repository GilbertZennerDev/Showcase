#include <stdarg.h>
#include <stdio.h>

int	sum(int count, ...)
{
	va_list args;
	va_start(args, count);
	int total = 0;
	for(int i=0; i < count; i++)
	{
		total += va_arg(args, int);
	}
	va_end(args);
	return total;
}

int	product(int count, ...)
{
	va_list args;
	va_start(args, count);
	int total = 1;
	for(int i=0; i < count; i++)
	{
		total *= va_arg(args, int);
	}
	va_end(args);
	return total;
}

int	main(void)
{
	int a = 2;
	int b = 3;
	int c = 5;

	int result;
	int (*operation[])(int a, ...) = {sum, product};
	char* operationNames[] = {"Additon", "Multiplication" };

	for(int i = 0; i < 2; i++)
	{
		result = operation[i](3, a, b, c);
		printf("result of %s of %d, %d and %d = %d\n", operationNames[i], a , b, c, result);
	}
	
	return 0;
}
