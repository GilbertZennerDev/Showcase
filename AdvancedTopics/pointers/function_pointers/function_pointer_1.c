#include <stdio.h>

int	add( int a, int b)
{
	return a + b;
}

int	subtract( int a, int b)
{
	return a - b;
}

int	multiply( int a, int b)
{
	return a * b;
}

int	divide( int a, int b)
{
	if(b == 0)
		return 1;
	return a / b;
}

int	main(void)
{
	int (*operation[])(int, int) = {add, subtract, multiply, divide};
	int result;

	char* operationNames[] = {"Addition", "Subtract", "Multiply", "Divide"};

	for(int i=0; i < 4; i++)
	{
		result = operation[i](10, 2);
		printf("Operation = %s\n", operationNames[i]);
		printf("result = %d\n", result);
	}
	
	return 0;
}
