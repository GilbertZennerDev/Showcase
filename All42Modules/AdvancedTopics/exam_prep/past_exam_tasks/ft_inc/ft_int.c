// task: define a variable a in the main function and use void ft_inc(*ptr) to increase a by 1
// rate for efficiency
//
#include <unistd.h>

void	ft_inc(int *ptr)
{
	*ptr += 1;
}

int	main(void)
{
	int	a = 5;
	ft_inc(&a);
	return (0);
}
