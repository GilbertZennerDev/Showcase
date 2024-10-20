#include <unistd.h>

static void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void ft_putnbr_fd(int n, int fd)
{
    int div;
    unsigned char digit;

    div = 1;
    while (div <= n / 10)
        div *= 10;
    while (div > 0)
    {
        digit = (n / div) + '0';
        ft_putchar_fd(digit, fd);
        n %= div;
        div /= 10;
    }
}