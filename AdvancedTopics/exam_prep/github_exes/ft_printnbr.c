#include <unistd.h>

void ft_putnbr(int nb)
{
    char digit;
    int divisor;

    if(nb < 0)
    {
        nb *= -1;
        write(1, "-", 1);
    }

    divisor = 1;

    while( nb / divisor >= 10)
    {
        divisor *= 10;
    }

    while(divisor > 0)
    {
        digit = (nb / divisor) + '0';
        write(1, &digit, 1);
        nb %= divisor;
        divisor /= 10;
    }
}

int main(void)
{
    int test1 = -123456464;
    ft_putnbr(test1);
    return (0);
}