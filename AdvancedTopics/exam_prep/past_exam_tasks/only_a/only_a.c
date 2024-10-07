// a trivial program which prints 'a' to the standard output using the function write
//

#include <unistd.h>

void	ft_only_a(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	ft_only_a('a');
	return (0);
}
