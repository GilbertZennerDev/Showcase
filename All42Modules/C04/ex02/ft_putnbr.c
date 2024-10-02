#include <unistd.h>

void	ft_putnbr(int nb)
{
	unsigned int	n;
	char		digit;
	unsigned int	div;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return;
	}
    if(nb < 0)
    {
        write(1, "-", 1);
            nb = -nb;
    }
	n = nb;
	div = 1;
	while (div <= n / 10)
		div *= 10;
	while (div > 0)
	{
		digit = (n / div) + '0';
		write(1, &digit, 1);
		n %= div;
		div /= 10;
	}
}