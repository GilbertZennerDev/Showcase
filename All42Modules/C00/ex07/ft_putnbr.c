#include <unistd.h>

void    ft_putnbr(int nb)
{
    int div;
    unsigned char digit;
    
    div = 1;
    if(nb > nb + 1)
    {
        write(1, "0", 1);
        return ;
    }
    if(nb < 0)
    {
        nb *= -1;
        write(1, "-", 1);
    }
    while(div < nb / 10)
        div *= 10;
    while(div > 0)
    {
        digit = (nb / div) + '0';
        write(1, &digit, 1);
        nb %= div;
        div /= 10;
    }
}