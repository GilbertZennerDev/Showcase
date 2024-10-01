// rate for efficiency. and how could I use write without the alt_c, i.e. adding 32 directly?
// task: write a function ft_rev_alpha that outputs the alphabet in reverse using write with every second letter uppercase starting from a. the rest lowercase

#include <unistd.h>

void	ft_rev_alpha()
{
	char c = 'Z';//we start from Z
	while(c >= 'A')
	{
		char toWrite = (c % 2 == 0 ? c + 32 : c);
		write(1, &toWrite, 1);
		c--;
	}
}

int	main(void)
{
	ft_rev_alpha();
	return (0);
}
